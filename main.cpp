#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416



GLint i, j, k;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;

void init(void)
{
    glClearColor(0.0, 0.5, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();


}

float p = -10;
float b= -100;
float c= -450;

///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}
/// *** Sun_Model **///
void Sun_Model()
{

    glPushMatrix();
    glTranslatef(600,400,0);
    circle(50);
    glPopMatrix();

}
void Moving_Sun_Model()
{
    glPushMatrix();
    glRotatef(-sun_spin, 0,0,-.009);
    Sun_Model();
    glPopMatrix();

}
///*** Cloud_Model***///
void cloud_model_one()
{

    glColor3f(1.25, 0.924, 0.930);

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    ///Right

    glPushMatrix();
    glTranslatef(360,210,0);
    circle(16);
    glPopMatrix();


    ///middle_Fill
    glPushMatrix();
    glTranslatef(355,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350,210,0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310,204,0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305,204,0);
    circle(10);
    glPopMatrix();







    ///****Fill End****

}

void cloud_model_Two()
{
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(305,205,0);
    circle(10);
    glPopMatrix();

    ///Top

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(334,207,0);
    circle(10);
    glPopMatrix();

    ///Bottom_Part
    glPushMatrix();
    glTranslatef(320,207,0);
    circle(10);
    glPopMatrix();



}

void cloud_model_Three()
{
    glColor3f(1.25, 0.924, 0.930);

    ///Left_Part
    glPushMatrix();
    glTranslatef(300,200,0);
    circle(15);
    glPopMatrix();

    ///Top_Left

    glPushMatrix();
    glTranslatef(320,210,0);
    circle(15);
    glPopMatrix();

    ///Top
    glPushMatrix();
    glTranslatef(340,220,0);
    circle(16);
    glPopMatrix();

    ///Top_Right
    glPushMatrix();
    glTranslatef(360,210,0);
    circle(15);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(380,200,0);
    circle(15);
    glPopMatrix();

    ///Bottom_Right
    glPushMatrix();
    glTranslatef(360,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom_Left
    glPushMatrix();
    glTranslatef(320,190,0);
    circle(20);
    glPopMatrix();

    ///Bottom
    glPushMatrix();
    glTranslatef(340,190,0);
    circle(20);
    glPopMatrix();




    ///****Fill End****

}
///*** Hill_Model***///
void hill_big()
{

    ///Hill_Big
    glBegin(GL_POLYGON);
    glColor3ub(56, 160, 146);
    glVertex2i(10, 70);
    glVertex2i(200, 250);
    glVertex2i(360, 70);

    glEnd();

    ///Hill_Snow
    glBegin(GL_POLYGON);
    glColor3ub(182, 213, 216);

    glVertex2i(200, 250);
    glVertex2i(250, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 200);
    glVertex2i(180, 180);
    glVertex2i(140, 190);

    glEnd();

}
void hill_small()
{
    ///Hill_Small
    glBegin(GL_POLYGON);
    glColor3ub(56, 160, 146);
    glVertex2i(900, 70);
    glVertex2i(950, 150);
    glVertex2i(1000, 70);

    glEnd();

    ///Hill_Small_Snow
    glBegin(GL_POLYGON);
    glColor3ub(182, 213, 216);
    glVertex2i(950, 150);
    glVertex2i(965, 130);
    glVertex2i(955, 130);
    glVertex2i(950, 135);
    glVertex2i(940, 130);
    glVertex2i(930, 130);



    glEnd();
}
///*** Tilla_Model ***///
void Tilla_One_Model()
{
    ///Tilla
    glBegin(GL_POLYGON);
    glColor3ub(160, 196, 57);
    glVertex2i(125, 70);
    glVertex2i(150, 80);
    glVertex2i(160, 90);
    glVertex2i(170, 90);
    glVertex2i(180, 100);
    glVertex2i(190, 105);
    glVertex2i(200, 108);
    glVertex2i(300, 110);
    glVertex2i(300, 70);

    glEnd();

}

void Tilla_Two_Model()
{

    glColor3ub(57, 140, 2);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430,90,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420,87,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390,70,0);
    circle(30);
    glPopMatrix();

    ///Right_Part
    glPushMatrix();
    glTranslatef(445,80,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455,75,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465,70,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470,65,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480,60,0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485,55,0);
    circle(20);
    glPopMatrix();

}
///*** House_Model ***///
void house()
{
    ///House_Roof
    glBegin(GL_POLYGON);
    glColor3ub(224, 107, 99);
    glVertex2i(290, 110);
    glVertex2i(340, 135);
    glVertex2i(380, 110);

    glEnd();


    ///House_Body_Fence
    glBegin(GL_POLYGON);
    glColor3ub(239, 203, 208);
    glVertex2i(290, 70);
    glVertex2i(290, 110);
    glVertex2i(380, 110);
    glVertex2i(380, 70);

    glEnd();



    ///House_Door
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(330, 70);
    glVertex2i(330, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 70);

    glEnd();

    ///House_Window1
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(295, 75);
    glVertex2i(295, 90);
    glVertex2i(310, 90);
    glVertex2i(310, 75);

    glEnd();

    ///House_Window2
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(312, 75);
    glVertex2i(312, 90);
    glVertex2i(327, 90);
    glVertex2i(327, 75);

    glEnd();

    ///House_Window3
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(355, 75);
    glVertex2i(355, 90);
    glVertex2i(370, 90);
    glVertex2i(370, 75);

    glEnd();

    ///House_Small_Roof
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(250, 90);
    glVertex2f(250, 100);
    glVertex2f(290, 100);
    glVertex2f(290, 90);



    glEnd();

///House_Small_Fence
    glBegin(GL_POLYGON);
    glColor3ub(227,177,81);
    glVertex2i(255, 70);
    glVertex2i(255, 90);
    glVertex2i(290, 90);
    glVertex2i(290, 70);

    glEnd();

    ///House_Small_Door
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex2i(260, 70);
    glVertex2i(260, 80);
    glVertex2i(285, 80);
    glVertex2i(285, 70);

    glEnd();

}
///*** Road_Field_Model ***///
void field()
{
    ///Road
    glBegin(GL_QUADS);
    glBegin(GL_POLYGON);
    glColor3ub(118,118,108);
    glVertex2i(0, 20);
    glVertex2i(0, 70);
    glVertex2i(1000, 70);
    glVertex2i(1000, 20);

    glEnd();

    ///Road_Stripe
    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);
    glVertex2i(10, 52);
    glVertex2i(10, 55);
    glVertex2i(100, 55);
    glVertex2i(100, 52);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);
    glVertex2i(150, 52);
    glVertex2i(150, 55);
    glVertex2i(250, 55);
    glVertex2i(250, 52);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);
    glVertex2i(300, 52);
    glVertex2i(300, 55);
    glVertex2i(400, 55);
    glVertex2i(400, 52);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);
    glVertex2i(450, 52);
    glVertex2i(450, 55);
    glVertex2i(550, 55);
    glVertex2i(550, 52);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);
    glVertex2i(600, 52);
    glVertex2i(600, 55);
    glVertex2i(700, 55);
    glVertex2i(700, 52);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);
    glVertex2i(750, 52);
    glVertex2i(750, 55);
    glVertex2i(850, 55);
    glVertex2i(850, 52);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);
    glVertex2i(900, 52);
    glVertex2i(900, 55);
    glVertex2i(1000, 55);
    glVertex2i(1000, 52);

    glEnd();



    ///Field_Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
    glVertex2i(0, 0);
    glVertex2i(0, 25);
    glVertex2i(1000, 25);
    glVertex2i(1000, 0);

    glEnd();



}

