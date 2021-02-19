////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
// hw2.cpp
// 
// Offical Name: Arvin Lin
// 
// E-Mail: alin11@syr.edu
// 
// Assignment: Assignment 2
// 
// Environment/Compiler: Visual Studio 2019
// 
// Date: February 17, 2020
// 
// References: windows.cpp, menus.cpp, RGB website for color: https://www.rapidtables.com/web/color/RGB_Color.html
// 
// Description: This program has radio buttons and check boxes where if you click on them the shape or object would appear.
//              The radio button can only be selected on at a time whereas the check boxes could be selected multiple times. 
//
// KeyBoard Interactions:
// Press ESC to exit out of the windows. 
// Press 1 to toggle the toy if the menu option (for toy) button does not work.
// Press 4 to toggle the paper if the menu option (for paper) button or 
// the check box for white paper does not work.  
// Press 5 to toggle the tea pot if the check box for tea pot does not work.
// Press 6 to toggle the mug/cup if the check box for cup/mug does not work. 
// Press 8 to toggle the pencil if the check box for the pen/pencil does not work.
// Press q to make the round table appear which is also the default table. if the radio button does not work.
// Press w to make the pentagon table appear if the radio button does not work. 
// Press e to make the square table appear if the radio button does not work. 
//
// Click left button on the mouse when clicking on the radio button and check boxes
// Click right button on the mouse to have the menu to appear, and clicking on each section would lead you to a submenus 
//          1. Color of mug Sub Menu: blue, red, black
//          2. Change option Sub Menu: toy, paper 
//          3. Quit : exit out of both window display
// 
//If you check the teapot, white paper, cup, and a choice of desk shape then 
//it would look like a person is on a desk that is on a desk facing to the right.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265

using namespace std;


//global variables 

//Radio button
//Kathleen, the TA, helped me understand what #define ... meant  
#define ROUND 1
#define PENTA 2
#define SQU 3

#define BLUEMUG 5
#define REDMUG 6
#define BLAMUG 7

#define PAP 4
#define OPT 8

#define ROTATE0 1
#define ROTATE270 2

float mugRedParameter = 0.0;
float mugGreenParameter = 25.5;
float mugBlueParameter = 25.5;


static int id1, id2; //window identifiers 

//Ratio 
float width = 100.0;
float height = 100.0;

float xLeft = -width / 2;
float xRight = -xLeft;
float yTop = height/2;
float yBottom = -yTop;
float zNear = 10.0;
float zFar = 80.0;

float height2;


//Submenu options 
int mugColorSubmenu;
int optTypeSubmenu;
//int pencilAngleSubmenu;

//inital radio button
int SeltableShape = ROUND;


//Check Box 
bool tea = false; 
bool mug = false;
bool paper = false;
bool pencil = false;
//bool liquid = false;
bool food = false; 
bool toy = false;



void radioButton() {

    //Filled Circle 
    switch (SeltableShape) {
    case ROUND:
        glColor3f(0.0, 0.0, 0.0);
        float degree;
        int y;
        glBegin(GL_POLYGON);
        {
            for (y = 0; y < 30; ++y)
            {
                degree = 2 * PI * y / 30;
                glVertex2f(100.0 + cos(degree) * 25.0, 425.0 + sin(degree) * 25.0);
            }
        }
        glEnd();
        break;

    case PENTA: 
        glColor3f(0.0, 0.0, 0.0);
        float degre;
        int x;
        glBegin(GL_POLYGON);
        {
            for (x = 0; x < 30; ++x)
            {
                degre = 2 * PI * x / 30;
                glVertex2f(100.0 + cos(degre) * 25.0, 365.0 + sin(degre) * 25.0);
            }
        }
        glEnd();
        break;

    case SQU: 
        glColor3f(0.0, 0.0, 0.0);
        float degr;
        int c;
        glBegin(GL_POLYGON);
        {
            for (c = 0; c < 30; ++c)
            {
                degr = 2 * PI * c / 30;
                glVertex2f(100.0 + cos(degr) * 25.0, 305.0 + sin(degr) * 25.0);
            }
        }
        glEnd();
        break;
    default:
        break;
    }
    
}



