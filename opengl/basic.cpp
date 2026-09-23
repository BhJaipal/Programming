#include "../renderer.hpp"
#include <cmath>
#include <glm/ext/matrix_float3x3.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <unistd.h>

int main()
{
    Renderer render("Pyramids", 900, 800);
    render.load_shaders("vertex.glsl", "fragment.glsl");

    // blue background
    render.clear_color(0.7f, 0.4f, 1.f, 0.0f);

    // Projection matrix: 45° Field of View, 4:3 ratio, display range: 0.1 unit <-> 100 units
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f),
        (float)3 / (float)4, // width / height
        .1f, 100.0f);

    // Camera matrix
    glm::mat4 View = glm::lookAt(
        glm::vec3(2, 1, 7), // Camera is at (2,1,6), in World Space
        glm::vec3(0, 0, 0), // and looks at the origin
        glm::vec3(0, 1, 0)
        // Head is up (set to 0,-1,0 to look upside-down)
    );
    // Model matrix: an identity matrix (model will be at the origin)
    glm::mat4 Model = glm::mat4(1.0f);
    // Our ModelViewProjection: multiplication of our 3 matrices
    glm::mat4 mvp = Projection * View * Model;
    GLuint MatrixID = glGetUniformLocation(render.program_id, "MVP");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

    const float rad_90_deg = 3.14 / 2;
    float theta = 0;
    float phi = 0;
    float delta = 0;

    GLfloat vertices[][6] = {
        // triangle 1
        { -1, 0.25, 0, 0, 1, 0 }, // green left
        { 0, 1.25, 0, 1, 1, 1 }, // white middle
        { 0, 2.5, 0, 0, 0, 1 }, // blue top

        { 0, 2.5, 0, 0, 0, 1 }, // blue top
        { 0, 1.25, 0, 1, 1, 1 }, // white middle
        { 1, 0.25, 0, 1, 0, 0 }, // red right

        { 1, 0.25, 0, 1, 0, 0 }, // red right
        { 0, 1.25, 0, 1, 1, 1 }, // white middle
        { -1, 0.25, 0, 0, 1, 0 }, // green left

        // triangle 2
        { -1, 0.25, 0, 0, 1, 0 }, // green left
        { 0, 1.25, 0, 1, 1, 1 }, // white middle
        { 0, 2.5, 0, 0, 0, 1 }, // blue top

        { 0, 2.5, 0, 0, 0, 1 }, // blue top
        { 0, 1.25, 0, 1, 1, 1 }, // white middle
        { 1, 0.25, 0, 1, 0, 0 }, // red right

        { 1, 0.25, 0, 1, 0, 0 }, // red right
        { 0, 1.25, 0, 1, 1, 1 }, // white middle
        { -1, 0.25, 0, 0, 1, 0 }, // green left
    };

    GLfloat pyramid_tri[][6] = {
        { -1.25, -0.1, 0, 1, 1, 1 }, //
        { -1, -2, -1, 0, 1, 0 }, //
        { 1, -2, -1, 1, 0, 0 }, //

        { -1.25, -0.1, 0, 1, 1, 1 }, //
        { 1, -2, -1, 1, 0, 0 }, //
        { 0, -2, 1, 0, 0, 1 }, //

        { -1.25, -0.1, 0, 1, 1, 1 }, //
        { 0, -2, 1, 0, 0, 1 }, //
        { -1, -2, -1, 0, 1, 0 }, //

    };

    GLfloat pyramid[][6] = {
        { 1, -0.1, 0, 1, 1, 1 }, //
        { -1, -2, -1, 0, 1, 0 }, //
        { 1, -2, -1, 1, 1, 0 }, //

        { 1, -0.1, 0, 1, 1, 1 }, //
        { 1, -2, -1, 1, 1, 0 }, //
        { 1, -2, 1, 1, 0, 0 }, //

        { 1, -0.1, 0, 1, 1, 1 }, //
        { 1, -2, 1, 1, 0, 0 }, //
        { -1, -2, 1, 0, 0, 1 }, //

        { 1, -0.1, 0, 1, 1, 1 }, //
        { -1, -2, 1, 0, 0, 1 }, //
        { -1, -2, -1, 0, 1, 0 }, //

    };

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);

    GLuint vertex_array_id;
    glGenVertexArrays(1, &vertex_array_id);

    const float rad_120_deg = 120.0 / 180 * 3.14;

    render.register_vertex_info(vertex_array_id, vertex_buffer);
    render.render_loop(
        [&vertices, &pyramid_tri, &pyramid, rad_120_deg, rad_90_deg](
            Renderer &render, auto &theta, auto &phi, auto &delta) {
            {
                // triangle 1
                vertices[5][0] = cos(theta); //  red
                vertices[5][2] = sin(theta);

                vertices[6][0] = cos(theta); //  red
                vertices[6][2] = sin(theta);

                vertices[0][0] = -cos(theta); //  green
                vertices[0][2] = -sin(theta);

                vertices[8][0] = -cos(theta); // green
                vertices[8][2] = -sin(theta);

                // triangle 2
                vertices[9 + 5][0] = cos(theta + 1.57); //  red
                vertices[9 + 5][2] = sin(theta + 1.57);

                vertices[9 + 6][0] = cos(theta + 1.57); //  red
                vertices[9 + 6][2] = sin(theta + 1.57);

                vertices[9 + 0][0] = -cos(theta + 1.57); //  green
                vertices[9 + 0][2] = -sin(theta + 1.57);

                vertices[9 + 8][0] = -cos(theta + 1.57); // green
                vertices[9 + 8][2] = -sin(theta + 1.57);
            }

            {
                pyramid_tri[1][0] = -sin(phi + rad_120_deg) - 1.25;
                pyramid_tri[1][2] = -cos(phi + rad_120_deg);
                pyramid_tri[2][0] = -sin(phi + rad_120_deg * 2) - 1.25;
                pyramid_tri[2][2] = -cos(phi + rad_120_deg * 2);

                pyramid_tri[4][0] = -sin(phi + rad_120_deg * 2) - 1.25;
                pyramid_tri[4][2] = -cos(phi + rad_120_deg * 2);
                pyramid_tri[5][0] = -sin(phi) - 1.25;
                pyramid_tri[5][2] = -cos(phi);

                pyramid_tri[7][0] = -sin(phi) - 1.25;
                pyramid_tri[7][2] = -cos(phi);
                pyramid_tri[8][0] = -sin(phi + rad_120_deg) - 1.25;
                pyramid_tri[8][2] = -cos(phi + rad_120_deg);
            }

            {
                pyramid[1][0] = sin(delta + rad_90_deg * 2) + 1;
                pyramid[1][2] = -cos(delta + rad_90_deg * 2);
                pyramid[2][0] = sin(delta + rad_90_deg * 3) + 1;
                pyramid[2][2] = -cos(delta + rad_90_deg * 3);

                pyramid[4][0] = sin(delta + rad_90_deg * 3) + 1;
                pyramid[4][2] = -cos(delta + rad_90_deg * 3);
                pyramid[5][0] = sin(delta) + 1;
                pyramid[5][2] = -cos(delta);

                pyramid[7][0] = sin(delta) + 1;
                pyramid[7][2] = -cos(delta);
                pyramid[8][0] = sin(delta + rad_90_deg) + 1;
                pyramid[8][2] = -cos(delta + rad_90_deg);

                pyramid[10][0] = sin(delta + rad_90_deg) + 1;
                pyramid[10][2] = -cos(delta + rad_90_deg);
                pyramid[11][0] = sin(delta + rad_90_deg * 2) + 1;
                pyramid[11][2] = -cos(delta + rad_90_deg * 2);
            }

            render.draw([vertices, pyramid_tri, pyramid]() {
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
                    GL_DYNAMIC_DRAW);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(
                    0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, NULL);
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                    sizeof(float) * 6, (void *)(3 * sizeof(float)));
                glDrawArrays(GL_TRIANGLES, 0, 12 * 9);

                //

                glBufferData(GL_ARRAY_BUFFER, sizeof(pyramid_tri), pyramid_tri,
                    GL_DYNAMIC_DRAW);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(
                    0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, NULL);
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                    sizeof(float) * 6, (void *)(3 * sizeof(float)));
                glDrawArrays(GL_TRIANGLES, 0, 9);

                //

                glBufferData(
                    GL_ARRAY_BUFFER, sizeof(pyramid), pyramid, GL_DYNAMIC_DRAW);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(
                    0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, NULL);
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
                    sizeof(float) * 6, (void *)(3 * sizeof(float)));
                glDrawArrays(GL_TRIANGLES, 0, 12);
            });
            usleep(20000);
            theta += 0.04;
            phi += 0.04;
            delta += 0.04;

            return 0;
        },
        theta, phi, delta);
}
