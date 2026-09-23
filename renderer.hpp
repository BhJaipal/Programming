#include "glad/gl.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <stdarg.h>

inline __attribute__((noreturn)) void crash(const char *msg, ...)
{
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    exit(1);
}
static void glfw_error_callback(int error, const char *description)
{
    std::cerr << "Glfw Error " << error << description << "\n";
}

class Renderer {
public:
    GLuint program_id = 0;
    GLFWwindow *window = NULL;
    GLuint vertex_array_id, vertex_buffer;
    Renderer(const char *app_title, int width = 950, int height = 800);

    GLuint compile_shader(const char *shader_path, int shader_type);

    void load_shaders(
        const char *vertex_file_path, const char *fragment_file_path);

    void clear_color(
        GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
    {
        glClearColor(red, green, blue, alpha);
    }

    void register_vertex_info(GLuint array_id, GLuint buffer)
    {
        vertex_array_id = array_id;
        vertex_buffer = buffer;
    }

    /// @param main_loop Return 1 if you want to exit else 0
    void draw(std::function<void()> main_loop)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(vertex_array_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        main_loop();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /// @param main_loop Return 1 if you want to exit else 0
    void draw(std::function<void(Renderer &)> main_loop)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(vertex_array_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        main_loop(*this);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /// @param main_loop Return 1 if you want to exit else 0
    void draw(std::function<void(GLuint, GLuint)> main_loop,
        GLuint vertex_array_id, GLuint vertex_buffer)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(vertex_array_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        main_loop(vertex_array_id, vertex_buffer);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    GLboolean window_close()
    {
        return glfwWindowShouldClose(window);
    }

    /// @param main_loop Return 1 if you want to exit else 0
    template <class T>
    void render_loop(std::function<GLboolean(Renderer &self)> main_loop)
    {
        while (!glfwWindowShouldClose(window)) {
            auto out = main_loop(*this);
            if (out)
                break;
        }
    }

    /// @param main_loop Return 1 if you want to exit else 0
    template <class T, class... Args>
    void render_loop(T main_loop, Args... args)
    {
        while (!glfwWindowShouldClose(window)) {
            auto out = main_loop(*this, args...);
            if (out)
                break;
        }
    }

    /// @param main_loop Return 1 if you want to exit else 0
    template <class T, class... Args>
    void render_loop_vertex(T main_loop, Args... args)
    {
        while (!glfwWindowShouldClose(window)) {
            auto out =
                main_loop(*this, vertex_array_id, vertex_buffer, args...);
            if (out)
                break;
        }
    }

    /// @param main_loop Return 1 if you want to exit else 0
    template <class T, class... Args>
    void render_loop_vertex(
        T main_loop, GLuint vertex_array_id, GLuint vertex_buffer, Args... args)
    {
        while (!glfwWindowShouldClose(window)) {
            auto out =
                main_loop(*this, vertex_array_id, vertex_buffer, args...);
            if (out)
                break;
        }
    }

    ~Renderer()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

inline Renderer::Renderer(const char *app_title, int width, int height)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        crash("Cannot initialize GLFW\n");

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 0);

    window = glfwCreateWindow(width, height, app_title, NULL, NULL);
    if (window == NULL)
        crash("GLFW cannot create window\n");

    glfwMakeContextCurrent(window);
    int version =
        gladLoadGL(reinterpret_cast<GLADloadfunc>(glfwGetProcAddress));

    if (version == 0) {
        glfwDestroyWindow(window);
        glfwTerminate();
        crash("Failed to initialize GLAD\n");
    }
    // Enable vsync
    glfwSwapInterval(1);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

// NOLINTBEGIN(misc-definitions-in-headers)
GLuint Renderer::compile_shader(const char *shader_path, int shader_type)
// NOLINTEND(misc-definitions-in-headers)
{
    // Create the shaders
    GLuint shader_id = glCreateShader(shader_type);

    // Read the Vertex Shader code from the file
    std::string shader_code;
    std::ifstream shader_istream(shader_path, std::ios::in);
    if (shader_istream.is_open()) {
        std::stringstream sstr;
        sstr << shader_istream.rdbuf();
        shader_code = sstr.str();
        shader_istream.close();
    } else {
        crash("Unable to open shader: %s\n", shader_path);
    }
    GLint result = GL_FALSE;
    int info_log_len;

    printf("\e[93m  Compiling %s\e[0m", shader_path);
    fflush(stdout);

    char const *VertexSourcePointer = shader_code.c_str();
    glShaderSource(shader_id, 1, &VertexSourcePointer, NULL);
    glCompileShader(shader_id);

    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_len);
    if (info_log_len > 0) {
        char err_msg[info_log_len + 1];
        glGetShaderInfoLog(shader_id, info_log_len, NULL, err_msg);
        printf("\n");
        crash("Compile Error: %s\n", err_msg);
    } else {
        printf("\r\e[92m  Compiled %s\e[0m  \n", shader_path);
    }
    return shader_id;
}

inline void Renderer::load_shaders(
    const char *vertex_file_path, const char *fragment_file_path)
{
    GLuint vertex_id = compile_shader(vertex_file_path, GL_VERTEX_SHADER);
    GLuint fragment_id = compile_shader(fragment_file_path, GL_FRAGMENT_SHADER);

    if (!vertex_id) {
        crash("Could not compile vertex shader\n");
    }
    if (!fragment_id) {
        crash("Could not compile shader shader\n");
    }

    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_id);
    glAttachShader(program_id, fragment_id);
    glLinkProgram(program_id);

    // Check the program
    int info_log_len, result;
    glGetProgramiv(program_id, GL_LINK_STATUS, &result);
    glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_len);
    if (info_log_len > 0) {
        char err_msg[info_log_len + 1];
        glGetProgramInfoLog(program_id, info_log_len, NULL, err_msg);
        crash("%s\n", err_msg);
    }

    glDetachShader(program_id, vertex_id);
    glDetachShader(program_id, fragment_id);

    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);

    glUseProgram(program_id);
}
