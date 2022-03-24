#pragma GCC diagnostic ignored "-Wdeprecated-declarations" // Xcode: ignore deprecated warning

#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <vector>
#include <math.h>


struct pt { double x; double y; };
int width = 500, height = 500;
int arrowIdx = 0;
double PI = 3.14159265;
std::vector<pt> pts;

void DrawObject() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    /*glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0);
    glVertex2f(-1, 0);
    glVertex2f(-0.5, 1);
    glEnd();*/


//    glColor3f(1, 1, 0);
//    glBegin(GL_POLYGON);
//    glVertex2f(0, 0);
//    glVertex2f(1, 0);
//    glVertex2f(1, 1);
//    glVertex2f(0, 1);
//    glEnd();



//    int max = 100;
//    float radius = 0.5;
//
//    glColor3f(0, 1, 0);
//    glBegin(GL_POLYGON);
//    for (int i = 0; i <= max; i++) {
//        double theta = PI * 2.0 * double(i) / double(max);
//        auto x = radius * cos(theta);
//        auto y = radius * sin(theta);
//        glVertex2d(x, y);
//    }
//    glEnd();


    
    glPointSize(5);
    glColor3f(0, 1, 1);
    glBegin(GL_POINTS);
    for (int i = 0; i < pts.size(); i++) {
        glVertex2d(pts[i].x, pts[i].y);
    }
    for (auto& p : pts)
        glVertex2f(p.x, p.y);
    glEnd();
    
    glutSwapBuffers();
    glFlush();

    /*glLoadIdentity();
    glColor3f(1, 0, 0);
    glutWireTeapot(0.3);

    glTranslatef(0.5, 0, 0);
    glRotatef(arrowIdx, 0, 0, 1);
    DrawAxis();
    glLineWidth(1.0);
    glColor3f(0, 0, 1);
    glutWireTeapot(0.3);

    glRotatef(arrowIdx, 0, 0, 1);
    glTranslatef(0.5, 0, 0);
    DrawAxis();
    glLineWidth(1.0);
    glColor3f(0, 0, 1);
    glutWireTeapot(0.3);

    glutSwapBuffers();

    glLineWidth(1.0);
    glColor3f(1, 0, 0);
    glutWireTeapot(0.2);
    glTranslatef(1, 0, 0);
    glColor3f(0, 0, 1);
    glutWireTeapot(0.2);
    glutSwapBuffers();
    glEnd();
    glFlush();*/

    /*glLineWidth(3.0);
    glColor3f(0, 1, 0);
    double radius = 1.0;
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= arrowIdx; i++) {
        double theta = PI * 2.0 * double(i) / double(50);
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();
    glutSwapBuffers();*/

//    glLoadIdentity();
//    glColor3f(0, 0, 1);
//    glutWireTeapot(0.2);
//
//    glColor3f(1, 0, 0);
//    glRotatef(-45, 0, 0, 1);
//    glutWireTeapot(0.2);
//
//    glEnd();
//    glFlush();




}
void DrawAxis() {
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0, 1);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    glEnd();
}

void KeyDown(unsigned char key, int x, int y)
{
    switch (key) {
    case 'p': case 'P':
        printf("Hello world!\n");
        break;
    case 'r': case 'R':
        printf("Clear\n");
        pts.clear();
        break;
    }
    
    glutPostRedisplay();
}
void KeySpecial(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_UP:
        arrowIdx++;
        break;
    case GLUT_KEY_DOWN:
        arrowIdx--;
        break;
    }
    glutPostRedisplay();
}
void Mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        printf("Mouse Click (%d %d)\n", x, y);
    
    glutPostRedisplay();
}

void Motion(int x, int y)
{
    printf("Mouse motion (%d %d)\n", x, y);

    double xd, yd;
    xd = x / 500.0 * 4.0 - 2.0;
    yd = y / 500.0 * 4.0 - 2.0;
    yd *= -1.0;

    /*pt p;
    p.x = xd;
    p.y = yd;
    pts.push_back(p);
    */
    pts.push_back({ xd,yd });

    glutPostRedisplay();
}

void Init()
{
    glViewport(0, 0, width, height);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
}

void Timer(int value) {
    if (arrowIdx < 50)
        arrowIdx++;
    else
        arrowIdx = 0;
    glutTimerFunc(30, Timer, 1);
}

int main(int argc, char** argv) {
    int mode = GLUT_RGB | GLUT_DOUBLE;

    glutInit(&argc, argv);
    glutInitDisplayMode(mode);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL");
    glutSetWindowTitle("DAU CG");
     
    Init();
    glutDisplayFunc(DrawObject);
    glutKeyboardFunc(KeyDown);
    glutMouseFunc(Mouse);
    glutSpecialFunc(KeySpecial);
    glutMotionFunc(Motion);
    //glutIdleFunc(DrawObject);
    //glutTimerFunc(1, Timer, 1);
    glutMainLoop();
}
