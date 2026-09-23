#include <cmath>
#include <initializer_list>

template <class T = float> struct vec3 {
    T x, y, z;

    vec3()
    {
        x = 0, y = 0, z = 0;
    }

    vec3(std::initializer_list<T> vec)
    {
        x = *vec.begin();
        y = *(vec.begin() + 1);
        z = *(vec.begin() + 2);
    }

    vec3(T a, T b, T c)
    {
        x = a, y = b, z = c;
    }

    T operator*(vec3<T> other)
    {
        return x * other.x + y * other.y + z * other.z;
    }

    T &operator[](int index)
    {
        switch (index) {
        case 0:
            return x;
        case 1:
            return y;
        default:
            return z;
        }
    }
};

template <class T> struct mat3 {
    vec3<T> v0, v1, v2;

    mat3(std::initializer_list<vec3<T>> vec)
    {
        v0 = *vec.begin();
        v1 = *(vec.begin() + 1);
        v2 = *(vec.begin() + 2);
    }

    T *data()
    {
        return &v0.x;
    }

    mat3()
    {
        v0 = vec3();
        v1 = vec3();
        v2 = vec3();
    }

    vec3<T> &operator[](size_t ind)
    {
        if (ind == 0)
            return v0;
        else if (ind == 1)
            return v1;
        else
            return v2;
    }
};

using mat3f = mat3<float>;
using vec3f = vec3<float>;

#ifdef NO_CL
typedef struct _cl_command_queue *cl_command_queue;
typedef struct _cl_mem *cl_mem;
typedef struct _cl_kernel *cl_kernel;

vec3f operator*(vec3f vec, mat3f mat)
{
    return vec3f(vec * mat.v0, vec * mat.v1, vec * mat.v2);
}
#else
#include "ocl.h"
#endif
class DonutBuffer {
    float *ptr;
    size_t length;
    size_t pos;

    cl_mem donut_mem;
    cl_kernel donut_k;
    cl_command_queue que;

    bool use_cl = false;

public:
    DonutBuffer()
    {
        length = 12 * 100 * 314;
        pos = 0;
        ptr = new float[length];
    }

    void init_cl(const char *const cl_prog_name);

    bool cl_enabled()
    {
        return use_cl;
    }

    float &operator[](size_t ind)
    {
        return ptr[ind];
    }

    void use_cpu()
    {
        use_cl = false;
    }

    void reset()
    {
        pos = 0;
    }

    void push(std::initializer_list<float> args)
    {
        for (auto i : args) {
            ptr[pos++] = i;
        }
    }

    size_t size()
    {
        return length;
    }

    float *data()
    {
        return ptr;
    }

    ~DonutBuffer()
    {
        delete[] ptr;
    }

    void cl_render(float A, float B);

    void cpu_render(float A, float B);
};
