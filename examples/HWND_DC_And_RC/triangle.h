#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <glad/glad.h>
#include <Windows.h>

namespace RenderSource
{
    const char* vertexShaderSource =
        "#version 460 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{ \n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); \n"
        "} \0";

    // render data 
    float vertices[] = {
   -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
    };

};

class Triangle
{
public:
    Triangle() = default;
    ~Triangle() = default;

    void create(HDC hdc, HGLRC hrc)
    {
        wglMakeCurrent(hdc, hrc);
        createProgram();

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(RenderSource::vertices), RenderSource::vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

    }

    void draw()
    {
        glClearColor(0.4, 0.4, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);
        glUseProgram(shaderProgram);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glFlush();
    }

    void createProgram()
    {
        // create shader 
        // vertex shader
        GLuint vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &RenderSource::vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        // ºÏ≤È±‡“Î 
        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        else
        {
            std::cout << "SUCCESS::SHADER::VERTEX:\n" << std::endl;

        }

        // fragment
        GLuint fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &RenderSource::fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        else
        {
            std::cout << "SUCCESS::SHADER::FRAGMENT:\n" << std::endl;

        }

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::LINKEFAILED\n" << infoLog << std::endl;
        }
        else
        {
            std::cout << "SUCCESS::SHADER::LINKE\n" << infoLog << std::endl;
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
        }
    }


private:
    GLuint vao{0};
    GLuint vbo{0};

    GLuint shaderProgram{0};

};


#endif 