void xInBox() {
    // the x for box 1 
    if (tea) {

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(325.0, 450.0, 0.0); //top right
        glVertex3f(275.0, 400.0, 0.0); //top left
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(325.0, 400.0, 0.0); //bottom left
        glVertex3f(275.0, 450.0, 0.0); //bottom right 
        glEnd();
    }
    // the x for box 2
    if (mug) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(325.0, 350.0, 0.0); //top right
        glVertex3f(275.0, 300.0, 0.0); //top left

        glVertex3f(275.0, 350.0, 0.0); //bottom left
        glVertex3f(325.0, 300.0, 0.0); //bottom right 
        glEnd();
    }
    
    // the x for box 3
    if (paper) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(325.0, 250.0, 0.0); //top right
        glVertex3f(275.0, 200.0, 0.0); //top left

        glVertex3f(275.0, 250.0, 0.0); //bottom left
        glVertex3f(325.0, 200.0, 0.0); //bottom right 
        glEnd();
    }
    // the x for box 4 
    if (pencil) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(325.0, 150.0, 0.0); //top right
        glVertex3f(275.0, 100.0, 0.0); //top left

        glVertex3f(275.0, 150.0, 0.0); //bottom left
        glVertex3f(325.0, 100.0, 0.0); //bottom right 
        glEnd();
    }
}

void writeBitmapString(void* font, const char* string)
{
    const char* c;
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

//First window 
void DisplayPan(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Non-square aspect ratio squashes the square
    glFrustum(xLeft, xRight, yTop, yBottom, zNear, zFar);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // A red table
    switch (SeltableShape) {
    case SQU:
        glPushMatrix();
        glColor3ub(96.0, 96.0, 96.0);
        glTranslatef(0.0, 0.0, -20);
        // glScalef(1.5, 1.5, -10.0);
        glutSolidCube(70.0);
        glPopMatrix();

        break;

        //Oval Table
    case ROUND:
            glPushMatrix();
            glColor3ub(255.0, 204.0, 153.0);
            glTranslatef(0.0, 0.0, -20.0);
            glutSolidSphere(35.0, 100.0, 100.0);
            glPopMatrix();

            break;

        //Pentagon Table
    case PENTA: 
            glPushMatrix();
            glColor3ub(255.0, 102.0, 102.0);
            glTranslatef(0.0, 0.0, -20.0);
            glutSolidSphere(40.0, 5.0, 5.0);
            glPopMatrix();

            break;
    default:
        break;

    }
    //Green teaPot
    if (tea) {
        glPushMatrix();
        glColor3f(0.0, 0.20, 0.0);
        glTranslatef(0.0, 0.0, -15.0);
       // glRotatef()
        glRotatef(90.0, 150.0, 20.0, -30.0);
        glutSolidTeapot(15.0);
        glPopMatrix();
    }

    //Paper
    if (paper) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(10.0, 0.0, -25.0);
        glutSolidCube(20.0);
        glPopMatrix();
    }
    //toy
    if (toy) {

        glPushMatrix();

        glPushMatrix();
        glColor3f(0.0, -5.0, 1.0);
        glTranslatef(0.0, 0.0, -10.0);
        glutSolidSphere(3.5, 10, 10);
        glPopMatrix();
        //body
        glPushMatrix();
        glColor3f(0.0, 1.0, 1.0);
        glTranslatef(10.0, 0.0, -10.0);
        glutWireCube(15.0);
        glPopMatrix();
        glPopMatrix();
    }

    if (pencil) {
        //glPushMatrix();
        glPushMatrix();
        glTranslatef(-20.0, -20.0, -10.0);
        //glRotatef(0.0, 1.0, 0.0, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glColor3ub(153.0, 76.0, 0.0);
        glutSolidCone(2.5, 10.0, 15.0, 15.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-20.0, -15.0, -10.0);
        glColor3ub(255.0, 204.0, 204.0);
        //glRotatef(-90.0, 1.0, 0.0, 0.0);
        glScalef(1.0, 2.0, 1.0);
        glutSolidCube(4.5);
        glPopMatrix();

        glPushMatrix();
        glColor3ub(255.0, 204.0, 204.0);
        glTranslatef(-20, -10.0, -10);
        glutSolidSphere(3.0, 10, 10);
        glPopMatrix();
    }

    //cup
    if (mug) {
        glPushMatrix();
        glTranslatef(20.0, 5.0, 25.0);
        glPushMatrix();
        glColor3ub(mugRedParameter, mugGreenParameter, mugBlueParameter);
        //glTranslatef(1.0, 1.0, -10.0);
        glScalef(1.5, 1.5, -10);
        
        glutWireCone(10.0,5.0,10.0, 10.0);
        glPopMatrix();
    }


    glFlush();
}

