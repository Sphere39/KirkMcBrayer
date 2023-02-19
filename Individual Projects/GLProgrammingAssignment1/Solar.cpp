/*Kirk McBrayer*/
/*cs435628*/
/* A simple solar system with a sun and a planet   */

#include <glut.h>
#include <stdlib.h>

static GLfloat year = 0.0, venusYear = 0.0, day = 0.0, moonDay = 0.0;

void display(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);		/* clears the color buffer to black color */
    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();
    glRotatef(year, 0.0, 1.0, 0.0);
    glutWireSphere(1.0, 20, 16);    		/* draws a sun */
    glTranslatef(5.0, 0.0, 0.0);
    glRotatef(day, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0); 
    glutWireSphere(0.5, 10, 8);	/* draws Earth */
    glRotatef(-day, 0.0, 1.0, 0.0);
    glRotatef(moonDay, 0.5, 0.86, 0.0);
    glTranslatef(1.0, -0.5, 0.0);
    glColor3f(0.75, 0.75, 0.75);
    glutWireSphere(0.2, 10, 8);	/* draws a moon */
    glPopMatrix();

    glPushMatrix();
    glRotatef(venusYear, 0.0, 1.0, 0.0);
    glutWireSphere(0.0, 0.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef(day, 0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glutWireSphere(0.3, 10, 8);	/* draws Venus */
    glPopMatrix();
    glutSwapBuffers();
}

void yearDisplay(void)
{
    year = year + 0.1;
    if (year > 360.0)
        year = year - 360.0;

    venusYear = venusYear + 0.2;
    if (venusYear > 360.0)
        venusYear = venusYear - 360.0;

    day = day + 0.5;
    if (day > 360.0)
        day = day - 360.0;

    moonDay = moonDay + 1.0;
    if (moonDay > 360.0)
        moonDay = moonDay - 360.0;
    glutPostRedisplay();
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

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'y':
        glutIdleFunc(yearDisplay);
        break;
    case 'n':
        glutIdleFunc(NULL);
        break;
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1250, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("A simple solar system");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}