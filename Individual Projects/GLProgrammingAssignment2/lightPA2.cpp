//  Adding lighting effects on a simple solar system (sun + earth)
//Kirk McBrayer
//cs435628
#include <glut.h>
#include <stdlib.h>

static GLfloat year = 0.0, day = 90.0;

void init(void)
{
    glClearColor(0.0, 0.2, 0.2, 0.0);

    GLfloat light0_position[] = { 0.0, 0.0, 2.0, 0.0 };
    GLfloat light0_ambient[] = {0.0, 0.0, 0.0, 1.0 };  // ambient light color
    GLfloat light0_specular[] = {0.0, 0.0, 0.0, 1.0 };  // specular light color
    GLfloat light0_diffuse[] = {1.0, 1.0, 0.0, 1.0 };  // diffusive light color

    GLfloat light1_position[] = { 0.0, 0.0, 2.0, 1.0 };
    GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };  // ambient light color
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };  // specular light color
    GLfloat light1_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };  // diffusive light color

    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);

    
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat light_sun_ambient[] = {0.0, 0.0, 0.0, 1.0 };  // ambient light color
    GLfloat light_sun_specular[] = {0.0, 0.0, 0.0, 1.0 };  // specular light color
    GLfloat light_sun_diffuse[] = {0.5, 0.5, 0.5, 1.0 };  // diffusive light color
    GLfloat light_sun_emission[] = {1.0, 0.0, 0.0, 1.0 };  // emission light color

    GLfloat light_earth_ambient[] = { 0.0, 0.0, 0.0, 1.0 };  // ambient light color
    GLfloat light_earth_specular[] = { 1.0, 1.0, 1.0, 1.0 };  // specular light color
    GLfloat light_earth_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };  // diffusive light color
    GLfloat light_earth_emission[] = { 0.0, 0.0, 0.0, 1.0 };  // emission light color
    GLfloat light_earth_shininess[] = { 100.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, light_sun_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, light_sun_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_sun_diffuse);
    glMaterialfv(GL_FRONT, GL_EMISSION, light_sun_emission);

    glPushMatrix();
    glRotatef(year, 0.0, 1.0, 0.0);
    glutSolidSphere(1.0, 100, 100);
    glTranslatef(3.0, 0.0, 0.0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, light_earth_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, light_earth_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, light_earth_diffuse);
    glMaterialfv(GL_FRONT, GL_EMISSION, light_earth_emission);
    glMaterialfv(GL_FRONT, GL_SHININESS, light_earth_shininess);

    glRotatef(day, 0.5, 1.0, 0.0);
    glDepthMask(GL_FALSE);
    glutSolidSphere(0.5, 100, 100);
    glDepthMask(GL_TRUE);
    glPopMatrix();
    glutSwapBuffers();
}

void yearDisplay(void)
{
    year = year + 0.01;
    if (year > 360.0)
        year = year - 360.0;
    day = day + 0.05;
    if (day > 360.0)
        day = day - 360.0;
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
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lighting");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}