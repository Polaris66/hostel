#include <iostream>
#include <vector>
#include <GL/glut.h>

void drawCuboid(vector<float> dimn, vector<float> cntr, vector<float> clr) // draws the tables and chairs
{
    // Color set here
    glColor3f(clr[0], clr[1], clr[2]);
    glBegin(GL_QUADS);

    // Front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);

    // Right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);

    // Back
    glNormal3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], -(dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);

    // Left
    glNormal3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);

    // Top
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], (dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);

    // Bottom
    glNormal3f((dimn[0] / 2) + cntr[0], -1.0f, 0.0f);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);
    glVertex3f((dimn[0] / 2) + cntr[0], -(dimn[1] / 2) + cntr[1], (dimn[2] / 2) + cntr[2]);

    glEnd();
}

void door()
{
    vector<float> dimn = {200, 600, 2};
    vector<float> cntr = {800, 600, -1000};
    vector<float> clr = {0.0f, 1.0f, 0.0f};
    drawCuboid(dimn, cntr, clr);
}

void table_Top() // /////
{
    vector<float> dimn = {200, 150, 300};
    vector<float> cntr = {900, 125, -150};
    vector<float> clr = {0.0f, 1.0f, 0.0f};
    drawCuboid(dimn, cntr, clr);
}
// void table_Legs() // /////
// {
//     vector<float> dimn = {200, 50, 300};
//     vector<float> cntr = {900,125,};
//     vector<float> clr = {0.0f, 1.0f, 0.0f};
//     drawCuboid(dimn, cntr, clr);
// }
void window()
{
    vector<float> dimn = {300, 200, 2};
    vector<float> cntr = {750, 700, 0};
    vector<float> clr = {0.0f, 1.0f, 0.0f};
    drawCuboid(dimn, cntr, clr);
}
// chair dekhte hain
void cupboard()
{
    vector<float> dimn = {550, 800, 300};
    vector<float> cntr = {275, 400, -150};
    vector<float> clr = {0.0f, 1.0f, 0.0f};
    drawCuboid(dimn, cntr, clr);
}
void bed()
{
    vector<float> dimn = {300, 50, 600}; // this is basically for hr dimension of teh bed
    vector<float> cntr = {150, -125, -700};
    vector<float> clr = {0.0f, 1.0f, 0.0f};
    drawCuboid(dimn, cntr, clr);
}

void blackboard()
{
    vector<float> dimn = {2, 200, 300};
    vector<float> cntr = {1000, 500, -150};
    vector<float> clr = {0.0f, 1.0f, 0.0f};
    drawCuboid(dimn, cntr, clr);
}

void drawRoom()
{
    glBegin(GL_QUADS);
    // Floor /
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-100, -5, -100);
    glVertex3f(100, -5, -100);
    glVertex3f(100, -5, 60);
    glVertex3f(-100, -5, 60);
    // Ceiling /
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-100, 100, -100);
    glVertex3f(100, 100, -100);
    glVertex3f(100, 100, 60);
    glVertex3f(-100, 100, 60);
    // Walls
    glColor3f(0.0f, 0.0f, 1.0f); // wall with the blackboard
    glVertex3f(-100, -5, 60);
    glVertex3f(100, -5, 60);
    glVertex3f(100, 100, 60);
    glVertex3f(-100, 100, 60);

    // glColor3f(0.0f, 0.0f, 0.0f); // blackboard
    // glVertex3f(-20, 0, 59.9);
    // glVertex3f(20, 0, 59.9);
    // glVertex3f(20, 20, 59.9);
    // glVertex3f(-20, 20, 59.9);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-100, -5, -100);
    glVertex3f(100, -5, -100);
    glVertex3f(100, 100, -100);
    glVertex3f(-100, 100, -100);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(100, 100, 60);
    glVertex3f(100, -5, 60);
    glVertex3f(100, -5, -100);
    glVertex3f(100, 100, -100);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-100, 100, 60);
    glVertex3f(-100, -5, 60);
    glVertex3f(-100, -5, -100);
    glVertex3f(-100, 100, -100);
    glEnd();
}