///Bottom Tree
void Bottom_tree()
{
    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree1   ///
    glColor3ub(75,35,5);
    glVertex3f(680,0,0);
    glVertex3f(685,0,0);
    glVertex3f(685,20,0);
    glVertex3f(680,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(675,10,0);
    glVertex3f(690,10,0);
    glVertex3f(682.5,40,0);
    glVertex3f(682.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(676,15,0);
    glVertex3f(689,15,0);
    glVertex3f(682.5,45,0);
    glVertex3f(682.5,45,0);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree2   ///
    glColor3ub(75,35,5);
    glVertex3f(580,0,0);
    glVertex3f(585,0,0);
    glVertex3f(585,20,0);
    glVertex3f(580,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(575,10,0);
    glVertex3f(590,10,0);
    glVertex3f(582.5,40,0);
    glVertex3f(582.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(576,15,0);
    glVertex3f(589,15,0);
    glVertex3f(582.5,45,0);
    glVertex3f(582.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree3   ///
    glColor3ub(75,35,5);
    glVertex3f(480,0,0);
    glVertex3f(485,0,0);
    glVertex3f(485,20,0);
    glVertex3f(480,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(475,10,0);
    glVertex3f(490,10,0);
    glVertex3f(482.5,40,0);
    glVertex3f(482.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(476,15,0);
    glVertex3f(489,15,0);
    glVertex3f(482.5,45,0);
    glVertex3f(482.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree4   ///
    glColor3ub(75,35,5);
    glVertex3f(380,0,0);
    glVertex3f(385,0,0);
    glVertex3f(385,20,0);
    glVertex3f(380,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(375,10,0);
    glVertex3f(390,10,0);
    glVertex3f(382.5,40,0);
    glVertex3f(382.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(376,15,0);
    glVertex3f(389,15,0);
    glVertex3f(382.5,45,0);
    glVertex3f(382.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree5   ///
    glColor3ub(75,35,5);
    glVertex3f(280,0,0);
    glVertex3f(285,0,0);
    glVertex3f(285,20,0);
    glVertex3f(280,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(275,10,0);
    glVertex3f(290,10,0);
    glVertex3f(282.5,40,0);
    glVertex3f(282.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(276,15,0);
    glVertex3f(289,15,0);
    glVertex3f(282.5,45,0);
    glVertex3f(282.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree6   ///
    glColor3ub(75,35,5);
    glVertex3f(180,0,0);
    glVertex3f(185,0,0);
    glVertex3f(185,20,0);
    glVertex3f(180,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(175,10,0);
    glVertex3f(190,10,0);
    glVertex3f(182.5,40,0);
    glVertex3f(182.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(176,15,0);
    glVertex3f(189,15,0);
    glVertex3f(182.5,45,0);
    glVertex3f(182.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree7   ///
    glColor3ub(75,35,5);
    glVertex3f(80,0,0);
    glVertex3f(85,0,0);
    glVertex3f(85,20,0);
    glVertex3f(80,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(75,10,0);
    glVertex3f(90,10,0);
    glVertex3f(82.5,40,0);
    glVertex3f(82.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(76,15,0);
    glVertex3f(89,15,0);
    glVertex3f(82.5,45,0);
    glVertex3f(82.5,45,0);
    glEnd();
    ///End///
}
///*** Tree_Model ***///
void Tree_Model_One()
{


    glPushMatrix();
    glTranslatef(110,110,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,100,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(109, 70);
    glVertex2f(109, 90);
    glVertex2f(111, 90);
    glVertex2f(111, 70);

    glEnd();

}
void Tree_Model_Two()
{

    glPushMatrix();
    glTranslatef(130,130,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,125,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(129, 110);
    glVertex2f(129, 124);
    glVertex2f(131, 124);
    glVertex2f(131, 110);

    glEnd();
}

void Tree_Model_Three()
{


    glBegin(GL_POLYGON);

    glVertex2f(125, 123);
    glVertex2f(133, 145);
    glVertex2f(141, 123);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(132, 110);
    glVertex2f(132, 124);
    glVertex2f(134, 124);
    glVertex2f(134, 110);

    glEnd();
}

/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model()
{

    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

///*** Windmill_Blades_Model ***///

void Windmill_Blade()
{

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
///*** Windmill_Final_Model ***///
void Windmill()
{


    ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    ///Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();




}



///***   Object  ***///
///=================///

///*** Sun ***///
void Sun()
{
    glColor3f(1, 0, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}
///*** Cloud_One_Model_One ***///
void cloud_one()
{
    glPushMatrix();
    glTranslatef(cx,-40,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Two_Model_one ***///

void cloud_two()
{
    glPushMatrix();
    glTranslatef(bx+100,150,0);
    cloud_model_one();
    glPopMatrix();

}

///*** Cloud_Three_Model_Two ***///

void cloud_three()
{
    glPushMatrix();
    glTranslatef(ax-80,80,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Four_Model_Two ***///

void cloud_four()
{
    glPushMatrix();
    glTranslatef(dx+300,125,0);
    cloud_model_Two();
    glPopMatrix();

}
///*** Cloud_Five_Model_Three ***///
void cloud_five()
{

    glPushMatrix();
    glTranslatef(ax+-300,170,0);
    cloud_model_Three();
    glPopMatrix();
}
///*** Cloud_Six_Model_Three ***///
void cloud_six()
{

    glPushMatrix();
    glTranslatef(cx+-500,20,0);
    cloud_model_Three();
    glPopMatrix();
}

///*** House_One ***///
void house_one()
{
    glPushMatrix();
    glTranslatef(-8,0,0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_two()
{
    glPushMatrix();
    glTranslatef(430,0,0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_three()
{
    glPushMatrix();
    glTranslatef(320, 37,0);
    house();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two()
{
    glPushMatrix();
    glTranslatef(560,-20,0);
    hill_big();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One()
{
    glPushMatrix();
    glTranslatef(-1,0,0);
    hill_small();
    glPopMatrix();

}
/// *** Tilla_One_Model_One ***///

void Tilla_One()
{

    glPushMatrix();
    glTranslatef(-7,0,0);
    Tilla_One_Model();
    glPopMatrix();

}
/// *** Tilla_Two_Model_Two ***///
void Tilla_Two()
{

    glPushMatrix();
    glTranslatef(0,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Three_Model_Two ***///
void Tilla_Three()
{

    glPushMatrix();
    glTranslatef(400,0,0);
    Tilla_Two_Model();
    glPopMatrix();


}
/// *** Tilla_Four_Model_One ***///
void Tilla_Four()
{

    glColor3f(0.833, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(380,0,0);
    Tilla_One_Model();
    glPopMatrix();


}
///*** Tree_1 ***///
void Tree_One()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(-50,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(500,0,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model_One();
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(292,40,0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(30,-30,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50,-10,0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(322,0,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(350,-15,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(760,-25,0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90,-2,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125,0,0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408,-22,0);
    Tree_Model_Three();
    glPopMatrix();
}

/// *** Windmill ***///
void Windmill_One()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0,-10,0);
    Windmill();
    glPopMatrix();

}

void Windmill_Two()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,-70,0);
    Windmill();
    glPopMatrix();

}
void Windmill_Three()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108,-90,0);
    Windmill();
    glPopMatrix();

}
///Object_End


///*** Display Function ***///


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);



    ///*** Object_Layer ***///
    Sun();

    Windmill_Three();

    Hill_Big_One();
    Tilla_Four();

    house_three();

    Hill_Big_Two();
    Hill_Small_One();

    cloud_three();
    cloud_four();

    Windmill_One();
    Windmill_Two();


    Tilla_One();
    Tilla_Two();
    Tilla_Three();


    house_one();
    cloud_one();
    house_two();


    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();



    cloud_two();
    cloud_five();
    cloud_six();
    field();

    Bottom_tree();


    //***Bus 1***//


    if(b<= 1000)
        b = b + 0.2;
    else
        b = -150;

    glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(b+80,88);  //bus front...................
    glVertex2f(b+95,88);
    glVertex2f(b+95,100);
    glVertex2f(b+80,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(26, 26, 0);
    glVertex2f(b+94,89);   // bus font glass
    glVertex2f(b+96,89);
    glVertex2f(b+96,100);
    glVertex2f(b+94,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(b+5,80);  //.....bus
    glVertex2f(b+90,80);
    glVertex2f(b+90,105);
    glVertex2f(b+5,105);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(b+10,55);  //top..........lowerpart
    glVertex2f(b+92,55);
    glVertex2f(b+92,80);
    glVertex2f(b+10,80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 51, 0);
    glVertex2f(b+11,81);  //top..........
    glVertex2f(b+89,81);
    glVertex2f(b+89,102);
    glVertex2f(b+11,102);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(b+12,85);  //window..........
    glVertex2f(b+20,85);
    glVertex2f(b+20,100);
    glVertex2f(b+12,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(b+22,85);  //window..........
    glVertex2f(b+30,85);
    glVertex2f(b+30,100);
    glVertex2f(b+22,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(b+32,85);  //window..........
    glVertex2f(b+40,85);
    glVertex2f(b+40,100);
    glVertex2f(b+32,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(b+42,85);  //window..........
    glVertex2f(b+50,85);
    glVertex2f(b+50,100);
    glVertex2f(b+42,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(b+52,85);  //window..........
    glVertex2f(b+60,85);
    glVertex2f(b+60,100);
    glVertex2f(b+52,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(b+62,55);  //..door..........
    glVertex2f(b+70,55);
    glVertex2f(b+70,95);
    glVertex2f(b+62,95);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(b+72,85);  //window..........
    glVertex2f(b+80,85);
    glVertex2f(b+80,100);
    glVertex2f(b+72,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(b+82,85);  //window..........
    glVertex2f(b+88,85);
    glVertex2f(b+88,100);
    glVertex2f(b+82,100);
    glEnd();

    glColor3ub(255, 255, 204);          //....chaka....back
    circle(4,8,b+45,65);
    glColor3ub(255, 255, 204);
    circle(2,4,b+55,75);
    glColor3ub(255, 255, 204);
    circle(3,6,b+15,75);
    glColor3ub(255, 255, 204);
    circle(2,4,b+35,65);
    glColor3ub(255, 255, 204);
    circle(2,4,b+75,75);


    glColor3ub(0,0,0);          //....chaka....back
    circle(5,10,b+25,55);
    glColor3ub(255,255,255);
    circle(3,6,b+25,55);

    glColor3ub(0,0,0);
    circle(5,10,b+78,55);
    glColor3ub(255,255,255);
    circle(3,6,b+78,55);

    glColor3ub(255, 81, 76);
    glRasterPos2i(b+40,65);

    glutPostRedisplay();
    glutSwapBuffers();


    ///***Bus 2***///


    if(c<= 1000)
        c = c + 0.2;
    else
        c = -450;

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(c+90,88);  ///bus front...................
    glVertex2f(c+95,88);
    glVertex2f(c+95,100);
    glVertex2f(c+90,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(26, 26, 0);
    glVertex2f(c+94,89);   // bus font glass
    glVertex2f(c+96,89);
    glVertex2f(c+96,100);
    glVertex2f(c+94,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(c+10,80);  //.....bus
    glVertex2f(c+90,80);
    glVertex2f(c+90,105);
    glVertex2f(c+10,105);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(c+10,55);  //top..........lowerpart
    glVertex2f(c+92,55);
    glVertex2f(c+92,80);
    glVertex2f(c+10,80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(c+11,81);  //top..........
    glVertex2f(c+89,81);
    glVertex2f(c+89,102);
    glVertex2f(c+11,102);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(c+12,85);  //window..........
    glVertex2f(c+20,85);
    glVertex2f(c+20,100);
    glVertex2f(c+12,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(c+22,85);  //window..........
    glVertex2f(c+30,85);
    glVertex2f(c+30,100);
    glVertex2f(c+22,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(c+32,85);  //window..........
    glVertex2f(c+40,85);
    glVertex2f(c+40,100);
    glVertex2f(c+32,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(c+42,85);  //window..........
    glVertex2f(c+50,85);
    glVertex2f(c+50,100);
    glVertex2f(c+42,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(c+52,85);  //window..........
    glVertex2f(c+60,85);
    glVertex2f(c+60,100);
    glVertex2f(c+52,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(c+62,55);  //..door..........
    glVertex2f(c+70,55);
    glVertex2f(c+70,95);
    glVertex2f(c+62,95);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(c+72,85);  //window..........
    glVertex2f(c+80,85);
    glVertex2f(c+80,100);
    glVertex2f(c+72,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(c+82,85);  //window..........
    glVertex2f(c+88,85);
    glVertex2f(c+88,100);
    glVertex2f(c+82,100);
    glEnd();

    glColor3ub(255, 255, 204);          //....chaka....back
    circle(4,8,c+45,65);
    glColor3ub(255, 255, 204);
    circle(2,4,c+55,75);
    glColor3ub(255, 255, 204);
    circle(3,6,c+15,75);
    glColor3ub(255, 255, 204);
    circle(2,4,c+35,65);
    glColor3ub(255, 255, 204);
    circle(2,4,c+75,75);


    glColor3ub(0,0,0);          //....chaka....back
    circle(5,10,c+25,55);
    glColor3ub(255,255,255);
    circle(3,6,c+25,55);

    glColor3ub(0,0,0);
    circle(5,10,c+78,55);
    glColor3ub(255,255,255);
    circle(3,6,c+78,55);


    glutPostRedisplay();
    glutSwapBuffers();


    ///***Bottom Tree***///

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree1   ///
    glColor3ub(75,35,5);
    glVertex3f(880,0,0);
    glVertex3f(885,0,0);
    glVertex3f(885,20,0);
    glVertex3f(880,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(875,10,0);
    glVertex3f(890,10,0);
    glVertex3f(882.5,40,0);
    glVertex3f(882.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(876,15,0);
    glVertex3f(889,15,0);
    glVertex3f(882.5,45,0);
    glVertex3f(882.5,45,0);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree2   ///
    glColor3ub(75,35,5);
    glVertex3f(780,0,0);
    glVertex3f(785,0,0);
    glVertex3f(785,20,0);
    glVertex3f(780,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(775,10,0);
    glVertex3f(790,10,0);
    glVertex3f(782.5,40,0);
    glVertex3f(782.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(776,15,0);
    glVertex3f(789,15,0);
    glVertex3f(782.5,45,0);
    glVertex3f(782.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree3   ///
    glColor3ub(75,35,5);
    glVertex3f(680,0,0);
    glVertex3f(685,0,0);
    glVertex3f(685,20,0);
    glVertex3f(680,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(675,10,0);
    glVertex3f(690,10,0);
    glVertex3f(682.5,40,0);
    glVertex3f(682.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(676,15,0);
    glVertex3f(689,15,0);
    glVertex3f(682.5,45,0);
    glVertex3f(682.5,45,0);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree4   ///
    glColor3ub(75,35,5);
    glVertex3f(580,0,0);
    glVertex3f(585,0,0);
    glVertex3f(585,20,0);
    glVertex3f(580,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(575,10,0);
    glVertex3f(590,10,0);
    glVertex3f(582.5,40,0);
    glVertex3f(582.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(576,15,0);
    glVertex3f(589,15,0);
    glVertex3f(582.5,45,0);
    glVertex3f(582.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree5   ///
    glColor3ub(75,35,5);
    glVertex3f(480,0,0);
    glVertex3f(485,0,0);
    glVertex3f(485,20,0);
    glVertex3f(480,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(475,10,0);
    glVertex3f(490,10,0);
    glVertex3f(482.5,40,0);
    glVertex3f(482.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(476,15,0);
    glVertex3f(489,15,0);
    glVertex3f(482.5,45,0);
    glVertex3f(482.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree6   ///
    glColor3ub(75,35,5);
    glVertex3f(380,0,0);
    glVertex3f(385,0,0);
    glVertex3f(385,20,0);
    glVertex3f(380,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(375,10,0);
    glVertex3f(390,10,0);
    glVertex3f(382.5,40,0);
    glVertex3f(382.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(376,15,0);
    glVertex3f(389,15,0);
    glVertex3f(382.5,45,0);
    glVertex3f(382.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree7   ///
    glColor3ub(75,35,5);
    glVertex3f(280,0,0);
    glVertex3f(285,0,0);
    glVertex3f(285,20,0);
    glVertex3f(280,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(275,10,0);
    glVertex3f(290,10,0);
    glVertex3f(282.5,40,0);
    glVertex3f(282.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(276,15,0);
    glVertex3f(289,15,0);
    glVertex3f(282.5,45,0);
    glVertex3f(282.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree8   ///
    glColor3ub(75,35,5);
    glVertex3f(180,0,0);
    glVertex3f(185,0,0);
    glVertex3f(185,20,0);
    glVertex3f(180,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(175,10,0);
    glVertex3f(190,10,0);
    glVertex3f(182.5,40,0);
    glVertex3f(182.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(176,15,0);
    glVertex3f(189,15,0);
    glVertex3f(182.5,45,0);
    glVertex3f(182.5,45,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  ///Bottom tree9   ///
    glColor3ub(75,35,5);
    glVertex3f(80,0,0);
    glVertex3f(85,0,0);
    glVertex3f(85,20,0);
    glVertex3f(80,20,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(75,10,0);
    glVertex3f(90,10,0);
    glVertex3f(82.5,40,0);
    glVertex3f(82.5,40,0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(76,15,0);
    glVertex3f(89,15,0);
    glVertex3f(82.5,45,0);
    glVertex3f(82.5,45,0);
    glEnd();
    ///End///


    glFlush();
}
///========================///
///*** Speed & Movement ***///
///========================///



void move_right()
{



    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000)
    {
        cx = -300;
    }
    if(bx>1000)
    {
        bx= -400;

    }
    if(cx>1000)
    {
        cx= -400;

    }
    if(dx>1000)
    {
        dx= -500;

    }


    glutPostRedisplay();
}
void move_left()
{



    spin = spin -.1;
    ax = ax - .05;
    bx = bx - .08;
    cx = cx - .10;
    dx = dx - .15;

    if(cx>1000)
    {
        cx = +300;
    }
    if(bx>1000)
    {
        bx= +400;

    }
    if(cx>1000)
    {
        cx= +400;

    }
    if(dx>1000)
    {
        dx= +500;

    }


    glutPostRedisplay();
}



void mouse(int key, int state, int x, int y)
{
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_left);
        }
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(1000, 500);
    glutCreateWindow("villege project");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
