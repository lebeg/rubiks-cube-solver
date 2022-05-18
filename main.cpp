#include "src/Cube.h"
#include "src/Render.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Rubik's Cube Solver");

    /* that is indeed a bit ugly */
    auto render = []() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        gluLookAt(
            0.0f, 0.0f, 5.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f);

        static auto angle = 0.f;
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        angle += 0.1f;

        static Cube cube;
        static Render render(cube);
        render.draw();

        glutSwapBuffers();
    };
    glutDisplayFunc(render);
    glutIdleFunc(render);

    glutReshapeFunc([](int width, int height) {
        if (height == 0) {
            height = 1;
        }

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, width, height);
        glEnable(GL_DEPTH_TEST);

        auto ratio = static_cast<float>(width) / static_cast<float>(height);
        gluPerspective(45.0f, ratio, 0.1f, 100.0f);

        glMatrixMode(GL_MODELVIEW);
    });

    glutMainLoop();

    return EXIT_SUCCESS;
}
