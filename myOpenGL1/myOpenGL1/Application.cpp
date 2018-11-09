#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

#define ASSERT(x) if (!(x)) __debugbreak();

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        cout << "[OpenGL Error] (" << error << "): " << function <<
            " " << file << ":" << line << endl;
        return false;
    }
    return true;
}

struct ShaderProgramSource
{
    string VertexSource;
    string FragementSource;
};

static int CompileShader(GLuint type, const string& source)
{
    GLuint id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        cout << "Failed to compile " <<
            (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " Shader.\n";
        cout << message << endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

static int CreateShader(const ShaderProgramSource shdrsrc)
{
    GLuint program = glCreateProgram();
    GLuint vs = CompileShader(GL_VERTEX_SHADER, shdrsrc.VertexSource);
    GLuint fs = CompileShader(GL_FRAGMENT_SHADER, shdrsrc.FragementSource);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        cout << "GLEW NOT OKAY!\n";

    cout << glGetString(GL_VERSION);

    float positions[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.5f,  0.5f,
        -0.5f,  0.5f,
    };

    unsigned int indicies[] = {
        0, 1, 2, 
        2, 3, 0
    };

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0x0);

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indicies, GL_STATIC_DRAW);

    ShaderProgramSource shaderSrc;

    shaderSrc.VertexSource =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "uniform vec4 u_Color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    gl_Position = position;\n"
        "}\n";

    shaderSrc.FragementSource =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;\n"
        "uniform vec4 u_Color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    color = u_Color;\n"
        "}\n";

    GLuint shadersProgram = CreateShader(shaderSrc);
    glUseProgram(shadersProgram);

    GLuint u_ColorLocation = glGetUniformLocation(shadersProgram, "u_Color");

    cout << "\n u_Color Location:" << u_ColorLocation << endl;

    /* Loop until the user closes the window */
   // GLCall(glUniform4f(u_ColorLocation, 0.8f, 0.3f, 0.8f, 1.0f));

    float r = 0.0f, increment = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // glDrawArrays(GL_TRIANGLES, 0, 6);
        //GLClearError();
        GLCall(glUniform4f(u_ColorLocation, r, 0.3f, 0.8f, 1.0f));
        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
        //ASSERT(GLLogCall());

        if (r > 1.0f) {
            increment = -0.05f;
        }
        else if (r < 0.0f){
            increment = 0.05f;
        }

        r += increment;
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shadersProgram);

    glfwTerminate();
    return 0;
}

/*
glBegin(GL_TRIANGLES);
glVertex2f(-0.5f, -0.5f);
glVertex2f(0.0f, 0.5f);
glVertex2f(0.5f, -0.5f);
glVertex2f(0.1f, 0.5f);
glVertex2f(0.6f, -0.5f);
glVertex2f(1.1f, 0.5f);
glEnd();
*/