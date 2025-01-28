#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "glutil.h"


bool getdown = false;
bool rocketmoving1 = false;
bool startRotation = false;
bool launchRocket =false;
bool toggleDayNight = false;
bool creatingRocket = false;
float earthAngle = 0.0f;
int rotationCount = 0;
const int maxRotations = 3;
bool crotation = false;
bool crotation2 = false;
float angle = 0.0f;
float scale_factor = 1.0f;  // Initial scaling factor
bool zoom_in = true;        // Direction of scaling
bool isday = true;
bool rocketBuilt = false;
bool wingsBuilt = false;
float rocketHeight = -10.4685f;
float rocketPosY = 0.0f;
float rocketPosY2 = 0.0f;
float rocketPosY3 = 0.0f;
float rocketPosX1 = 0.0f;
float rocketPosX = 0.0f;
float rocketSpeed = 0.1f;
const float maxRocketHeight = -3.949435772322f;
const float Rocketanimantionspeed = 0.05f;
float carPosX = 0.0f;
float carSpeed = 0.1f;
float boatspeed = 0.1f;
float boatPosX = 0.0f;
float wheelRotation = 0.0f;
int currentLine = 0;

//an1
void earthSpinningTop(int value) {
    // Increase the rotation angle for Earth
    earthAngle += 0.5f; // Adjust the rotation speed as needed

    // Ensure the angle stays within 360 degrees
    if (earthAngle >= 360.0f)
        earthAngle -= 360.0f;

    // Request redisplay to update the window
    glutPostRedisplay();

    // Call the function again after a certain interval (e.g., 16 milliseconds)
    glutTimerFunc(16, earthSpinningTop, 0);
}

//an2
void glutSolidSphereWithTexture(GLdouble radius, GLint slices, GLint stacks) {
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE); // Enable texture coordinates

    gluSphere(quadric, radius, slices, stacks);

    gluDeleteQuadric(quadric);
}

