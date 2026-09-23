#include "../renderer.hpp"
#include <x86intrin.h>
#define NO_CL
#include "types.hpp"
#include <math.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <unistd.h>

int main()
{
    Renderer render("Spinning Donut");
    glDisable(GL_BLEND);

    // A is at 135 deg
    float A = 2.35614675, B = 0;

    DonutBuffer buffer;
    buffer.init_cl("donut.cl");
    // uncomment next line or pass NULL in init_cl
    // if you wanna use your cpu for computing and cook your CPU
    // buffer.use_cpu();

    const int zPov = 10;

    glm::mat4 View = glm::lookAt(
        glm::vec3(0, 0, zPov), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

    glm::mat4 Model = glm::mat4(1.0f);
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f),
        4.f / 3.f, // width / height
        .1f, 100.0f);

    glm::mat4 mvp = Projection * View * Model;
    render.load_shaders("vertex.glsl", "fragment.glsl");

    GLuint mvp_id = glGetUniformLocation(render.program_id, "MVP");
    glUniformMatrix4fv(mvp_id, 1, GL_FALSE, &mvp[0][0]);

    int end = 0;

    GLuint vertex_buffer, vertex_array_id;
    glGenVertexArrays(1, &vertex_array_id);
    glBindVertexArray(vertex_array_id);
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    render.register_vertex_info(vertex_array_id, vertex_buffer);

    render.clear_color(0.125, 0.125, 0.125, 1);
    render.render_loop([&A, &B, &buffer](Renderer &render) {
        if (render.window_close())
            return 1;

        if (buffer.cl_enabled()) {
            buffer.cl_render(A, B);
        } else {
            buffer.cpu_render(A, B);
        }

        if (render.window_close())
            return 1;

        render.draw([&buffer]() {
            glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(GLfloat),
                buffer.data(), GL_DYNAMIC_DRAW);

            glDrawArrays(GL_TRIANGLE_STRIP, 0, buffer.size() / 3);
        });
        usleep(20000);
        A += 0.0704;
        B += 0.0352;
        return 0;
    });
    std::cout << "\n";
}

void DonutBuffer::cpu_render(float A, float B)
{
    reset();
    const int R2 = 2, R1 = 1;
    mat3f Rx = {
        { 1, 0, 0 },
        { 0, cos(A), -sin(A) },
        { 0, sin(A), cos(A) },
    };

    mat3f Rz = {
        { cos(B), -sin(B), 0 },
        { sin(B), cos(B), 0 },
        { 0, 0, 1 },
    };

    int n_theta = 100;
    int n_phi = 314;
    for (int ti = 0; ti < n_theta; ti++) {
        float theta = ti * 0.0628;
        for (int pii = 0; pii < n_phi; pii++) {
            float phi = pii * 0.02;
            vec3f circle = { R2 + R1 * cos(theta), R1 * sin(theta), 0 };

            mat3f Ry = {
                { cos(phi), 0, -sin(phi) },
                { 0, 1, 0 },
                { sin(phi), 0, cos(phi) },
            };

            vec3f donut = circle * Ry * Rx * Rz;

            GLfloat sz_y = 0.15, sz_x = 0.15;

            push({
                donut.x, donut.y, donut.z, //
                donut.x + sz_x, donut.y, donut.z, //
                donut.x, donut.y + sz_y, donut.z, //
                donut.x + sz_x, donut.y + sz_y, donut.z //
            });
        }
    }
}
