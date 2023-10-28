#include <GL/glut.h>
#include <iostream>

GLfloat cameraPosition[3] = {0.0f, 0.0f, -5.0f};
GLfloat cameraFront[3] = {0.0f, 0.0f, 1.0f};
GLfloat cameraUp[3] = {0.0f, 1.0f, 0.0f};
GLfloat cameraSpeed = 0.05f;

GLfloat pitch = 0.0f;
GLfloat yaw = -90.0f;
GLfloat roll = 0.0f;
GLfloat sensitivity = 0.05f;

GLfloat scaleFactor = 1.0f;

float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = -5.0f;

float cameraRotationX = 0.0f;
float cameraRotationY = 0.0f;
float cameraRotationZ = 0.0f;
float cameraZoom = 1.0f;

void setCamera()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        cameraPosition[0], cameraPosition[1], cameraPosition[2],
        cameraPosition[0] + cameraFront[0], cameraPosition[1] + cameraPosition[1], cameraPosition[2] + cameraPosition[2],
        cameraUp[0], cameraUp[1], cameraUp[2]);

    glScalef(scaleFactor, scaleFactor, scaleFactor);

    glRotatef(pitch, 1.0f, 0.0f, 0.0f);
    glRotatef(yaw, 0.0f, 1.0f, 0.0f);
    glRotatef(roll, 0.0f, 0.0f, 1.0f);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setCamera();

    glColor3f(1.0f, 1.0f, 0.0f);

    // door();
    // table_Top();
    // window();
    // // drawRoom();
    // cupboard();
    // bed();
    // blackboard();
    // glutSolidCube(0.5);

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
        for (int i = 0; i < 3; i++)
        {
            cameraPosition[i] += cameraSpeed * cameraFront[i];
        }
        break;
    case 's':
        for (int i = 0; i < 3; i++)
        {
            cameraPosition[i] -= cameraSpeed * cameraFront[i];
        }
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

void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[1]);

    glutDisplayFunc(display);
    glutReshapeFunc(handleResize);
    glutKeyboardFunc(processNormalKeys);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
    return 0;
}