#include <GL/glut.h>
#include <cmath>

// Camera parameters
GLfloat cameraPosition[] = {0.0, 0.0, 5.0};
GLfloat cameraRotation[] = {0.0, 0.0, 0.0};
GLfloat cameraScale = 1.0;

// Panning speed
GLfloat panSpeed = 0.1;

// Translation speed
GLfloat translationSpeed = 0.1;

// Mouse interaction variables
int prevMouseX, prevMouseY;
bool isMouseDragging = false;

// Function to set up the perspective projection
void setProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Function to update the camera transformation using gluLookAt
void updateCamera()
{
    glLoadIdentity();
    GLfloat lookAt[3];
    lookAt[0] = cameraPosition[0] + cos(cameraRotation[0] * M_PI / 180.0) * cos(cameraRotation[1] * M_PI / 180.0);
    lookAt[1] = cameraPosition[1] + sin(cameraRotation[0] * M_PI / 180.0);
    lookAt[2] = cameraPosition[2] + cos(cameraRotation[0] * M_PI / 180.0) * sin(cameraRotation[1] * M_PI / 180.0);

    gluLookAt(cameraPosition[0], cameraPosition[1], cameraPosition[2], lookAt[0], lookAt[1], lookAt[2], 0.0, 1.0, 0.0);
    glScalef(cameraScale, cameraScale, cameraScale);
}

// Function to draw visible axes
void drawAxes()
{
    // Draw the X-axis (red)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(2.0, 0.0, 0.0);
    glEnd();

    // Draw the Y-axis (green)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, -2.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    glEnd();

    // Draw the Z-axis (blue)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, -2.0);
    glVertex3f(0.0, 0.0, 2.0);
    glEnd();
}

// Function to draw cubes for demonstration
void drawCubes()
{
    glColor3f(1.0, 0.0, 0.0); // Red cube
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0.0, 1.0, 0.0); // Green cube
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glutSolidCube(0.5);
    glPopMatrix();

    glColor3f(0.0, 0.0, 1.0); // Blue cube
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    glutSolidCube(0.5);
    glPopMatrix();
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    updateCamera();

    // Render the visible axes
    drawAxes();

    // Render cubes for demonstration
    drawCubes();

    glutSwapBuffers();
}

// Mouse drag function for rotation
void mouseDrag(int x, int y)
{
    if (isMouseDragging)
    {
        int dx = x - prevMouseX;
        int dy = y - prevMouseY;

        cameraRotation[1] += dx * 0.5;
        cameraRotation[0] += dy * 0.5;

        prevMouseX = x;
        prevMouseY = y;
        glutPostRedisplay();
    }
}

// Keyboard function for scaling, translation, and panning
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '+': // Scale up
        cameraScale *= 1.1;
        break;
    case '-': // Scale down
        cameraScale /= 1.1;
        break;
    case 'q': // Translate forward
        cameraPosition[2] -= translationSpeed;
        break;
    case 'e': // Translate backward
        cameraPosition[2] += translationSpeed;
        break;
    case 'a': // Translate left
        cameraPosition[0] -= translationSpeed;
        break;
    case 'd': // Translate right
        cameraPosition[0] += translationSpeed;
        break;
    case 'w': // Pan up
        cameraPosition[1] += panSpeed;
        break;
    case 's': // Pan down
        cameraPosition[1] -= panSpeed;
        break;
    }
    glutPostRedisplay();
}

// Mouse click function
void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            isMouseDragging = true;
            prevMouseX = x;
            prevMouseY = y;
        }
        else if (state == GLUT_UP)
        {
            isMouseDragging = false;
        }
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("OpenGL Camera Navigation");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutMotionFunc(mouseDrag);
    glutMouseFunc(mouseClick);
    glutKeyboardFunc(keyboard);

    setProjection();

    glutMainLoop();
    return 0;
}
