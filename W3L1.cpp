#pragma GCC diagnostic ignored "-Wdeprecated-declarations" // Xcode: ignore deprecated warning
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <vector>
#include <math.h>

struct pt { double x; double y; double z; };
int width = 500, height = 500;
int arrowIdx = 0;
double PI = 3.14159265;
double PI20 = 3.14159265 * 2.0;
std::vector<pt> pts;
void DrawAxis()
{
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glColor3f(0, 1, 0);
    glVertex2f(0, 0);
    glVertex2f(0, 1);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    glEnd();
}
void DrawCircle(double ctrX, double ctrY, double radius) {

    int res = 100;
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < res; i++)
    {
        double theta = PI * 2.0 * double(i) / double(res);
        double x = radius * cos(theta) + ctrX;
        double y = radius * sin(theta) + ctrY;
        glVertex2d(x, y);
    }
    glEnd();
}

void DrawObject() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    /* #1 색이 다른 티팟 3개를 위치를 옮겨서 그리기 */
//    glLoadIdentity();
//    glColor3f(1,0,0);
//    glutWireTeapot(0.2);
//
//    glColor3f(0,1,0);
//    glTranslatef(0.5, 0, 0);
//    glutWireTeapot(0.2);
//
//    glColor3f(0,0,1);
//    glTranslatef(0.2, 0, 0);
//    glutWireTeapot(0.2);
    
    /* #2 색이 다른 티팟 3개를 위치와 각도를 옮겨서 그리기. */
//    glLoadIdentity();
//    glColor3f(1,0,0);
//    glutWireTeapot(0.2);
//
//    glColor3f(0,1,0);
//    glTranslatef(0.5, 0, 0);
//    glRotatef(45, 0, 0, 1);
//    glutWireTeapot(0.2);
//
//    glColor3f(0,0,1);
//    glLoadIdentity();
//    glRotatef(45, 0, 0, 1);
//    glTranslatef(0.5, 0, 0);
//    glutWireTeapot(0.2);
    
    /* #3 원을 그리고, TR VS RT */
//    glLoadIdentity();
//    glColor3f(0,0,0);
//    DrawCircle(0, 0, 0.5);
//
//    glLoadIdentity();
//    glColor3f(1,0,0);
//    glutWireTeapot(0.2);
//
//    glColor3f(0,1,0);
//    glTranslatef(0.5, 0, 0);
//    glRotatef(arrowIdx, 0, 0, 1);
//    glutWireTeapot(0.2);
//
//    glColor3f(0, 0, 1);
//    glLoadIdentity();
//    glRotatef(arrowIdx, 0, 0, 1);
//    glTranslatef(0.5, 0, 0);
//    glutWireTeapot(0.2);
    
    
    
//    glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
//    pt cameraPos;
//    double value = PI20 * double(arrowIdx % 360) / 360.0;
//    printf("value %f\n", value);
//    double radius = 1.0;
//    cameraPos.x = radius * cos(value);
//    cameraPos.y = 1.0;
//    cameraPos.z = radius * sin(value);
//    gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, 0, 0, 0, 0, 1, 0);
//    DrawAxis();
//    glColor3f(0, 0, 0);
//    glLineWidth(1.0);
//    glutWireTeapot(0.2);
    glutSwapBuffers();
}

void Init()
{
    glViewport(0, 0, width, height);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void KeyDown(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'p': case 'P':
        printf("Hello world!\n");
        break;
    }

    glutPostRedisplay();
}
void KeySpecial(int key, int x, int y)
{
    switch(key)
    {
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
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
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

    glutPostRedisplay();
}

void Timer(int value)
{
    arrowIdx++;
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
    // glutIdleFunc(DrawObject);
    // glutTimerFunc(1, Timer, 1);
    glutMainLoop();
}
