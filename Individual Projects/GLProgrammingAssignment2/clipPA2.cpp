//  Implementing clipping planes using OpenGL functions
//Kirk McBrayer
//cs435628
#include <glut.h>
#include <stdlib.h>

static GLfloat shift = 0.0;   // Initialize the fourth parameter of the plane equation

void init(void)
{
    glClearColor(0.0, 0.5, 0.0, 0.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLdouble eqn0[4] = { 1.0, 0.5, -1.0, shift };  // Parameters array of the first plane
    glClipPlane(GL_CLIP_PLANE0, eqn0);         // Create the first plane with eqn0 array
        glEnable (GL_CLIP_PLANE0);                  // Activate the first plane

    GLdouble eqn1[4] = { 0.0, 1.0, 0.0, 3.0 };  // Parameters array of the second plane
    glClipPlane(GL_CLIP_PLANE1, eqn1);         // Create the second plane with eqn1 array
        glEnable(GL_CLIP_PLANE1);                  // Activate the second plane

    /* Draw five different objects at different locations  */
    glLineWidth(2.0);
    glPushMatrix();
    glutSolidTeapot(2.0);
    glTranslatef(3.0, 3.0, 0.0);
    glutSolidTorus(0.4, 0.8, 20, 20);
    glTranslatef(-6.0, 0.0, 0.0);
    glutWireIcosahedron();
    glTranslatef(0.0, -6.0, 0.0);
    glutSolidSphere(1.0, 20, 20);
    glTranslatef(6.0, 0.0, 0.0);
    glutWireCube(2.0);
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


/* Implement any keyboard function to increase or decrese the value of
"shift" to interactively adjust the position of the clipping plane */

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'f':
        if (shift < 6) {
            shift++;
        }            
        glutPostRedisplay();
        break;
    case 'b':
        if (shift > -6) {
            shift--;
        }              
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Planner clipping");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}