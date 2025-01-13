#include <GLFW/glfw3.h>
#include <cmath>
#define PI 3.14159265359

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Juan Morcwel D.Sy-wico", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    const float OctRadius = 0.5f;
    const int OctSides = 8;
    const float OctAngle = 2 * PI / OctSides;

    float centerY = 0.54;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);

        for (int i = 0; i < OctSides; ++i) {
            float angle = i * OctAngle - PI / 8;

            float x = OctRadius * cos(angle);
            float y = centerY + OctRadius * sin(angle);

            glVertex2d(x, y);
        }
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}



















