void circle(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(xc, yc);
    for (int i = 0; i <= 200; ++i) {
        float angle = i * 2.0f * M_PI / 200.0f;
        float x = xc + (radius * cos(angle));
        float y = yc + (radius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
}
void circle1(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(xc, yc);
    for (int i = 0; i <= 200; ++i) {
        float angle = i * 2.0f * M_PI / 200.0f;
        float x = xc + (radius * cos(angle));
        float y = yc + (radius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
}

void Semicircle(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(xc, yc);
    for (int i = 0; i <= 100; ++i) {
        float angle = i * 2.0f * M_PI / 200.0f;
        float x = xc + (radius * cos(angle));
        float y = yc + (radius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
}
//an3
void scaletimer(int value) {
    // Update scaling factor for animation
    if (zoom_in) {
        scale_factor += 0.01f; // Increase scaling factor
        if (scale_factor > 1.0f)
            zoom_in = false;  // Change direction if reached max scale
    } else {
        scale_factor -= 0.01f; // Decrease scaling factor
        if (scale_factor < 0.97f)
            zoom_in = true;   // Change direction if reached min scale
    }

    glutPostRedisplay(); // Request a redraw to create animation
    glutTimerFunc(20, scaletimer, 0); // Call timer function again
}

void Day() { //22-47046-1--obj1
glBegin(GL_POLYGON); //SKY
glColor3ub(166,231,255);
glVertex2f(-20, 12);
glVertex2f(-20,25);
glVertex2f(25,25);
glVertex2f(25,12);

glEnd();

circle(2.5,18,20,255,255,0); // SUN

}

void Night() { //22-47046-1--obj2


glBegin(GL_POLYGON); //SKY
glColor3ub(15,15,15);
glVertex2f(-20, 12);
glVertex2f(-20,25);
glVertex2f(25,25);
glVertex2f(25,12);

glEnd();

circle(2.5,18,20,255,255,255); // SUN

}

void Garage(){   //22-47046-1--obj3
// Garage Part Starts


glBegin(GL_POLYGON);
glColor3ub(145,163,176);
glVertex2f(-8,4);
glVertex2f(-10,2);
glVertex2f(-10, -2);
glVertex2f(-5.2304140151632f, -1.9886193972448f);
glVertex2f(-3.4539424070083f, 1.9318898841187f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(6,42,120);
glVertex2f(-8,4);
glVertex2f(-5.6f, 4);
glVertex2f(-3.5f, 2);
glVertex2f(-5.2f, 2);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(145,163,176);
glVertex2f(-3.5f, 2);
glVertex2f(-5.2f, 2);
glVertex2f(-5.2f, -2);
glVertex2f(-3.5f, -2);
glEnd();


glBegin(GL_LINES);
glLineWidth(0.1);
glColor3ub(0,0,0);
glVertex2f(-5.2f, 2);
glVertex2f(-5.2f,-2);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(240,234,214); // Main garage
glVertex2f(-9.5f, 1);
glVertex2f(-9.5f, -2);
glVertex2f(-6, -2);
glVertex2f(-6.0f, 1);
glEnd();


glBegin(GL_LINES);
glLineWidth(1);
glColor3ub(0,0,0);
glVertex2f(-9.5f, 0.4f);
glVertex2f(-6, 0.4f);
glEnd();

glBegin(GL_LINES);
glLineWidth(1);
glColor3ub(0,0,0);
glVertex2f(-9.5f, -0.2f);
glVertex2f(-6, -0.2f);
glEnd();

glBegin(GL_LINES);
glLineWidth(1);
glColor3ub(0,0,0);
glVertex2f(-9.5f, -0.8f);
glVertex2f(-6, -0.8f);
glEnd();

glBegin(GL_LINES);
glLineWidth(1);
glColor3ub(0,0,0);
glVertex2f(-9.5f, -1.4f);
glVertex2f(-6, -1.4f);
glEnd();

glBegin(GL_LINES);
glLineWidth(1);
glColor3ub(0,0,0);
glVertex2f(-9.5f, -1.8f);
glVertex2f(-6, -1.8f);
glEnd();

glBegin(GL_LINES);
glLineWidth(1);
glColor3ub(0,0,0);
glVertex2f(-10, 2);
glVertex2f(-8, 4);
glEnd();

glBegin(GL_LINES);
glLineWidth(1);
glColor3ub(0,0,0);
glVertex2f(-4.7844518f,3.2065428f);
glVertex2f(-3.5, 2);
glEnd();

glBegin(GL_LINES);
glLineWidth(1);
glColor3ub(0,0,0);
glVertex2f(-3.5, -2);
glVertex2f(-3.5, 2);
glEnd();

//Garage ends

}

void House() {  //22-47046-1--obj4

glBegin(GL_POLYGON);
glColor3ub(145,163,176);
glVertex2f(-9.6039066466298f, 1.9318898841187f);
glVertex2f(-9.6039066466298f, 3.965083467029f);
glVertex2f(-6.7610504608708f, 7.5061335809379f);
glVertex2f(-3.675746f, 3.2065428f);
glVertex2f(-4.7844518f,3.2065428f);
glVertex2f(-5.6f, 4);
glVertex2f(-8, 4);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(6,42,120);
glVertex2f(-6.7610504608708f, 7.5061335809379f);
glVertex2f(-3.675746f, 3);
glVertex2f(10,3);
glVertex2f(7.7977736419344f, 7.5061335809379f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(145,163,176);
glVertex2f(10,3);
glVertex2f(-4.7844518f,3.2065428f);
glVertex2f(-3.5f, -2);
glVertex2f(10,-2);
glEnd();


glBegin(GL_POLYGON);      // window1
glColor3ub(50,20,20);
glVertex2f(-2.5, 2);
glVertex2f(0,2);
glVertex2f(0,0.5f);
glVertex2f(-2.5, 0.5);
glEnd();


glBegin(GL_POLYGON);      // window2
glColor3ub(50,20,20);
glVertex2f(6.5, 2);
glVertex2f(8.8557287034044f, 1.9949924520701f);
glVertex2f(8.8557287034044f, 0.4823369847152f);
glVertex2f(6.5, 0.5);
glEnd();


glBegin(GL_POLYGON);      // Gate
glColor3ub(160,82,45);
glVertex2f(2, 0);
glVertex2f(5.6055043426386f,0);
glVertex2f(5.6055043426386f, -2);
glVertex2f(2,-2);
glEnd();


Garage();
}
void Tree() {   // 22-47046-1

//bushes   //22-47046-1--obj5

Semicircle(1.5,-13.8,-2,167,252,0);
Semicircle(1.5,-12.0,-2,167,252,0);
Semicircle(1.5,-11.2,-1.5,167,252,0);
Semicircle(1.5,-10.2,-2,167,252,0);


Semicircle(1.5,-20,-2,167,252,0);
Semicircle(1.5,-18,-2,167,252,0);
Semicircle(1.5,-17.5,-1.5,167,252,0);
Semicircle(1.5,-15,-2,167,252,0);

// Tree //22-47046-1--obj6
glBegin(GL_POLYGON);
glColor3ub(100,65,23);
glVertex2f(-14.796259371581f, 4.0014701389271f);
glVertex2f(-14.796259371581f, -1.9770281098655f);
glVertex2f(-13.566428463327f, -1.9770281098655f);
glVertex2f(-13.566428463327f, 4.0014701389271f);
glEnd();

circle(1.5,-14.8,5,167,252,0);
circle(1.5,-14.0,6,167,252,0);
circle(1.5,-13.2,5,167,252,0);


}

void Wall() {   //22-47046-1--obj7

glBegin(GL_POLYGON);
glColor3ub(27,27,27);
glVertex2f(10, 3);
glVertex2f(10, -2);
glVertex2f(25,-2);
glVertex2f(25,3);
glEnd();

}
void River() {    //22-47046-1--obj8

glBegin(GL_POLYGON);
glColor3ub(0,183,235);
glVertex2f(25, -2);
glVertex2f(-20, -2);
glVertex2f(-20, 12);
glVertex2f(25,12);
glEnd();
}

void Hill() { //22-47046-1--obj9


glBegin(GL_POLYGON);
glColor3ub(131,137,150);
glVertex2f(-20, 12);
glVertex2f(-11.2604804796804f, 19.9713907699976f);
glVertex2f(-5.067125,12);
glEnd();

//Bush
Semicircle(2,1.5,12,167,252,0);
Semicircle(2,4.5,12,167,252,0);

glBegin(GL_POLYGON);
glColor3ub(131,137,150);
glVertex2f(-12, 12);
glVertex2f(-3.25791f, 18);
glVertex2f(1.5f,12);
glEnd();

//Bush
Semicircle(2,11.5,12,167,252,0);
Semicircle(2,13.5,12,167,252,0);

glBegin(GL_TRIANGLES);
glColor3ub(131,137,150);
glVertex2f(4.0f, 12);
glVertex2f(6.557f, 18);
glVertex2f(11.5f,12);

glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(131,137,150);
glVertex2f(15.0f, 12);
glVertex2f(22.2969297704116f, 16.7703659448696f);
glVertex2f(25,12);

glEnd();


}

void Road() { //22-47046-1--obj10

glBegin(GL_POLYGON); //Grass
glColor3ub(50,205,50);
glVertex2f(-20,-2);
glVertex2f(-20,-14);
glVertex2f(25,-14);
glVertex2f(25,-2);

glEnd();

glBegin(GL_POLYGON); //miniroad
glColor3ub(220,220,220);
glVertex2f(-10,-2);
glVertex2f(-10,-14);
glVertex2f(-5,-14);
glVertex2f(-5,-2);

glEnd();

glBegin(GL_POLYGON); //miniroad
glColor3ub(220,220,220);
glVertex2f(2,-2);
glVertex2f(5.6f,-2);
glVertex2f(5.6,-14);
glVertex2f(2,-14);

glEnd();

//22-47046-1--obj11
glBegin(GL_POLYGON); //main road
glColor3ub(36,33,36);
glVertex2f(-20,-14);
glVertex2f(-20,-20);
glVertex2f(25,-20);
glVertex2f(25,-14);

glEnd();

glBegin(GL_LINES); //Strip
glColor3ub(255,255,255);
glVertex2f(25,-17);
glVertex2f(-20,-17);
glEnd();

}

void Car()  //22-47046-1—obj12
{
    glBegin(GL_POLYGON);
    glColor3ub(255, 69, 0);
    glVertex2f(carPosX+(-14.2727073741446f), -16.7477613714875f);
    glVertex2f(carPosX+(-14), -16);
    glVertex2f(carPosX+(-9.0752305720388f), -15.9960601811003f);
    glVertex2f(carPosX+-8.6068339023256f, -16.7715154603116f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 128);
    glVertex2f(carPosX+-10.5029026110443f, -16.0886128404426f);
    glVertex2f(carPosX+-10.6227472158393f, -16.6513614194799f);
    glVertex2f(carPosX+-9.3380498347768f, -16.6614399435985f);
    glVertex2f(carPosX+-9.2471395781923f, -16.1094553804069f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 128);
    glVertex2f(carPosX+-13.1749678459186f, -16.1110623600331f);
    glVertex2f(carPosX+-13.2727073741446f, -16.6677613714875f);
    glVertex2f(carPosX+-11.7832988131889f, -16.6693024805066f);
    glVertex2f(carPosX+-11.7430337389231f, -16.1198766503891f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(carPosX+(-14.2727073741446f), -16.7477613714875f);
    glVertex2f(carPosX+ -14.8338097908084f, -17.7943679843564f);
    glVertex2f(carPosX+-7.8095566538295f, -17.8072093977695f);
    glVertex2f(carPosX+-8.6068339023256f, -16.771515460311f);
    glEnd();



    circle(0.7, carPosX +-13, -18, 0, 0, 0);
    circle(0.5, carPosX +-13, -18, 255, 255, 255);
    circle(0.7, carPosX +-9, -18, 0, 0, 0);
    circle(0.5, carPosX +-9, -18, 255, 255, 255);




    glPushMatrix();
    glTranslatef(carPosX + -13, -18, 0);
    glRotatef(-wheelRotation, 0.0f, 0.0f, 1.0f);
    circle1(.7, 0, 0, 0, 0, 0);
    circle1(.5, 0, 0, 1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(carPosX + -9, -18, 0);
    glRotatef(-wheelRotation, 0.0f, 0.0f, 1.0f);
    circle1(.7, 0, 0, 0, 0, 0);
    circle1(.5, 0, 0, 1, 1, 1);
    glPopMatrix();

}
//an4
void carupdate(int value) {
    carPosX += carSpeed;
    wheelRotation -= 10.0f;
    if (carPosX > 40.0f) {
        carPosX = -18.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, carupdate, 0);
}



void Boat() {   //22-47046-1—obj13

glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(boatPosX+14,8);
    glVertex2f(boatPosX+16, 6);
    glVertex2f(boatPosX+22, 6);
    glVertex2f(boatPosX+24, 8);
    glEnd();


    glPushMatrix();
    glTranslatef(boatPosX + -13, -18, 0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(boatPosX + -13, -18, 0);
    glPopMatrix();
}
//an5
void boatupdate(int value) {
  boatPosX -= boatspeed;
  if (boatPosX < -40.0f) {
    boatPosX = 30.0f;
  }
  glutPostRedisplay();
  glutTimerFunc(20, boatupdate, 0);
}


void Human() { //22-47046-1

// Human1
//22-47046-1—obj14
     glBegin(GL_POLYGON); //pant
    glColor3ub(255, 69, 0);
    glVertex2f(-8, -7.3524f);
    glVertex2f(-8, -10);
    glVertex2f(-7.3420334194441f, -9.99408963069933f);
    glVertex2f(-7.3327756698981f, -8.0497196127579f);
    glVertex2f(-6.7886759387922f, -8.0497196127579f);
    glVertex2f(-6.8f, -10);
    glVertex2f(-6.2757095151221f, -10.0062069477938f);
    glVertex2f(-6.2757095151221f, -7.3524f);
    glEnd();
//22-47046-1—obj15
    glBegin(GL_POLYGON); //Shirt
    glColor3ub(255,196,12);
    glVertex2f(-8,-6);
    glVertex2f(-8, -7.3524f);
    glVertex2f(-6.2757095151221f, -7.3524f);
    glVertex2f(-6.2757095151221f, -5.985751f);

    glEnd();
//22-47046-1—obj16
    glBegin(GL_POLYGON); //Hand1
    glColor3ub(250,235,215);
     glVertex2f(-8,-6);
    glVertex2f(-8.8447362660842f, -7.504985364287f);
    glVertex2f(-8.5934520833823f, -7.6769166471883f);
    glVertex2f(-8,-6.539525f);
    glEnd();

//22-47046-1—obj17
    glBegin(GL_POLYGON); //Hand2
    glColor3ub(250,235,215);
    glVertex2f(-6.2728f,-5.98575f);
    glVertex2f(-6.272899f,-6.42049f);
    glVertex2f(-5.6177183408601f, -7.3198285980856f);
    glVertex2f(-5.4727829440348f, -7.137529570677f);
    glEnd();
//22-47046-1—obj18
    glBegin(GL_POLYGON); //Neck
    glColor3ub(250,235,215);
    glVertex2f(-7.4134085854856f, -5.693248979122f);
    glVertex2f(-7.02014f,-5.668929f);
    glVertex2f(-7.00068f,-5.99175f);
    glVertex2f(-7.4134085854856f,-5.99175f);
    glEnd();

    circle(.7,-7.24f,-5.0475f,255,255,255);



   // Human2

   //22-47046-1—obj19
    glBegin(GL_POLYGON); //pant
    glColor3ub(255, 69, 0);
    glVertex2f(-3, -7.3524f);
    glVertex2f(-3, -10);
    glVertex2f(-2.3420334194441f, -9.99408963069933f);
    glVertex2f(-2.3327756698981f, -8.0497196127579f);
    glVertex2f(-1.7886759387922f, -8.0497196127579f);
    glVertex2f(-1.8f, -10);
    glVertex2f(-1.2757095151221f, -10.0062069477938f);
    glVertex2f(-1.2757095151221f, -7.3524f);
glEnd();

glBegin(GL_POLYGON); //Shirt
    glColor3ub(2,0,255);
    glVertex2f(-3,-6);
    glVertex2f(-3, -7.3524f);
    glVertex2f(-1.2757095151221f, -7.3524f);
    glVertex2f(-1.2757095151221f, -5.985751f);
glEnd();

glBegin(GL_POLYGON); //Hand1
    glColor3ub(250,235,215);
    glVertex2f(-3,-6);
    glVertex2f(-3.8447362660842f, -7.504985364287f);
    glVertex2f(-3.5934520833823f, -7.6769166471883f);
    glVertex2f(-3,-6.539525f);
glEnd();

glBegin(GL_POLYGON); //Hand2
    glColor3ub(250,235,215);
    glVertex2f(-1.2728f,-5.98575f);
    glVertex2f(-1.272899f,-6.42049f);
    glVertex2f(-0.6177183408601f, -7.3198285980856f);
    glVertex2f(-0.4727829440348f, -7.137529570677f);
glEnd();

glBegin(GL_POLYGON); //Neck
    glColor3ub(250,235,215);
    glVertex2f(-2.4134085854856f, -5.693248979122f);
    glVertex2f(-2.02014f,-5.668929f);
    glVertex2f(-2.00068f,-5.99175f);
    glVertex2f(-2.4134085854856f,-5.99175f);
glEnd();

circle(0.7,-2.24f,-5.0475f,255,255,255);


}

const char *conversation[] = { //22-47046-1
    "Friend 1: Hey, have you ever thought about time travel?",
    "Friend 2: Oh, definitely! It's such a mind-bending concept",
    "Friend 1: Yeah ! Do you know it is very Possible",
    "Friend 2: You must be kidding Right !",
    "Friend 1: No ! Einstein has proven it with his Theory",
    "Friend 2: I never heard about it",
    "Friend 1: If an Object Travel with the speed of light it is possible",
    "Friend 2: But, It is not possible to achieve speed of light",
    "Friend 1: well, If we rotate surrounding close to blackhole it is possible",
    "Friend 2: I always wants to know how future would look",
    "Friend 1: Let's then Start building a Rocket",
    "Friend 2: Okay Cool . Let's do it",
};


void Text(float x, float y, const char *string) { //22-47046-1
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(x, y);
for (const char *c = string; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
 }
//an6
void Textupdate(int value) { //22-47046-1
     currentLine++;
    if (currentLine >= sizeof(conversation) / sizeof(conversation[0])) {
        currentLine = 0;
    } else {
        glutTimerFunc(2000, Textupdate, 0);
    }
}

//22-47046-1—obj20
void rocket() { //22-47046-1


    // Draw LaunchPad
    glBegin(GL_QUADS);
    glColor3ub(249,255,227);
    glVertex2f(13.212969653515f, -10.468533237733f);
    glVertex2f(12.2f, -12.4f);
    glVertex2f(18, -12.4f);
    glVertex2f(17.212969653515f, -10.468533237733f);

    glEnd();



    // Draw rocket body

    glBegin(GL_QUADS);
    glColor3ub(250,218,94);
    glVertex2f(14.26697f, -10.4685f);
    glVertex2f(14.26697f, rocketHeight);
    glVertex2f(16.16829f, rocketHeight);
    glVertex2f(16.16829f, -10.4685f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(245,245,245);
    glVertex2f(12.2f, -12.4f);
    glVertex2f(12.2f, -3.5f);
    glVertex2f(12, -3.5f);
    glVertex2f(12, -12.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(245,245,245);
    glVertex2f(18.2f, -12.4f);
    glVertex2f(18.2f, -3.5f);
    glVertex2f(18, -3.5f);
    glVertex2f(18, -12.4f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(245,245,245);
    glVertex2f(12.2f, -7.006417634036f);
    glVertex2f(18, -7);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(245,245,245);
    glVertex2f(12.2f, -8);
    glVertex2f(18, -8);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(245,245,245);
    glVertex2f(12.2f, -9);
    glVertex2f(18, -9);
    glEnd();


    if (wingsBuilt) {
    // Draw rocket tip
    glBegin(GL_TRIANGLES);
    glColor3ub(220,20,60); //
    glVertex2f(15.2775f, rocketHeight+ 2.0f);
    glVertex2f(14.3129f, rocketHeight);
    glVertex2f(16.1989f, rocketHeight);
    glEnd();

        // Draw bottom wing 1
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.276f, -9.36381f);
        glVertex2f(14.276f, -8.5968f);
        glVertex2f(13.3776465929047f, -9.946141079297f);
        glEnd();

        // Draw bottom wing 2
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.1606200477948f, -6.2308707437794f);
        glVertex2f(16.1933f, -5.9746f);
        glVertex2f(16.1933f, -5.4687f);
        glEnd();

        // Draw top wing 1
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.0f, -10.0f);
        glVertex2f(16.1989f, -8.5968f);
        glVertex2f(16.1989f, -9.36381f);
        glEnd();

        // Draw top wing 2
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.3044f, -6.0054f);
        glVertex2f(13.4696458871467f, -6.3428353881523f);
        glVertex2f(14.3044f, -5.45334f);
        glEnd();
    }

}

//22-47046-1—obj21
void rocket1() { //22-47046-1

    if(maxRocketHeight)  {
    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(254,39,18); // Orange color for flames
    glVertex2f(14.4f, -11.021f + rocketPosY);
    glVertex2f(15.2622557038941f, -12.7706177718086f + rocketPosY);
    glVertex2f(16.022f, -11.004 + rocketPosY);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    circle(1,15.216f ,-10.75f+rocketPosY,254,39,18);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    circle(0.8,15.216f ,-10.75f+rocketPosY,255, 165, 0);
    glPopMatrix();
    }


    // Draw rocket body
    glBegin(GL_QUADS);
    glColor3ub(250,218,94);
    glVertex2f(14.26697f, -10.4685f+ rocketPosY);
    glVertex2f(14.26697f, -4.9935124059364f+ rocketPosY);
    glVertex2f(16.16829f, -4.9935124059364f+ rocketPosY);
    glVertex2f(16.16829f, -10.4685f+ rocketPosY);
    glEnd();

    // Draw rocket tip
    glBegin(GL_TRIANGLES);
    glColor3ub(220,20,60); //
    glVertex2f(15.2775f, -4.9935124059364f+ 2.0f+ rocketPosY);
    glVertex2f(14.3129f, -4.9935124059364f+ rocketPosY);
    glVertex2f(16.1989f, -4.9935124059364f+ rocketPosY);
    glEnd();

    // Draw bottom wing 1
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.276f, -9.36381f+ rocketPosY);
        glVertex2f(14.276f, -8.5968f+ rocketPosY);
        glVertex2f(13.3776465929047f, -9.946141079297f+ rocketPosY);
        glEnd();

        // Draw bottom wing 2
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.1606200477948f, -6.2308707437794f+ rocketPosY);
        glVertex2f(16.1933f, -5.9746f+ rocketPosY);
        glVertex2f(16.1933f, -5.4687f+ rocketPosY);
        glEnd();

        // Draw top wing 1
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.0f, -10.0f+ rocketPosY);
        glVertex2f(16.1989f, -8.5968f+ rocketPosY);
        glVertex2f(16.1989f, -9.36381f+ rocketPosY);
        glEnd();

        // Draw top wing 2
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.3044f, -6.0054f + rocketPosY);
        glVertex2f(13.4696458871467f, -6.3428353881523f+ rocketPosY);
        glVertex2f(14.3044f, -5.45334f+ rocketPosY);
        glEnd();


       glEnd();

}
//22-47046-1—obj22
void rocket1Y() { //22-47046-1

    if(maxRocketHeight)  {
    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(254,39,18); // Orange color for flames
    glVertex2f(14.4f, -11.021f + rocketPosY2);
    glVertex2f(15.2622557038941f, -12.7706177718086f + rocketPosY2);
    glVertex2f(16.022f, -11.004 + rocketPosY2);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    circle(1,15.216f ,-10.75f+rocketPosY2,254,39,18);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    circle(0.8,15.216f ,-10.75f+rocketPosY2,255, 165, 0);
    glPopMatrix();
    }


    // Draw rocket body
    glBegin(GL_QUADS);
    glColor3ub(250,218,94);
    glVertex2f(14.26697f, -10.4685f+ rocketPosY2);
    glVertex2f(14.26697f, -4.9935124059364f+ rocketPosY2);
    glVertex2f(16.16829f, -4.9935124059364f+ rocketPosY2);
    glVertex2f(16.16829f, -10.4685f+ rocketPosY2);
    glEnd();

    // Draw rocket tip
    glBegin(GL_TRIANGLES);
    glColor3ub(220,20,60); //
    glVertex2f(15.2775f, -4.9935124059364f+ 2.0f+ rocketPosY2);
    glVertex2f(14.3129f, -4.9935124059364f+ rocketPosY2);
    glVertex2f(16.1989f, -4.9935124059364f+ rocketPosY2);
    glEnd();

    // Draw bottom wing 1
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.276f, -9.36381f+ rocketPosY2);
        glVertex2f(14.276f, -8.5968f+ rocketPosY2);
        glVertex2f(13.3776465929047f, -9.946141079297f+ rocketPosY2);
        glEnd();

        // Draw bottom wing 2
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.1606200477948f, -6.2308707437794f+ rocketPosY2);
        glVertex2f(16.1933f, -5.9746f+ rocketPosY2);
        glVertex2f(16.1933f, -5.4687f+ rocketPosY2);
        glEnd();

        // Draw top wing 1
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.0f, -10.0f+ rocketPosY2);
        glVertex2f(16.1989f, -8.5968f+ rocketPosY2);
        glVertex2f(16.1989f, -9.36381f+ rocketPosY2);
        glEnd();

        // Draw top wing 2
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.3044f, -6.0054f + rocketPosY2);
        glVertex2f(13.4696458871467f, -6.3428353881523f+ rocketPosY2);
        glVertex2f(14.3044f, -5.45334f+ rocketPosY2);
        glEnd();


       glEnd();

}

//22-47046-1—obj23
void rocket2() { //22-47046-1


    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(254,39,18); // Orange color for flames
    glVertex2f(14.4f+rocketPosX1, -11.021f);
    glVertex2f(15.2622557038941f+rocketPosX1, -12.7706177718086f );
    glVertex2f(16.022f+rocketPosX1, -11.004 );
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    circle(1,15.216f+rocketPosX1 ,-10.75f,254,39,18);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    circle(0.8,15.216f+rocketPosX1 ,-10.75f,255, 165, 0);
    glPopMatrix();


    // Draw rocket body
    glBegin(GL_QUADS);
    glColor3ub(250,218,94);
    glVertex2f(14.26697f+rocketPosX1, -10.4685f);
    glVertex2f(14.26697f+rocketPosX1, -4.9935124059364f);
    glVertex2f(16.16829f+rocketPosX1, -4.9935124059364f);
    glVertex2f(16.16829f+rocketPosX1, -10.4685f);
    glEnd();

    // Draw rocket tip
    glBegin(GL_TRIANGLES);
    glColor3ub(220,20,60); //
    glVertex2f(15.2775f+rocketPosX1, -4.9935124059364f+ 2.0f);
    glVertex2f(14.3129f+rocketPosX1, -4.9935124059364f);
    glVertex2f(16.1989f+rocketPosX1, -4.9935124059364f);
    glEnd();

    // Draw bottom wing 1
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.276f+rocketPosX1, -9.36381f);
        glVertex2f(14.276f+rocketPosX1, -8.5968f);
        glVertex2f(13.3776465929047f+rocketPosX1, -9.946141079297f);
        glEnd();

        // Draw bottom wing 2
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.1606200477948f+rocketPosX1, -6.2308707437794f);
        glVertex2f(16.1933f+rocketPosX1, -5.9746f);
        glVertex2f(16.1933f+rocketPosX1, -5.4687f);
        glEnd();

        // Draw top wing 1
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.0f+rocketPosX1, -10.0f);
        glVertex2f(16.1989f+rocketPosX1, -8.5968f);
        glVertex2f(16.1989f+rocketPosX1, -9.36381f);
        glEnd();

        // Draw top wing 2
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.3044f+rocketPosX1, -6.0054f  );
        glVertex2f(13.4696458871467f+rocketPosX1, -6.3428353881523f);
        glVertex2f(14.3044f+rocketPosX1, -5.45334f);
        glEnd();

}


