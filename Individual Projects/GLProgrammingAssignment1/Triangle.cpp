/*Kirk McBrayer*/
/*cs435628*/
// A simple OpenGL program which draws a red triangle in a white window.
// c++ -w triangle.cpp -framework OpenGL -framework GLUT 

#include <glut.h>  //Change the location as needed to <GL/glut.h> or <glut.h>
#include <stdlib.h>

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);     // Display window clearing color
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);               // To draw a square using four vertices
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.6, -0.6);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.6, -0.6);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.6, 0.6);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.6, 0.6);
    glEnd();
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-0.6, -0.6);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.6, 0.6);
    glVertex2f(-0.6, 0.6);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0, 1.0f);
    glEnd();
    glFlush();                            // Start drawing
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {			// Exit or close the display when press "esc" key
    case 27:
        exit(0);
        break;
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("A multi-colored square in a white window");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}