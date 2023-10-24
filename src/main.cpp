#include <GL/glut.h>
#include <iostream>

float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = -5.0f;

float cameraRotationX = 0.0f;
float cameraRotationY = 0.0f;
float cameraRotationZ = 0.0f;
float cameraZoom = 1.0f;

void setCamera()
{
    glLoadIdentity();
    glTranslatef(cameraX, cameraY, cameraZ);
    glRotatef(cameraRotationX, 1.0, 0.0, 0.0);
    glRotatef(cameraRotationY, 0.0, 1.0, 0.0);
    glRotatef(cameraRotationZ, 0.0, 0.0, 1.0);
    glScalef(cameraZoom, cameraZoom, cameraZoom);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    setCamera();

    glColor3f(1.0f, 1.0f, 0.0f);

    glutSolidCube(0.5);

    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0, 2, 0);
    glVertex3f(0, -2, 0);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(2, 0, 0);
    glVertex3f(-2, 0, 0);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0, 0, 2);
    glVertex3f(0, 0, -2);

    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;

    case 'q':
        cameraZ -= 0.1f;
        break;
    case 'e':
        cameraZ += 0.1f;
        break;
    case 'd':
        cameraX -= 0.1f;
        break;
    case 'a':
        cameraX += 0.1f;
        break;
    case 'w':
        cameraY -= 0.1f;
        break;
    case 's':
        cameraY += 0.1f;
        break;
    case 'i':
        cameraRotationX += 5.0f;
        break;
    case 'u':
        cameraRotationX -= 5.0f;
        break;
    case 'k':
        cameraRotationY += 5.0f;
        break;
    case 'j':
        cameraRotationY -= 5.0f;
        break;
    case 'm':
        cameraRotationZ += 5.0f;
        break;
    case 'n':
        cameraRotationZ -= 5.0f;
        break;
    case '+':
        cameraZoom *= 1.1f;
        break;
    case '-':
        cameraZoom /= 1.1f;
        break;
    default:
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[1]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(processNormalKeys);
    glutMainLoop();
    return 0;
}