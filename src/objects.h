#pragma once
#include <GL/glut.h>

void bedleg3()
{
    float dimn[3] = {40, 150, 40};
    float cntr[3] = {20, 50, -720};
    float clr[3] = {0.6f, 0.3f, 0.1f};
    drawCube(dimn, cntr, clr);
}
void bedleg4()
{
    float dimn[3] = {40, 150, 40};
    float cntr[3] = {280, 50, -720};
    float clr[3] = {0.6f, 0.3f, 0.1f};
    drawCube(dimn, cntr, clr);
}
void bedleg2()
{
    float dimn[3] = {40, 150, 40};
    float cntr[3] = {280, 50, -980}; // the z is changed from the 4th leg
    float clr[3] = {0.6f, 0.3f, 0.1f};
    drawCube(dimn, cntr, clr);
}
void bedleg1()
{
    float dimn[3] = {40, 150, 40};
    float cntr[3] = {20, 50, -980};
    float clr[3] = {0.6f, 0.3f, 0.1f};
    drawCube(dimn, cntr, clr);
}

// saame for table legs as well

void table_Top_Leg3()
{
    float dimn[3] = {25, 100, 25};
    float cntr[3] = {812.5, 25, -12.5}; // the dimension for the legs of the table, the dimension of the square from the top is 25*25
    float clr[3] = {0.6f, 0.3f, 0.1f};
    drawCube(dimn, cntr, clr);
}
void table_Top_Leg4()
{
    float dimn[3] = {25, 100, 25};
    float cntr[3] = {987.5, 25, -12.5}; // the dimension for the legs of the table, the dimension of the square from the top is 25*25
    float clr[3] = {0.6f, 0.3f, 0.1f};
    drawCube(dimn, cntr, clr);
}
void table_Top_Leg2()
{
    float dimn[3] = {25, 100, 25};
    float cntr[3] = {987.5, 25, -287.5}; // the dimension for the legs of the table, the dimension of the square from the top is 25*25
    float clr[3] = {0.6f, 0.3f, 0.1f};
    drawCube(dimn, cntr, clr);
}
void table_Top_Leg1()
{
    float dimn[3] = {25, 100, 25};
    float cntr[3] = {812.5, 25, -287.5}; // the dimension for the legs of the table, the dimension of the square from the top is 25*25
    float clr[3] = {0.6f, 0.3f, 0.1f};
    drawCube(dimn, cntr, clr);
}
void drawCube(float dimn[], float cntr[], float clr[]) // draws the tables and chairs
{

    // Color set here
    glColor3f(clr[0], clr[1], clr[2]);
    glBegin(GL_QUADS);

    // Front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);

    // Right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(+(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);

    // Back
    glNormal3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);

    // Left
    glNormal3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);

    // Top
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);

    // Bottom
    glNormal3f((dimn[0] / 2) + cntr[0], -1.0f, 0.0f);
    glVertex3f(-(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], +(dimn[2] / 2) + cntr[2]);
    glVertex3f(+(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f(-(dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);

    glEnd();
}
// convert to cpp code

void door()
{
    float dimn[3] = {200, 600, 2};
    float cntr[3] = {800, 600, -1000};
    float clr[3] = {1.0f, 1.0f, 0.0f};
    drawCube(dimn, cntr, clr);
}

void table_Top() // /////
{
    float dimn[3] = {200, 150, 300};
    float cntr[3] = {900, 125, -150};
    float clr[3] = {0.8f, 0.6f, 0.4f};
    table_Top_Leg1();
    table_Top_Leg2();
    table_Top_Leg3();
    table_Top_Leg4();
    drawCube(dimn, cntr, clr);
}
void window()
{
    float dimn[3] = {300, 200, 20};
    float cntr[3] = {750, 700, 0};
    float clr[3] = {0.6f, 0.8f, 1.0f};
    drawCube(dimn, cntr, clr);
}
// chair dekhte hain
void cupboard()
{
    float dimn[3] = {550, 800, 300};
    float cntr[3] = {275, 400, -150};
    float clr[3] = {0.5f, 0.5f, 0.5f};
    drawCube(dimn, cntr, clr);
}
void bed()
{
    float dimn[3] = {300, 50, 600}; // this is basically for hr dimension of teh bed
    float cntr[3] = {150, 125, -700};
    float clr[3] = {0.6f, 0.3f, 0.1f};
    bedleg1();
    bedleg2();
    bedleg3();
    bedleg4();
    drawCube(dimn, cntr, clr);
}

void blackboard()
{
    float dimn[3] = {2, 200, 300};
    float cntr[3] = {1000, 500, -150};
    float clr[3] = {0.0f, 0.0f, 0.0f};
    drawCube(dimn, cntr, clr);
}

// void drawxx
void drawRoom()
{
    glBegin(GL_QUADS);
    // Floor /
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0, 0, 0);
    glVertex3f(1000, 0, 0);
    glVertex3f(1000, 0, -1000);
    glVertex3f(0, 0, -1000);
    // Ceiling /
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0, 1000, 0);
    glVertex3f(1000, 1000, 0);
    glVertex3f(1000, 1000, -1000);
    glVertex3f(0, 1000, -1000);
    // Walls
    glColor3f(0.0f, 0.0f, 1.0f); // wall with the blackboard // or the right wall
    glVertex3f(1000, 0, 0);
    glVertex3f(1000, 0, -1000);
    glVertex3f(1000, 1000, 0);
    glVertex3f(1000, 1000, -1000);

    // glColor3f(0.0f, 0.0f, 0.0f); // blackboard
    // glVertex3f(-20, 0, 59.9);
    // glVertex3f(20, 0, 59.9);
    // glVertex3f(20, 20, 59.9);
    // glVertex3f(-20, 20, 59.9);

    glColor3f(0.0f, 0.0f, 1.0f); // back wall
    glVertex3f(0, 0, -1000);
    glVertex3f(0, 1000, -1000);
    glVertex3f(1000, 1000, -1000);
    glVertex3f(-1000, 0, -1000);

    glColor3f(1.0f, 1.0f, 0.0f); // front wall
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1000, 0);
    glVertex3f(1000, 1000, 0);
    glVertex3f(-1000, 0, 0);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, -1000);
    glVertex3f(0, 1000, 0);
    glVertex3f(0, 1000, -1000);

    glEnd();
}