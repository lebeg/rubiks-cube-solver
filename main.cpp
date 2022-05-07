#include "src/Cube.h"
#include "src/Render.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int main(int argc, char** argv)
{
    // init GLUT and create Window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Rubik's Cube Solver");

    /* that is indeed a bit ugly */
    glutDisplayFunc([]() {
        static Cube cube;
        static Render render(cube);
        render.draw();
    });

    glutMainLoop();

    return EXIT_SUCCESS;
}