void controlPan(void)
{

	glutSetWindow(id2);

	glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Non-square aspect ratio squashes the square
    glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // circle outlines
    glColor3f(0.0, 0.0, 0.0);
    float angle;
    int i;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(100.0 + cos(angle) * 25.0, 425.0 + sin(angle) * 25.0);
    }
    //glutSolidSphere(0.5, 15.0, 15.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    float angl;
    int j;

    glBegin(GL_LINE_LOOP);
    {
        for (j = 0; j < 30; ++j)
        {
            angl = 2 * PI * j / 30;
            glVertex2f(100.0 + cos(angl) * 25.0, 365.0 + sin(angl) * 25.0);
        }
    }
    glEnd();

    
    glColor3f(0.0, 0.0, 0.0);
    float ang;
    int n;

    glBegin(GL_LINE_LOOP);
    {
        for (n = 0; n < 30; ++n)
        {
            ang = 2 * PI * n / 30;
            glVertex2f(100.0 + cos(ang) * 25.0, 305.0 + sin(ang) * 25.0);
        }
    }
    glEnd();

    // A black square
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(325.0, 450.0, 0.0); //top right
    glVertex3f(275.0, 450.0, 0.0); //top left
    glVertex3f(275.0, 400.0, 0.0); //bottom left
    glVertex3f(325.0, 400.0, 0.0); //bottom right 
    glEnd();

   glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(325.0, 350.0, 0.0); //top right
    glVertex3f(275.0, 350.0, 0.0); //top left
    glVertex3f(275.0, 300.0, 0.0); //bottom left
    glVertex3f(325.0, 300.0, 0.0); //bottom right 
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(325.0, 250.0, 0.0); //top right
    glVertex3f(275.0, 250.0, 0.0); //top left
    glVertex3f(275.0, 200.0, 0.0); //bottom left
    glVertex3f(325.0, 200.0, 0.0); //bottom right 
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(325.0, 150.0, 0.0); //top right
    glVertex3f(275.0, 150.0, 0.0); //top left
    glVertex3f(275.0, 100.0, 0.0); //bottom left
    glVertex3f(325.0, 100.0, 0.0); //bottom right 
    glEnd(); 
    
    xInBox();
    radioButton();

    //label for radio buttons

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(50.0, 455.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Desk/Table");
    glutSwapBuffers();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(130.0, 415.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Round");
    glutSwapBuffers();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(130.0, 355.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Pentagon");
    glutSwapBuffers();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(130.0, 295.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Square");
    glutSwapBuffers();

    //labe for check boxes 

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(265.0, 455.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Objects");
    glutSwapBuffers();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(330.0, 415.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Tea Pot");
    glutSwapBuffers();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(330.0, 315.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Cup/Mug");
    glutSwapBuffers();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(330.0, 215.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "White Paper");
    glutSwapBuffers();

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(330.0, 115.0, 0.0);
    writeBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "Pen/Pencil");
    glutSwapBuffers();

	glFlush();

}
//Kathleen helped me understand how to create menus and I referenced the menu.cpp from the required textbook 
void color_menu(int id)
{

    switch (id) {
    case BLUEMUG: mugRedParameter = 0.0; mugGreenParameter = 0.0; mugBlueParameter = 255.0; break;
    case REDMUG: mugRedParameter = 255.0; mugGreenParameter = 0.0; mugBlueParameter = 0.0; break;
    case BLAMUG: mugRedParameter = 0.0;  mugGreenParameter = 0.0; mugBlueParameter = 0.0; break;
    default:  break;
    }

    glutSetWindow(id1);
    glutPostOverlayRedisplay();

}

void pap_menu(int id)
{
    switch (id) {
    case OPT: toy = true; paper = false; break;
    case PAP: paper = true; toy = false; break;
    default: /*pencilAngleSubmenu = ROTATE0;*/ break;
    }

    glutSetWindow(id1);
    glutPostOverlayRedisplay();
}

/*void ang_menu(int id)
{

    glutSetWindow(id1);
    glutPostOverlayRedisplay();
    switch (id) {
    case ROTATE0: pencilAngleSubmenu = ROTATE0; break;
    case ROTATE270: pencilAngleSubmenu = ROTATE270; break;
    default: pencilAngleSubmenu = ROTATE0; break;
    }

    glutSetWindow(id1);
    glutPostOverlayRedisplay();

}*/

void handleQuit(int id)
{
    if (id == 9) exit(0);
}

//Menu Creation 
void Makemenu(void)
{

    mugColorSubmenu = glutCreateMenu(color_menu);
    glutAddMenuEntry("blue", BLUEMUG);
    glutAddMenuEntry("yellow", REDMUG);
    glutAddMenuEntry("black", BLAMUG);

    optTypeSubmenu = glutCreateMenu(pap_menu);
    glutAddMenuEntry("toy", OPT);
    glutAddMenuEntry("paper", PAP);

   /* pencilAngleSubmenu = glutCreateMenu(ang_menu);
    glutAddMenuEntry("0 degrees", ROTATE0);
    glutAddMenuEntry("90 degrees", ROTATE270);*/

    glutCreateMenu(handleQuit);
    glutAddSubMenu("Change Your Mug Color", mugColorSubmenu);
    //glutAddSubMenu("Rotate Your Pencil", pencilAngleSubmenu);
    glutAddSubMenu("Change Option", optTypeSubmenu);
    glutAddMenuEntry("Quit", 9);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

}



// Mouse callback routine.
void mouseinPutControl(int button, int state, int x, int y)
{
    float xClicked = x; 
    float yClicked = height2 - y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //radio button 1: Oval
        if (xClicked > 75 && xClicked < 125 && yClicked > 400 && yClicked < 450){
            SeltableShape = ROUND;
        }
        //radio button 2: Penta 
        else if (xClicked > 75 && xClicked < 125 && yClicked > 340 && yClicked < 390)
        {
            SeltableShape = PENTA;
        }

        //radio button 3: Square 
        else if (xClicked > 75 && xClicked < 125 && yClicked > 280 && yClicked < 330)
        {
            SeltableShape = SQU;
        }

        //check boxes 

        //box 1: tea
        else if (xClicked > 275 && xClicked < 325 && yClicked > 400  && yClicked < 450) {
            tea = !tea; 
        }
        //box 2: mug
        else if (xClicked > 275 && xClicked < 325 && yClicked > 300 && yClicked < 350) {
            mug = !mug; 
        }
        
        //box 3: paper
        else if (xClicked > 275 && xClicked < 325 && yClicked > 200 && yClicked < 250) {
            paper = !paper; 
        }
        //box 4: pencil
        
        else if (xClicked > 275 && xClicked < 325 && yClicked > 100 && yClicked < 150) {
            pencil = !pencil; 
        }
    }
    glutSetWindow(id1);
    glutPostRedisplay();

    glutSetWindow(id2);
    glutPostRedisplay();
}

//Initialization routine for first window
void setup1(void)
{
	//Black background 
	glClearColor(1.0, 1.0, 1.0, 0.0);

}

//Initialization routine for second window 
void setup2()
{
	//Green background 
	glClearColor(1.0, 1.0, 1.0, 0.0);

}

//Reshape routine for first window
void resize1(int w, int h)
{
	glViewport(0.0, 0.0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Non-square aspect ratio squashes the square
    glFrustum(xLeft, xRight, yTop, yBottom, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//Reshape routine for the second window 
void resize2(int w, int h)
{
	glViewport(0.0, 0.0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Non-square aspect ratio squashes the square
	glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);
    height2 = h;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine shared by both windows.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case '1':
        toy = !toy;
        break;
    case '4':
        paper = !paper;
        break;
    case '5': 
        tea = !tea;
        break;
    case '6': 
        mug = !mug;
        break;
    case '8':
        pencil = !pencil;
        break;

    case 'q':
        SeltableShape = ROUND;
        break;
    case 'w':
        SeltableShape = PENTA;
        break;
    case 'e':
        SeltableShape = SQU;
        break;
    default:
        break;
    }

    glutSetWindow(id1);
    glutPostRedisplay();

    glutSetWindow(id2);
    glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    cout << " " << endl;
    cout << "KeyBorad Interactions:" << endl;
    cout << "Press ESC to exit out of the windows." << endl;
    cout << "Press 1 to toggle the toy if the menu option (for toy) button does not work." << endl;
    cout << "Press 4 to toggle the paper if the menu option (for paper) button or the check box for white paper does not work." << endl;
    cout << "Press 5 to toggle the tea pot if the check box for tea pot does not work." << endl;
    cout << "Press 6 to toggle the mug/cup if the check box for cup/mug does not work." << endl;
    cout << "Press 8 to toggle the pencil if the check box for the pen/pencil does not work." << endl;
    cout << "Press q to make the round table appear which is also the default table. If the radio button does not work." << endl;
    cout << "Press w to make the pentagon table appear if the radio button does not work. " << endl;
    cout << "Press e to make the square table appear if the radio button does not work." << endl;
    cout << " " << endl;
    cout << "Click left button on the mouse when clicking on the radio button and check boxes." << endl;
    cout << "Click right button on the mouse to have the menu to appear, and clicking on each section would lead you to a submenus." << endl;
    cout << "           1. Color of mug Sub Menu: blue, red, black" << endl;
    cout << "           2. Change option Sub Menu: toy, paper " << endl;
    cout << "           3. Quit : exit out of both window display " << endl;
    cout << " " << endl;
    cout << "If you check the teapot, white paper, cup, and a choice of desk shape then it would look like a person is on a desk that is on a desk facing to the right." << endl;
}
      

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    // First top-level window definition.
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    // Create the first window and return id.
    id1 = glutCreateWindow("Display Window");

    // Initialization, display, and other routines of the first window. 
    setup1();
    glutDisplayFunc(DisplayPan);
    glutReshapeFunc(resize1);
    glutKeyboardFunc(keyInput); // Routine is shared by both windows.

    Makemenu();

    // Second top-level window definition.
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(700, 100);

    // Create the second window and return id.
    id2 = glutCreateWindow("Control Window");

    // Initialization, display, and other routines of the second window. 
    setup2();
    glutDisplayFunc(controlPan);
    glutReshapeFunc(resize2);
    glutKeyboardFunc(keyInput); // Routine is shared by both windows.
    glutMouseFunc(mouseinPutControl);

    glutMainLoop();

    return 0;
}
