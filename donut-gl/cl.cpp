#include "types.hpp"
#include <cstdio>

#define IS_NULL__NO_CL(data) \
    if (data == NULL)        \
        return;

#define DIE_ON_FAIL(err)   \
    if (err != CL_SUCCESS) \
        exit(1);

void DonutBuffer::init_cl(const char *const cl_prog_name)
{
    IS_NULL__NO_CL(cl_prog_name);

    cl_platform_id p = ocl_select_platform();
    IS_NULL__NO_CL(p);

    cl_device_id d = ocl_select_device(p);
    IS_NULL__NO_CL(p);

    cl_context ctx = ocl_create_context(p, d);
    IS_NULL__NO_CL(p);

    que = ocl_create_queue(ctx, d);
    IS_NULL__NO_CL(p);

    cl_program prog = ocl_create_program(cl_prog_name, ctx, d);
    IS_NULL__NO_CL(p);

    cl_int err;

    donut_k = clCreateKernel(prog, "donut", &err);
    ocl_cl_check(err, "create kernel donut");
    if (err != CL_SUCCESS)
        return;

    size_t preferred_wg_init;

    err = clGetKernelWorkGroupInfo(donut_k, d,
        CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE, sizeof(preferred_wg_init),
        &preferred_wg_init, NULL);

    const int memsize = length * 4;
    donut_mem = clCreateBuffer(ctx, CL_MEM_WRITE_ONLY, memsize, NULL, &err);
    ocl_cl_check(err, "create buffer data");
    if (err != CL_SUCCESS)
        return;

    use_cl = true;
}

void DonutBuffer::cl_render(float A, float B)
{
    cl_int err;
    const int memsize = length * 4;

    int n_theta = 100;
    int n_phi = 3.14f * 100;

    err = clSetKernelArg(donut_k, 0, sizeof(void *), &donut_mem);
    ocl_cl_check(err, "set sum arg 0");
    DIE_ON_FAIL(err);

    err = clSetKernelArg(donut_k, 1, sizeof(float), &A);
    ocl_cl_check(err, "set sum arg 1");
    DIE_ON_FAIL(err);

    err = clSetKernelArg(donut_k, 2, sizeof(float), &B);
    ocl_cl_check(err, "set sum arg 2");
    DIE_ON_FAIL(err);

    err = clSetKernelArg(donut_k, 3, sizeof(int), &n_phi);
    ocl_cl_check(err, "set sum arg 3");
    DIE_ON_FAIL(err);

    cl_event copy_evt, donut_event;

    size_t lws[] = { 1 };

    size_t gws[] = { round_mul_up(n_theta, lws[0]) };

    err = clEnqueueNDRangeKernel(que, donut_k, 1, NULL, gws,
        (lws[0] ? lws : NULL), 0, NULL, &donut_event);
    ocl_cl_check(err, "enqueue kernel donut");
    DIE_ON_FAIL(err);

    err = clEnqueueReadBuffer(
        que, donut_mem, CL_TRUE, 0, memsize, ptr, 1, &donut_event, &copy_evt);
    ocl_cl_check(err, "read buffer donut");
    DIE_ON_FAIL(err);
}
