float3 multi(float3 vec, float3 *mat)
{
    float3 out = (float3)(dot(vec, mat[0]), dot(vec, mat[1]), dot(vec, mat[2]));
    return out;
}

kernel void donut(global float *restrict out, float A, float B, int n_phi)
{
    int ti = get_global_id(0);

    int n_theta = 100;

    int ind = ti * n_phi * 12;

    float theta = ti * 0.0628f;

    float3 Rx[] = { //
        (float3)(1, 0, 0), //
        (float3)(0, cos(A), -sin(A)), //
        (float3)(0, sin(A), cos(A))
    };

    float3 Rz[] = { //
        (float3)(cos(B), -sin(B), 0), //
        (float3)(sin(B), cos(B), 0), //
        (float3)(0, 0, 1)
    };

    float3 circle = { 2 + cos(theta), sin(theta), 0 };

    for (int pi = 0; pi < n_phi; pi += 1) {
        float phi = pi * 0.02f;

        float3 Ry[] = { //
            (float3)(cos(phi), 0, -sin(phi)), //
            (float3)(0, 1, 0), //
            (float3)(sin(phi), 0, cos(phi))
        };

        float3 no_spin = multi(circle, Ry);
        float3 spin_x = multi(no_spin, Rx);
        float3 donut = multi(spin_x, Rz);

        float sz_x = 0.15f, sz_y = 0.15f;

        out[ind++] = donut.x;
        out[ind++] = donut.y;
        out[ind++] = donut.z;

        out[ind++] = donut.x + sz_x;
        out[ind++] = donut.y;
        out[ind++] = donut.z;

        out[ind++] = donut.x;
        out[ind++] = donut.y + sz_y;
        out[ind++] = donut.z;

        out[ind++] = donut.x + sz_x;
        out[ind++] = donut.y + sz_y;
        out[ind++] = donut.z;
    }
}
