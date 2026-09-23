/* A tweaked version of https://github.com/xmey95/opencl_boilerplate
    ocl_boiler.h
  */

#define CL_TARGET_OPENCL_VERSION 300
#include <CL/cl_platform.h>
/* Include the headers defining the OpenCL host API */
#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFSIZE 4096

// NOLINTBEGIN(misc-definitions-in-headers)

/* Check an OpenCL error status, printing a message and exiting
 * in case of failure
 */
void ocl_cl_check(cl_int err, const char *msg, ...)
{
    if (err != CL_SUCCESS) {
        char msg_buf[BUFSIZE + 1];
        va_list ap;
        va_start(ap, msg);
        vsnprintf(msg_buf, BUFSIZE, msg, ap);
        va_end(ap);
        msg_buf[BUFSIZE] = '\0';
        fprintf(stderr, "%s - error %d\n", msg_buf, err);
    }
}

// Return the ID of the platform specified in the OCL_PLATFORM
// environment variable (or the first one if none specified)
cl_platform_id ocl_select_platform()
{
    cl_uint nplats;
    cl_int err;
    cl_platform_id *plats;
    const char *const env = getenv("OCL_PLATFORM");
    cl_uint nump = 0;
    if (env && env[0] != '\0')
        nump = atoi(env);

    err = clGetPlatformIDs(0, NULL, &nplats);
    ocl_cl_check(err, "counting platforms");
    if (err)
        return NULL;

    plats = (cl_platform_id *)malloc(nplats * sizeof(*plats));

    err = clGetPlatformIDs(nplats, plats, NULL);
    ocl_cl_check(err, "getting platform IDs");
    if (err)
        return NULL;

    if (nump >= nplats) {
        fprintf(stderr, "no platform number %u", nump);
        return NULL;
    }

    cl_platform_id choice = plats[nump];

    char buffer[BUFSIZE];

    err = clGetPlatformInfo(choice, CL_PLATFORM_NAME, BUFSIZE, buffer, NULL);
    ocl_cl_check(err, "getting platform name");
    if (err)
        return NULL;

    printf("selected platform %d: %s\n", nump, buffer);

    return choice;
}

// Return the ID of the device (of the given platform p) specified in the
// OCL_DEVICE environment variable (or the first one if none specified)
cl_device_id ocl_select_device(cl_platform_id p)
{
    cl_uint ndevs;
    cl_int err;
    cl_device_id *devs;
    const char *const env = getenv("OCL_DEVICE");
    cl_uint numd = 0;
    if (env && env[0] != '\0')
        numd = atoi(env);

    err = clGetDeviceIDs(p, CL_DEVICE_TYPE_ALL, 0, NULL, &ndevs);
    ocl_cl_check(err, "counting devices");
    if (err)
        return NULL;

    printf("number of devices: %u\n", ndevs);

    devs = (cl_device_id *)malloc(ndevs * sizeof(*devs));

    err = clGetDeviceIDs(p, CL_DEVICE_TYPE_ALL, ndevs, devs, NULL);
    ocl_cl_check(err, "devices #2");
    if (err)
        return NULL;

    if (numd >= ndevs) {
        fprintf(stderr, "no device number %u", numd);
        return NULL;
    }

    cl_device_id choice = devs[numd];

    char buffer[BUFSIZE];

    err = clGetDeviceInfo(choice, CL_DEVICE_NAME, BUFSIZE, buffer, NULL);
    ocl_cl_check(err, "device name");
    if (err)
        return NULL;

    printf("selected device %d: %s\n", numd, buffer);

    return choice;
}

// Create a one-device context
cl_context ocl_create_context(cl_platform_id p, cl_device_id d)
{
    cl_int err;

    cl_context_properties ctx_prop[] = { CL_CONTEXT_PLATFORM,
                                         (cl_context_properties)p, 0 };

    cl_context ctx = clCreateContext(ctx_prop, 1, &d, NULL, NULL, &err);
    ocl_cl_check(err, "create context");
    if (err)
        return NULL;

    return ctx;
}

// Create a command queue for the given device in the given context
cl_command_queue ocl_create_queue(cl_context ctx, cl_device_id d)
{
    cl_int err;

    cl_queue_properties props[] = {
        CL_QUEUE_PROPERTIES,
        CL_QUEUE_PROFILING_ENABLE,
        0,
    };
    cl_command_queue que =
            clCreateCommandQueueWithProperties(ctx, d, props, &err);
    ocl_cl_check(err, "create queue");
    if (err)
        return NULL;

    return que;
}

// Compile the device part of the program, stored in the external
// file `fname`, for device `dev` in context `ctx`
cl_program ocl_create_program(const char *const fname, cl_context ctx,
                              cl_device_id dev)

{
    cl_int err, errlog;
    cl_program prg;

    char src_buf[BUFSIZE + 1];
    char *log_buf = NULL;
    size_t logsize;
    const char *buf_ptr = src_buf;
    memset(src_buf, 0, BUFSIZE);

    snprintf(src_buf, BUFSIZE, "#include \"%s\"\n", fname);
    prg = clCreateProgramWithSource(ctx, 1, &buf_ptr, NULL, &err);
    ocl_cl_check(err, "create program");
    if (err)
        return NULL;

    err = clBuildProgram(prg, 1, &dev, "-I.", NULL, NULL);
    errlog = clGetProgramBuildInfo(prg, dev, CL_PROGRAM_BUILD_LOG, 0, NULL,
                                   &logsize);
    ocl_cl_check(errlog, "get program build log size");
    if (err)
        return NULL;

    log_buf = (char *)malloc(logsize);
    errlog = clGetProgramBuildInfo(prg, dev, CL_PROGRAM_BUILD_LOG, logsize,
                                   log_buf, NULL);
    ocl_cl_check(errlog, "get program build log");
    if (err)
        return NULL;

    while (logsize > 0 &&
           (log_buf[logsize - 1] == '\n' || log_buf[logsize - 1] == '\0')) {
        logsize--;
    }
    if (logsize > 0) {
        log_buf[logsize] = '\n';
        log_buf[logsize + 1] = '\0';
    } else {
        log_buf[logsize] = '\0';
    }
    ocl_cl_check(err, "build program");
    if (err)
        return NULL;

    return prg;
}

/* round gws to the next multiple of lws */
size_t round_mul_up(size_t gws, size_t lws)
{
    return ((gws + lws - 1) / lws) * lws;
}

// NOLINTEND(misc-definitions-in-headers)