//22-47046-1—obj24
void rocket3() { //22-47046-1


    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 0.8f);
    glScalef(1.0f, scale_factor, 0.0f);
    glTranslatef(0,rocketPosX,0);
    glBegin(GL_POLYGON);
    glColor3ub(254,39,18); // Orange color for flames
    glVertex2f(14.4f, -11.021f);
    glVertex2f(15.2622557038941f, -12.7706177718086f );
    glVertex2f(16.022f, -11.004 );
    glPopMatrix();

    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 0.8f);
    glScalef(1.0f, scale_factor, 0.0f);
    glTranslatef(0,rocketPosX,0);
    circle(1,15.216f ,-10.75f,254,39,18);
    glPopMatrix();

    glPushMatrix();

    glRotatef(angle, 0.0, 0.0, 0.8f);
    glScalef(1.0f, scale_factor, 0.0f);
    glTranslatef(0,rocketPosX,0);
    circle(0.8,15.216f ,-10.75f,255, 165, 0);
    glPopMatrix();


    // Draw rocket body

    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 0.8f);

    glTranslatef(0,rocketPosX,0);
    glBegin(GL_QUADS);
    glColor3ub(250,218,94);
    glVertex2f(14.26697f, -10.4685f);
    glVertex2f(14.26697f, -4.9935124059364f);
    glVertex2f(16.16829f, -4.9935124059364f);
    glVertex2f(16.16829f, -10.4685f);
    glEnd();
    glPopMatrix();

    // Draw rocket tip
    glPushMatrix();
    glRotatef(angle, 0.0, 0.0, 0.8f);

    glTranslatef(0,rocketPosX,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(220,20,60); //
    glVertex2f(15.2775f, -4.9935124059364f+ 2.0f);
    glVertex2f(14.3129f, -4.9935124059364f);
    glVertex2f(16.1989f, -4.9935124059364f);
    glEnd();
    glPopMatrix();

    // Draw bottom wing 1
       glPushMatrix();
        glRotatef(angle, 0.0, 0.0, 0.8f);

        glTranslatef(0,rocketPosX,0);
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.276f, -9.36381f);
        glVertex2f(14.276f, -8.5968f);
        glVertex2f(13.3776465929047f, -9.946141079297f);
        glEnd();
        glPopMatrix();

        // Draw bottom wing 2

        glPushMatrix();
        glRotatef(angle, 0.0, 0.0, 0.8f);

        glTranslatef(0,rocketPosX,0);
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.1606200477948f, -6.2308707437794f);
        glVertex2f(16.1933f, -5.9746f);
        glVertex2f(16.1933f, -5.4687f);
        glEnd();
        glPopMatrix();
        // Draw top wing 1
        glPushMatrix();
        glRotatef(angle, 0.0, 0.0, 0.8f);
        glTranslatef(0,rocketPosX,0);
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(17.0f ,-10.0f);
        glVertex2f(16.1989f, -8.5968f);
        glVertex2f(16.1989f, -9.36381f);
        glEnd();
        glPopMatrix();

        // Draw top wing 2
        glPushMatrix();
        glRotatef(angle, 0.0, 0.0, 0.8f);

        glTranslatef(0,rocketPosX,0);
        glBegin(GL_TRIANGLES);
        glColor3ub(165,42,42);
        glVertex2f(14.3044f, -6.0054f);
        glVertex2f(13.4696458871467f, -6.3428353881523f);
        glVertex2f(14.3044f, -5.45334f);
        glEnd();
        glPopMatrix();


}

//an7
void rocket1update(int value) { //22-47046-1


        rocketPosY += rocketSpeed;

        if (rocketPosY > 40.0f) {
            rocketPosY = 0.0f;
        }

    glutPostRedisplay();
    glutTimerFunc(20, rocket1update, 0);
}

//an8
void rocket2update(int value) { //22-47046-1

 if (launchRocket) {
        rocketPosY2 += rocketSpeed;

        if (rocketPosY2 > 40.0f) {
            rocketPosY2 = 0.0f;
            launchRocket = false; // Reset launch flag
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, rocket2update, 0);
}

//an9
void timeupdate(int value) { //22-47046-1


  if (rocketHeight >= maxRocketHeight) {
        return;
    }

    // Manual toggling with 't' key
    if (toggleDayNight) {
        isday = !isday;
        toggleDayNight = false; // Reset toggle after toggling
    }

    // Automatic toggling based on some condition (example: every 3 seconds)
    // You can replace this condition with your specific automatic toggling condition
    static int automaticToggleCounter = 0;
    const int automaticToggleInterval = 3000; // Interval in milliseconds
    automaticToggleCounter += 80; // Assuming this function is called every 80 milliseconds
    if (automaticToggleCounter >= automaticToggleInterval) {
        isday = !isday;
        automaticToggleCounter = 0; // Reset counter after toggling
    }

    if (isday) {
        Day();
    } else {
        Night();
    }

    glutPostRedisplay();
    glutTimerFunc(80, timeupdate, 0); // Adjust the timer interval as needed

}

//10
void rocketupdate(int value) { //22-47046-1
    if (creatingRocket) {
        if (rocketHeight < maxRocketHeight) {
            rocketHeight += Rocketanimantionspeed;
        } else {
            rocketBuilt = true;
        }

        if (rocketBuilt && !wingsBuilt) {
            wingsBuilt = true;
        }
    }

    glutTimerFunc(80, rocketupdate, 0);
}

//21-44905-2—obj1
void stars()
{
   glPushMatrix();
   glScalef(.5,.5,0);
   glBegin(GL_QUADS);
   glColor3ub(255,245,220);
   glVertex2f(-10,11);
   glVertex2f(-10,10);
   glVertex2f(-11,10);
   glVertex2f(-11,11);
   glEnd();
   glPopMatrix();
 for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i * 3.0, i * 3.0, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 255, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 216, 255); // Blue color
        else
            glColor3ub(255, 128, 128); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, 11);
        glVertex2f(-10, 10);
        glVertex2f(-11, 10);
        glVertex2f(-11, 11);
        glEnd();
        glPopMatrix();
    }


    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i * -3.0, i * -3.0, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 245, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 0, 255); // Blue color
        else
            glColor3ub(255, 0, 0); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, 11);
        glVertex2f(-10, 10);
        glVertex2f(-11, 10);
        glVertex2f(-11, 11);
        glEnd();
        glPopMatrix();
    }


    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i * -3.0, i * 3.0, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 245, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 0, 255); // Blue color
        else
            glColor3ub(255, 0, 0); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, 11);
        glVertex2f(-10, 10);
        glVertex2f(-11, 10);
        glVertex2f(-11, 11);
        glEnd();
        glPopMatrix();
    }

    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i +10 , i * 3.0, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 245, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 0, 255); // Blue color
        else
            glColor3ub(255, 0, 0); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, 11);
        glVertex2f(-10, 10);
        glVertex2f(-11, 10);
        glVertex2f(-11, 11);
        glEnd();
        glPopMatrix();
    }

    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i *3 , i-5, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 245, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 0, 255); // Blue color
        else
            glColor3ub(255, 0, 0); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, 11);
        glVertex2f(-10, 10);
        glVertex2f(-11, 10);
        glVertex2f(-11, 11);
        glEnd();
        glPopMatrix();
    }


    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i *-3 , i-5, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 245, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 0, 255); // Blue color
        else
            glColor3ub(255, 0, 0); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, 11);
        glVertex2f(-10, 10);
        glVertex2f(-11, 10);
        glVertex2f(-11, 11);
        glEnd();
        glPopMatrix();
    }

    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i*3 , i*-3, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 245, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 0, 255); // Blue color
        else
            glColor3ub(255, 0, 0); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, 11);
        glVertex2f(-10, 10);
        glVertex2f(-11, 10);
        glVertex2f(-11, 11);
        glEnd();
        glPopMatrix();
    }

    for (int i = 0; i < 25; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i*3 , i*3, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 245, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 0, 255); // Blue color
        else
            glColor3ub(255, 0, 0); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, -11);
        glVertex2f(-10, -10);
        glVertex2f(-11, -10);
        glVertex2f(-11, -11);
        glEnd();
        glPopMatrix();
    }


    for (int i = 1; i < 10; ++i) {
        glPushMatrix();
        // Translate to the desired position along X and Y axes
        glTranslatef(i*3 , i*-3, 0.0);
        // Scale if necessary
        glScalef(.5, .5, 0);

        // Change color based on the object index
        if (i % 3 == 0)
            glColor3ub(255, 245, 220); // Current color
        else if (i % 3 == 1)
            glColor3ub(0, 0, 255); // Blue color
        else
            glColor3ub(255, 0, 0); // Red color

        // Draw the object
        glBegin(GL_QUADS);
        glVertex2f(-10, -11);
        glVertex2f(-10, -10);
        glVertex2f(-11, -10);
        glVertex2f(-11, -11);
        glEnd();
        glPopMatrix();
    }
}

//an11
void rotatetimer(int value) {
  if (startRotation) {
        angle += 0.7f;
        // Check if the desired number of rotations has been reached
        if (angle >= maxRotations * 269.0f) {
            // Reset the angle to the original position
            crotation = true;
            glutPostRedisplay(); // Request redisplay to update the window
            return; // Exit the function to stop further rotation
        }
        glutPostRedisplay(); // Request redisplay to update the window
        glutTimerFunc(16, rotatetimer, 0);
    }
}
//an12
void moveRocket(int value) {
    if (crotation) {
        for(int i = 0 ; i<20 ; ++i)
    {
        rocketPosX+=0.05;
    }
        crotation2= true;
    }
    glutPostRedisplay(); // Request redisplay to update the window
    glutTimerFunc(16, moveRocket, 0); // Call the function aga
    }


void asteriod()
{
//21-44905-2—obj2
        glBegin(GL_POLYGON);
        glColor3ub(166,123,91);
        glVertex2f(17.0602857840601f, 13.8182663521634f-rocketPosY);
        glVertex2f(14.9977655410897f, 11.441260903803f-rocketPosY);
        glVertex2f(17.3752644832614f, 10.11720661487f-rocketPosY);
        glVertex2f(17.9967725912493f, 11.8219927493265f-rocketPosY);
        glVertex2f(19.9363913925115f, 11.0353464502615f-rocketPosY);
        glVertex2f(19.830080464203f, 13.4901624312031f-rocketPosY);
        glEnd();
//21-44905-2—obj3
        glPushMatrix();
        glTranslatef(-30,-4,0);
        glBegin(GL_POLYGON);
        glColor3ub(166,123,91);
        glVertex2f(17.0602857840601f, 13.8182663521634f-rocketPosY);
        glVertex2f(14.9977655410897f, 11.441260903803f-rocketPosY);
        glVertex2f(17.3752644832614f, 10.11720661487f-rocketPosY);
        glVertex2f(17.9967725912493f, 11.8219927493265f-rocketPosY);
        glVertex2f(19.9363913925115f, 11.0353464502615f-rocketPosY);
        glVertex2f(19.830080464203f, 13.4901624312031f-rocketPosY);
        glEnd();
        glPopMatrix();
//21-44905-2—obj4
        glPushMatrix();
        glTranslatef(-5,0,0);
        circle(2,11,20-rocketPosY,188,152,126);
        circle(2,11,19-rocketPosY,188,152,126);
        Semicircle(2,10,20-rocketPosY,188,152,126);
        Semicircle(2,12,19-rocketPosY,188,152,126);
        glPopMatrix();

        glPushMatrix();

//21-44905-2—obj5

glRotatef(60, 0.0, 1.0, 0.0);
glTranslatef(-5.0, 20.0-rocketPosY, 0.0);

// Enable texture mapping
glEnable(GL_TEXTURE_2D);

// Bind the texture
glBindTexture(GL_TEXTURE_2D, textures[0].textureID); // Assuming you only have one texture loaded

// Set the color to white so that the texture's colors are not affected
glColor3f(1.0f, 1.0f, 1.0f);

// Draw the sphere with texture coordinates
glutSolidSphereWithTexture(4, 20, 60);

// Disable texture mapping
glDisable(GL_TEXTURE_2D);

glPopMatrix();

}
//22-47294-1—obj1
void Background6()   //Background for scenario6
{
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
        glVertex2f(-20,25);
        glVertex2f(-20,-20);
        glVertex2f(25,-20);
        glVertex2f(25,25);
        glEnd();
        ApplyTexture(-20,25,-20,-20,25,-20,25,25,textures[1].textureID);
}
//22-47294-1—obj3

void Rocket4()
{
    glPushMatrix();
    glTranslatef(10,-8,0);
    glRotatef(90,0,0,1);
    glScalef(0.5,0.5,0);
    rocket1();
    glPopMatrix();

}
//an13
void rocket3update(int value) {

 if (getdown){

 if (rocketPosY3 < 15.0f) {
        rocketPosY3 += rocketSpeed;
    }

}
glutPostRedisplay();
glutTimerFunc(20, rocket3update, 0);

}


void rocket5() {

   if (maxRocketHeight) {
    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(254, 39, 18); // Orange color for flames
    glVertex2f(14.4f + 2.0f, -11.021f - rocketPosY3 + 10.0f);
    glVertex2f(15.2622557038941f + 2.0f, -12.7706177718086f - rocketPosY3 + 10.0f);
    glVertex2f(16.022f + 2.0f, -11.004 - rocketPosY3+ 10.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    circle(1, 15.216f + 2.0f, -10.75f - rocketPosY3+ 10.0f, 254, 39, 18);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, scale_factor, 0.0f);
    circle(0.8, 15.216f + 2.0f, -10.75f - rocketPosY3 + 10.0f, 255, 165, 0);
    glPopMatrix();
}

// Draw rocket body
glBegin(GL_QUADS);
glColor3ub(250, 218, 94);
glVertex2f(14.26697f + 2.0f, -10.4685f - rocketPosY3 + 10.0f);
glVertex2f(14.26697f + 2.0f, -4.9935124059364f - rocketPosY3 + 10.0f);
glVertex2f(16.16829f + 2.0f, -4.9935124059364f - rocketPosY3 + 10.0f);
glVertex2f(16.16829f + 2.0f, -10.4685f - rocketPosY3 + 10.0f);
glEnd();

// Draw rocket tip
glBegin(GL_TRIANGLES);
glColor3ub(220, 20, 60); //
glVertex2f(15.2775f + 2.0f, -4.9935124059364f + 2.0f - rocketPosY3 + 10.0f);
glVertex2f(14.3129f + 2.0f, -4.9935124059364f - rocketPosY3 + 10.0f);
glVertex2f(16.1989f + 2.0f, -4.9935124059364f - rocketPosY3 + 10.0f);
glEnd();

// Draw bottom wing 1
glBegin(GL_TRIANGLES);
glColor3ub(165, 42, 42);
glVertex2f(14.276f + 2.0f, -9.36381f - rocketPosY3+ 10.0f);
glVertex2f(14.276f + 2.0f, -8.5968f - rocketPosY3 + 10.0f);
glVertex2f(13.3776465929047f + 2.0f, -9.946141079297f - rocketPosY3 + 10.0f);
glEnd();

// Draw bottom wing 2
glBegin(GL_TRIANGLES);
glColor3ub(165, 42, 42);
glVertex2f(17.1606200477948f + 2.0f, -6.2308707437794f - rocketPosY3 + 10.0f);
glVertex2f(16.1933f + 2.0f, -5.9746f - rocketPosY3 + 10.0f);
glVertex2f(16.1933f + 2.0f, -5.4687f - rocketPosY3 + 10.0f);
glEnd();

// Draw top wing 1
glBegin(GL_TRIANGLES);
glColor3ub(165, 42, 42);
glVertex2f(17.0f + 2.0f, -10.0f - rocketPosY3 + 10.0f);
glVertex2f(16.1989f + 2.0f, -8.5968f - rocketPosY3 + 10.0f);
glVertex2f(16.1989f + 2.0f, -9.36381f - rocketPosY3 + 10.0f);
glEnd();

// Draw top wing 2
glBegin(GL_TRIANGLES);
glColor3ub(165, 42, 42);
glVertex2f(14.3044f + 2.0f, -6.0054f - rocketPosY3 + 10.0f);
glVertex2f(13.4696458871467f + 2.0f, -6.3428353881523f - rocketPosY3 + 10.0f);
glVertex2f(14.3044f + 2.0f, -5.45334f - rocketPosY3 + 10.0f);
glEnd();

}
//22-47294-1—obj4

void earth()
{
  glPushMatrix();
    glTranslatef(-8,0,0);
    glRotatef(earthAngle, 0.0f, 0.0f, 1.0f);
    glScalef(6, 6, 0);

    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);

    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, textures[2].textureID);

    // Set the color to white so that the texture's colors are not affected
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw the sphere with texture coordinates
    glutSolidSphereWithTexture(1.0f, 50, 50);

    // Disable texture mapping
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();

}
//22-47294-1—obj5

void moon() {
    glPushMatrix();

    // Translate the moon to revolve around the Earth

    // Rotate the moon around the Earth
    glRotatef(earthAngle * 1.5, 0.0f, 0.0f, 0.5f); // Double the speed for faster rotation

  // Translate and scale the moon's orbit to revolve around the Earth and shift 5 units to the left
    glTranslatef(8.0f-2.0f * cos(earthAngle * 2 * M_PI / 360) - 8.0f, 2.0f * sin(earthAngle * 2 * M_PI / 360)-8, 0.0f);
    glScalef(0.8f, 0.8f, 0.8f); // Scale down the orbit size

        // Enable texture mapping
    glEnable(GL_TEXTURE_2D);

    // Bind the moon texture
    glBindTexture(GL_TEXTURE_2D, textures[3].textureID); // Assuming you have loaded the moon texture at index 3

    // Set the color to white so that the texture's colors are not affected
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw the moon as a textured sphere
    glutSolidSphereWithTexture(0.5f, 50, 50); // Adjust the size of the moon as needed

    // Disable texture mapping
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

//22-47081-1—obj1
void FRoad() {

     //road
    glColor4f(0.15, 0.15, 0.15, 0.15);

    glBegin(GL_POLYGON);
    glVertex2f(-20, -16); // Bottom-left vertex
    glVertex2f(25, -16);  // Bottom-right vertex
    glVertex2f(25, -20); // Top-right vertex
    glVertex2f(-20, -20); // Top-left vertex
    glEnd();

    glColor4f(1.0, 1.0, 1.0, 1.0);

    glBegin(GL_POLYGON);
    glVertex2f(-25, -18); // Bottom-left vertex
    glVertex2f(25, -18.5);  // Bottom-right vertex
    glVertex2f(23, -18.5); // Top-right vertex
    glVertex2f(-23, -18); // Top-left vertex
    glEnd();


}

void FCar() {


//22-47081-1—obj2

 //car1
    glColor4f(1.0, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(6.574, 0.3994); // Bottom-left vertex
    glVertex2f(7.13638, 1.0001);  // Bottom-right vertex
    glVertex2f(8.3893, 0.99924); // Top-right vertex
    glVertex2f(8.393, 0.4152);
    glEnd();
//w1
    glColor4f(0.6, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(7, 0.5); // Bottom-left vertex
    glVertex2f(7.2949815158913, 0.8904310470393);  // Bottom-right vertex
    glVertex2f(7.6129558888819, 0.9008564363177); // Top-right vertex
    glVertex2f(7.6338066674386, 0.5046916437393);
    glEnd();
//w2
    glColor4f(0.6, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(7.75369864414, 0.5046916437393); // Bottom-left vertex
    glVertex2f(7.6129558888819, 0.9008564363177);  // Bottom-right vertex
    glVertex2f(8.1759269099143, 0.8904310470393); // Top-right vertex
    glVertex2f(8.1811396045534, 0.5151170330177);
    glEnd();

    glColor4f(0.6, 0.4, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(6.5740538657136, 0.3994082458233); // Bottom-left vertex
    glVertex2f(6.16844, 0);  // Bottom-right vertex
    glVertex2f(8.33795, 0); // Top-right vertex
    glVertex2f(8.3935826203427, 0.4105276755353);
    glEnd();

//22-47081-1—obj3

//car2
    glColor4f(1.0, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-4.261054143797, 10.2730423848604); // Bottom-left vertex
    glVertex2f(-1.2869924734958, 13.4164274968695);  // Bottom-right vertex
    glVertex2f(1.984967174383, 13.44145922758); // Top-right vertex
    glVertex2f(3.7918297911357, 10.8949602480031);
    glEnd();

    //w1
    glColor4f(0.6, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.5, 11.5); // Bottom-left vertex
    glVertex2f(-1, 13);  // Bottom-right vertex
    glVertex2f(0,13); // Top-right vertex
    glVertex2f(0, 11.5);
    glEnd();
//w2
    glColor4f(0.6, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1, 11.5); // Bottom-left vertex
    glVertex2f(1, 13);  // Bottom-right vertex
    glVertex2f(1.7,13); // Top-right vertex
    glVertex2f(1.7, 11.5);
    glEnd();

     //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(0.4813,13.4299);
    glVertex2f(0.4823, 10.8859779654);  // End point of the line (right side)
    glEnd();

     glColor4f(0.6, 0.6, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(3.7918297911357, 10.8949602480031); // Bottom-left vertex
    glVertex2f(3.52216, 11.275);  // Bottom-right vertex
    glVertex2f(4.7153781272267, 12.7990095916168); // Top-right vertex
    glVertex2f(4.4584, 11.00877);
    glEnd();

    glColor4f(0.6, 0.1, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(5.373286692675, 10.1479126581325); // Bottom-left vertex
    glVertex2f(7.6064014890612, 11.5462328014884);  // Bottom-right vertex
    glVertex2f(3.7918297911357, 10.8949602480031); // Top-right vertex
    glVertex2f(-4.7928764850291, 10.871660683727);
    glVertex2f(-4.4395291852493, 9.6188838935986);
    glVertex2f(6.2616695355033, 9.5936869831445);
    glEnd();

     //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(6.1709,11.3011);
    glVertex2f(6.72717, 10.9956);  // End point of the line (right side)
    glEnd();

    //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(6.2287,11.32809);
    glVertex2f(6.83787, 11.06500);  // End point of the line (right side)
    glEnd();

     //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(5.373286692675, 10.1479126581325);
    glVertex2f(-3.8401665783873, 10.1632456286666);  // End point of the line (right side)
    glEnd();

}

void FCar1() {

 //car1
    glColor4f(1.0, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(6.574-carPosX, 0.3994); // Bottom-left vertex
    glVertex2f(7.13638-carPosX, 1.0001);  // Bottom-right vertex
    glVertex2f(8.3893-carPosX, 0.99924); // Top-right vertex
    glVertex2f(8.393-carPosX, 0.4152);
    glEnd();
//w1
    glColor4f(0.6, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(7-carPosX, 0.5); // Bottom-left vertex
    glVertex2f(7.2949815158913-carPosX, 0.8904310470393);  // Bottom-right vertex
    glVertex2f(7.6129558888819-carPosX, 0.9008564363177); // Top-right vertex
    glVertex2f(7.6338066674386-carPosX, 0.5046916437393);
    glEnd();
//w2
    glColor4f(0.6, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(7.75369864414-carPosX, 0.5046916437393); // Bottom-left vertex
    glVertex2f(7.6129558888819-carPosX, 0.9008564363177);  // Bottom-right vertex
    glVertex2f(8.1759269099143-carPosX, 0.8904310470393); // Top-right vertex
    glVertex2f(8.1811396045534-carPosX, 0.5151170330177);
    glEnd();

    glColor4f(0.6, 0.4, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(6.5740538657136-carPosX, 0.3994082458233); // Bottom-left vertex
    glVertex2f(6.16844-carPosX, 0);  // Bottom-right vertex
    glVertex2f(8.33795-carPosX, 0); // Top-right vertex
    glVertex2f(8.3935826203427-carPosX, 0.4105276755353);
    glEnd();

//car2
    glColor4f(1.0, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-4.261054143797+carPosX, 10.2730423848604); // Bottom-left vertex
    glVertex2f(-1.2869924734958+carPosX, 13.4164274968695);  // Bottom-right vertex
    glVertex2f(1.984967174383+carPosX, 13.44145922758); // Top-right vertex
    glVertex2f(3.7918297911357+carPosX, 10.8949602480031);
    glEnd();

    //w1
    glColor4f(0.6, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.5+carPosX, 11.5); // Bottom-left vertex
    glVertex2f(-1+carPosX, 13);  // Bottom-right vertex
    glVertex2f(0+carPosX,13); // Top-right vertex
    glVertex2f(0+carPosX, 11.5);
    glEnd();
//w2
    glColor4f(0.6, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1+carPosX, 11.5); // Bottom-left vertex
    glVertex2f(1+carPosX, 13);  // Bottom-right vertex
    glVertex2f(1.7+carPosX,13); // Top-right vertex
    glVertex2f(1.7+carPosX, 11.5);
    glEnd();

     //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(0.4813+carPosX,13.4299);
    glVertex2f(0.4823+carPosX, 10.8859779654);  // End point of the line (right side)
    glEnd();

     glColor4f(0.6, 0.6, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(3.7918297911357+carPosX, 10.8949602480031); // Bottom-left vertex
    glVertex2f(3.52216+carPosX, 11.275);  // Bottom-right vertex
    glVertex2f(4.7153781272267+carPosX, 12.7990095916168); // Top-right vertex
    glVertex2f(4.4584+carPosX, 11.00877);
    glEnd();

    glColor4f(0.6, 0.1, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(5.373286692675+carPosX, 10.1479126581325); // Bottom-left vertex
    glVertex2f(7.6064014890612+carPosX, 11.5462328014884);  // Bottom-right vertex
    glVertex2f(3.7918297911357+carPosX, 10.8949602480031); // Top-right vertex
    glVertex2f(-4.7928764850291+carPosX, 10.871660683727);
    glVertex2f(-4.4395291852493+carPosX, 9.6188838935986);
    glVertex2f(6.2616695355033+carPosX, 9.5936869831445);
    glEnd();

     //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(6.1709+carPosX,11.3011);
    glVertex2f(6.72717+carPosX, 10.9956);  // End point of the line (right side)
    glEnd();

    //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(6.2287+carPosX,11.32809);
    glVertex2f(6.83787+carPosX, 11.06500);  // End point of the line (right side)
    glEnd();

     //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(5.373286692675+carPosX, 10.1479126581325);
    glVertex2f(-3.8401665783873+carPosX, 10.1632456286666);  // End point of the line (right side)
    glEnd();

}


void FBuilding() {

//22-47081-1—obj4


    //b 1
     //outer shape
    glColor4f(1.0, 0.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(24, -16); // Bottom-left vertex
    glVertex2f(19, -16);  // Bottom-right vertex
    glVertex2f(19, 7); // Top-right vertex
    glVertex2f(22, 10); // Top-left vertex
     glVertex2f(22.1, 14.4); // Bottom-left vertex
    glVertex2f(24, 14.4);  // Bottom-right vertex
    glVertex2f(24, -16); // Top-right vertex
    glEnd();

    //window
       glColor4f(1.0, 1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(20, -16); // Bottom-left vertex
    glVertex2f(20, -6);  // Bottom-right vertex
    glVertex2f(23, -6); // Top-right vertex
    glVertex2f(23, -16);
    glEnd();

    //line
      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(21.3,-6.0);
    glVertex2f(21.3, -16.0);  // End point of the line (right side)
    glEnd();

    //window top
     glColor4f(1.0, 1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(20, 1); // Bottom-left vertex
    glVertex2f(20, 7);  // Bottom-right vertex
    glVertex2f(24, 7); // Top-right vertex
    glVertex2f(24, 1);
    glEnd();

     // Draw line in window
    glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(20, 6.0); // Start point of the line (left side)
    glVertex2f(24, 6.0);  // End point of the line (right side)
    glEnd();

      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(20, 5.0); // Start point of the line (left side)
    glVertex2f(24, 5.0);  // End point of the line (right side)
    glEnd();

      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(20, 4.0); // Start point of the line (left side)
    glVertex2f(24, 4.0);  // End point of the line (right side)
    glEnd();

      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(20, 3.0); // Start point of the line (left side)
    glVertex2f(24, 3.0);  // End point of the line (right side)
    glEnd();

      glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(20, 2.0); // Start point of the line (left side)
    glVertex2f(24, 2.0);  // End point of the line (right side)
    glEnd();


   //22-47081-1—obj5

    //b2

    glColor4f(1.0, 0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(6.8, -16); // Bottom-left vertex
    glVertex2f(8, -12);  // Bottom-right vertex
    glVertex2f(16, -12); // Top-right vertex
    glVertex2f(17.14, -16);
    glEnd();

    glColor4f(1.0, 1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(8.6, -12); // Bottom-left vertex
    glVertex2f(9.06, -9.98);  // Bottom-right vertex
    glVertex2f(14.938, -9.98); // Top-right vertex
    glVertex2f(15.49, -12);
    glEnd();

       glColor4f(1.0, 1.0, 0.7, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(9.3, -9.98); // Bottom-left vertex
    glVertex2f(9.48, -9);  // Bottom-right vertex
    glVertex2f(14.488, -9); // Top-right vertex
    glVertex2f(14.69, -10);
    glEnd();

    glColor4f(1.0, 1.0, 0.7, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(9.9, -9           ); // Bottom-left vertex
    glVertex2f(9.48, -9);  // Bottom-right vertex
    glVertex2f(14.488, -9); // Top-right vertex
    glVertex2f(14.69, -10);
    glEnd();

    glColor4f(1.0, 1.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(14.055, -9); // Bottom-left vertex
    glVertex2f(12.403776, 5.943599);  // Bottom-right vertex
    glVertex2f(12.2135, 5.944); // Top-right vertex
    glVertex2f(9.901, -8.9984);
    glEnd();

    //line
    glColor4f(0.0, 0.0, 0.0, 0.0); // Red color for the line
    glBegin(GL_LINES);
    glVertex2f(12,-9);
    glVertex2f(12, 5.9932);  // End point of the line (right side)
    glEnd();

          glColor4f(1.0, 0.4, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(11.8, 8.54); // Bottom-left vertex
    glVertex2f(12.4, 12.5);  // Bottom-right vertex
    glVertex2f(13.0, 8.54); // Top-right vertex
    glEnd();

     circle(1.5, 12.35f, 8.0f, 255, 0, 0);

      glColor4f(1.0, 0.4, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(14.253, 5.983); // Bottom-left vertex
    glVertex2f(10.50, 5.983);  // Bottom-right vertex
    glVertex2f(10.5, 7.2); // Top-right vertex
    glVertex2f(14.253, 7.2);
    glEnd();
//22-47081-1—obj7
    //b3
      glColor4f(1.0, 0.4, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(5, -16); // Bottom-left vertex
    glVertex2f(5, 5);  // Bottom-right vertex
    glVertex2f(-4.8, 5); // Top-right vertex
    glVertex2f(-4.8, -16);
    glEnd();

      glColor4f(1.0, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.0, 5); // Bottom-left vertex
    glVertex2f(-4.8, 5);  // Bottom-right vertex
    glVertex2f(-6.6, 7); // Top-right vertex
    glVertex2f(-3.6, 7);
    glEnd();

glColor4f(1.0, 0.6, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 4.9188); // Bottom-left vertex
    glVertex2f(0, 6);  // Bottom-right vertex
    glVertex2f(4, 6); // Top-right vertex
    glVertex2f(3.762, 4.58677);
    glEnd();

//22-47081-1—obj6

    // b4

    glColor4f(0.0, 0.6, 0.1, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-18.185046,-16.3781); // Bottom-left vertex
    glVertex2f(-9.9349,-16.3781);  // Bottom-right vertex
    glVertex2f(-10, 0); // Top-right vertex
    glVertex2f(-12.1419137399603, 1.998147347019);
    glVertex2f(-12.1505423748404, 4.3192501297723);
    glVertex2f(-16.0916101740802, 4.3399653612084);
    glVertex2f(-16.0916101740802, 4.3399653612084);
    glVertex2f(-16.102457149937, 2.0067759818991);
    glVertex2f(-18.2465, 0);
    glEnd();

    glColor4f(0.3, 0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-15.36613, 4.33615); // Bottom-left vertex
    glVertex2f(-15.4, 8);  // Bottom-right vertex
    glVertex2f(-14.0158267252183, 8.7418721559285);
    glVertex2f(-14.000505, 6.9999);
    glVertex2f(-13.33417776, 6.9944755);
    glVertex2f(-13.3208691329811, 8.6009694226825);
    glVertex2f(-12.729738175883, 4.3352794643493);

    glVertex2f(-12.7557220651269, 8.6009694226825);
    glVertex2f(-12.729738175883, 4.3352794643493);
    glEnd();

    glColor4f(1.0, 0.6, 0.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-15.9385130872147, 4.0776483531288); // Bottom-left vertex
    glVertex2f(-15.3862804548868, 4.0862769880089);  // Bottom-right vertex
    glVertex2f(-15.4035, 2.00525); // Top-right vertex
    glVertex2f(-15.92992, 2.0064);
    glEnd();

    glColor4f(1.0, 0.6, 0.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-15.1533073131234, 4.0862769880089); // Bottom-left vertex
    glVertex2f(-14.7218755691172, 4.0862769880089); // Bottom-right vertex
    glVertex2f(-14.6959, 2.003); // Top-right vertex
    glVertex2f(-15.1533, 2.0047);
    glEnd();

    glColor4f(1.0, 0.6, 0.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-14.428501983193, 4.1035342577692); // Bottom-left vertex
    glVertex2f(-13.9107838903856, 4.0862769880089); // Bottom-right vertex
    glVertex2f(-13.9280, 2.003); // Top-right vertex
    glVertex2f(-14.4199, 2.003);
    glEnd();

     glColor4f(1.0, 0.6, 0.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-13.6691821137422, 4.094905622889); // Bottom-left vertex
    glVertex2f(-13.2291217348559, 4.094905622889); // Bottom-right vertex
    glVertex2f(-13.2205, 2.003); // Top-right vertex
    glVertex2f(-13.64332, 2.003);
    glEnd();

    glColor4f(1.0, 0.6, 0.0, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-12.9961485930925, 4.094905622889); // Bottom-left vertex
    glVertex2f(-12.5043164049255, 4.094905622889); // Bottom-right vertex
    glVertex2f(-12.500002, 2.003); // Top-right vertex
    glVertex2f(-13.0, 2.003);
    glEnd();

    glPushMatrix();
    glRotatef(90,0,0,1);
    Semicircle(8,-8,8,0,0,0);
    glPopMatrix();

    glColor3ub(255,255,255); //Straight Line right side
    glBegin(GL_LINES);
    glVertex2f(-10, -16.0f);
    glVertex2f(-10,0);
    glEnd();
}


void FSky()
{
  circle(3,18,17,255,255,255); //moon

  //cloud1
  //22-47081-1—obj8
  circle (1,-15.029290289693f, 13.0507895983417f,128,128,128);
  circle (1,-14.029290289693f, 14.0507895983417f,128,128,128);
  circle (1,-13.029290289693f, 13.0507895983417f,128,128,128);

  //22-47081-1—obj9
  //cloud1
  circle (1,-7.029290289693f, 15.0507895983417f,128,128,128);
  circle (1,-8.029290289693f, 16.0507895983417f,128,128,128);
  circle (1,-6.329290289693f, 15.4507895983417f,128,128,128);

}

void FSky1()
{
  circle(3,18,17,255,255,255); //moon

  //cloud1
  circle (1,-15.029290289693f+carPosX, 13.0507895983417f,128,128,128);
  circle (1,-14.029290289693f+carPosX, 14.0507895983417f,128,128,128);
  circle (1,-13.029290289693f+carPosX, 13.0507895983417f,128,128,128);

  //cloud1
  circle (1,-7.029290289693f+carPosX, 15.0507895983417f,128,128,128);
  circle (1,-8.029290289693f+carPosX, 16.0507895983417f,128,128,128);
  circle (1,-6.329290289693f+carPosX, 15.4507895983417f,128,128,128);

}

void Scenario1() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Road();
    Day();
    Hill();
    River();
    Boat();
    Wall();
    Tree();
    House();
    Car();
    Human();
    int friendIndex = currentLine % 2;

    glColor3f(0, 0, 0);
    if (friendIndex == 0) {
        Text(-15.8, -3, conversation[currentLine]);
    } else {
        Text(-1.8, -3, conversation[currentLine]);
    }

    glutSwapBuffers();
	glFlush();
}
void Scenario2() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Road();
    Car();
    if (isday) {
        River();
        Boat();
        Day();
    } else {
        River();
        Night();
    }
    Hill();
    Wall();
    Tree();
    House();
    rocket();
    Text(0,-5,"Press R to Build the Rocket");
    Text(0,-7,"Press Toggle Between Day & Night");
	glFlush();
}

void Scenario3() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Road();
    River();
    Boat();
    Day();
    Car();
    Hill();
    Wall();
    Tree();
    House();
    // Draw LaunchPad
    glBegin(GL_QUADS);
    glColor3ub(249,255,227);
    glVertex2f(13.212969653515f, -10.468533237733f);
    glVertex2f(12.2f, -12.4f);
    glVertex2f(18, -12.4f);
    glVertex2f(17.212969653515f, -10.468533237733f);
    glEnd();
    rocket1Y();
    Text(3,-5,"Press L to Launch the Rocket");
    glutSwapBuffers();
	glFlush();
}
void Scenario4() {
 glClearColor(0.392f, 0.769f, 1.000f, 1.0f);
 glClear(GL_COLOR_BUFFER_BIT);
    //cloud start

    //cloud from left-top
    Semicircle(3,-18+carPosX,15,255,255,255);
    Semicircle(3,-20+carPosX,15,255,255,255);
    Semicircle(3,-14.2f+carPosX,15,255,255,255);
    Semicircle(3,-16+carPosX,15.5f,255,255,255);

    //cloud from Right-bottom
    Semicircle(3,18-carPosX,-5-10,255,255,255);
    Semicircle(3,19-carPosX,-6-10,255,255,255);
    Semicircle(3,14.2f-carPosX,-6-10,255,255,255);
    Semicircle(3,16-carPosX,-4.8f-10,255,255,255);
    //cloud from left-bottom
    circle(2,-18+carPosX,-5,255,255,255);
    circle(2,-20+carPosX,-6,255,255,255);
    circle(2,-18+carPosX,-8,255,255,255);
    circle(2,-16+carPosX,-6,255,255,255);

    //cloud from Right-top
    circle(2,18-carPosX,15-8,255,255,255);
    circle(2,20-carPosX,16-8,255,255,255);
    circle(2,18-carPosX,18-8,255,255,255);
    circle(2,16-carPosX,15.5f-8,255,255,255);

    glPushMatrix();
    glScalef(1.5f,1.5f,0);
    glTranslatef(-14,0,0);
    rocket1Y();
    glPopMatrix();
	glFlush();
}


void Scenario5() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    stars();
    asteriod();
    glPushMatrix();
    glTranslatef(-14,-2,0);
    rocket2();
    glPopMatrix();
    Text(3,-5,"Press w/s to Speed up /Speed down");
    Text(10,-8,"Press a/d to move left /Speed right");

	glFlush();
}


void Scenario6() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Background6();
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    rocket3();
    glPopMatrix();
    Text(3,-5,"Press B to Rotate Around BlackHole");
	glFlush();
    glutSwapBuffers();
}


void Scenario7() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
//22-47294-1—obj2
    glPushMatrix();
    glRotatef(90,0,0,1);
    Scenario5();
    glPopMatrix();
	glFlush();
    glutSwapBuffers();
}

void Scenario8() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    stars();
    Rocket4();
    moon();
    earth();
	glFlush();
    glutSwapBuffers();
}

void Scenario9() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    FSky();
    FRoad();
    FCar();
    FBuilding();

    glPushMatrix();
    glScalef(1.2,1.2,0);
    rocket5();
    glPopMatrix();
	Text(10,-18,"Press O to Land the Rocket");
    glutSwapBuffers();
	glFlush();
}
void Scenario10() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    FSky1();
    FRoad();
    FCar1();
    FBuilding();
	glFlush();
    glutSwapBuffers();
}


void display2() {


	glFlush();
}

void changeScenario(void (*scenarioFunction)()) {
float scale_factor = 1.0f;  // Initial scaling factor
bool zoom_in = true;        // Direction of scaling
bool isday = true;
bool rocketBuilt = false;
bool wingsBuilt = false;
float rocketHeight = -10.4685f;
float rocketPosY = 0.0f;
float rocketPosX = 0.0f;
float rocketSpeed = 0.1f;
const float maxRocketHeight = -3.949435772322f;
const float Rocketanimantionspeed = 0.05f;
float carPosX = 0.0f;
float carSpeed = 0.1f;
float boatspeed = 0.1f;
float boatPosX = 0.0f;
float wheelRotation = 0.0f;
int currentLine = 0;
int textDisplayDuration = 3000;

    // Set the display function to the provided scenario function
    glutDisplayFunc(scenarioFunction);

    // Request redisplay
    glutPostRedisplay();
}

//an14
void handleKeypress(unsigned char key, int x, int y) {
        switch (key) {
        case '1':
            changeScenario(Scenario1);
            break;
        case '2':
            changeScenario(Scenario2);
            break;
        case '3':
            changeScenario(Scenario3);
            break;
        case '4':
            changeScenario(Scenario4);
            break;
        case '5':
            changeScenario(Scenario5);
            break;
        case '6':
            changeScenario(Scenario6);
            break;

        case '7':
            if (crotation2) {

             changeScenario(Scenario7);
            }
            break;

        case '8':

            if (crotation2) {

             changeScenario(Scenario8);
            }
            break;

        case '9':

             changeScenario(Scenario9);

        break;
        case '0':

        changeScenario(Scenario10);

            break;

        case 'a':
            rocketPosX1 -= 0.1f;
            break;
        case 'd':
            rocketPosX1 += 0.1f;
            break;
        case 'w':
            rocketPosY += 0.1f;
            break;

        case 's':
            rocketPosY -= 0.1f;
            break;

        case 'r':
        creatingRocket = true;
        break;

        case 'n':
        toggleDayNight = !toggleDayNight;
        break;

        case 'l':
        launchRocket = true;
        break;

        case 'o':
        getdown = true;
        break;

        case 'b':
        if (!startRotation) {
            startRotation = true;
            glutTimerFunc(16, rotatetimer, 0); // Start the rotation timer
            }
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Project");
	glutInitWindowSize(3200, 3200);
 	glutKeyboardFunc(handleKeypress);
 	glutTimerFunc(0, rotatetimer, 20);
 	glutTimerFunc(0, earthSpinningTop, 20);
 	glutTimerFunc(0, moveRocket, 20);
	glutTimerFunc(0, scaletimer, 20);
	glutTimerFunc(0, rocket1update, 60);
	glutTimerFunc(0, rocket2update, 60);
	glutTimerFunc(0, rocket3update, 60);
	glutTimerFunc(2000, timeupdate,0);
	glutTimerFunc(0, rocketupdate, 20);
    glutTimerFunc(0, carupdate, 20);
    glutTimerFunc(0, boatupdate,20);
    glutTimerFunc(3000,Textupdate, 0);
    loadImageAndStore("C:/Study Matirial/7th sem/Computer Grapics/Project/Project/resources/a2.bmp");
    loadImageAndStore("C:/Study Matirial/7th sem/Computer Grapics/Project/Project/resources/a44.bmp");
    loadImageAndStore("C:/Study Matirial/7th sem/Computer Grapics/Project/Project/resources/a1.bmp");
    loadImageAndStore("C:/Study Matirial/7th sem/Computer Grapics/Project/Project/resources/a5.bmp");
    PlayMusic("C:/Study Matirial/7th sem/Computer Grapics/Project/Project/resources/m1.wav");
    gluOrtho2D(-20,25,-20,25);
	glutDisplayFunc(Scenario1);
	glutMainLoop();
	return 0;
}
