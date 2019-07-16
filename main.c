#include <Windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define dx 15
#define dy 25
#define fi 4
float theta;
static int window;
static int menu_id;
static int submenu_id;
static int submenu_id1;
static int value = 0;
void *currentfont;
int choice=1;
void setFont(void *font)
{
	currentfont=font;
}
int flag=0;
void drawstring(float x,float y,float z,char *string) //to display text messages
{
    char *c;
	glRasterPos3f(x,y,z);
    for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}
void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
    glutPostRedisplay();
}
void info(){
    //char data[50] = "IP : 192.168.0.154";
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1.0,0.0,0.0);
    drawstring(145.0,400.0,0.0,"IP : 192.168.0.154");
    drawstring(145.0,370.0,0.0,"System : Windows");
    glColor3f(1.0,0.0,0.0);
    drawstring(5.0,235.0,0.0,"IP : 192.168.0.255");
    drawstring(5.0,205.0,0.0,"System : MAC");
    glColor3f(1.0,0.0,0.0);
    drawstring(145.0,80.0,0.0,"IP : 192.168.0.11");
    drawstring(145.0,50.0,0.0,"System : Linux");
}
void createMenu(void){
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("1 to 2",3);
    glutAddMenuEntry("1 to 3",4);
    glutAddMenuEntry("2 to 3",5);
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Info", 1);
    glutAddSubMenu("Connect",submenu_id);
    glutAddMenuEntry("Disconnect",6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void createMenu1(void){
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("COM 1",10);
    glutAddMenuEntry("COM 2",11);
    glutAddMenuEntry("COM 3",12);
    menu_id = glutCreateMenu(menu);
   // glutAddMenuEntry("List", 7);
    //glutAddMenuEntry("Connect-to",8);
    glutAddSubMenu("Show-Active",submenu_id);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}
void title()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.1,0.2);
    glVertex2i(0,500);
    glColor3f(0.0,0.0,0.0);
    glVertex2i(0,0);
    glColor3f(0.0,0.0,0.0);
    glVertex2i(500,0);
    glColor3f(0.0,0.1,0.2);
    glVertex2i(500,500);
	glEnd();

    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(140.0,400.0,1.0," C O M P U T E R   G R A P H I C S   M I N I  P R O J E C T ");

    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,0.0,1.0);
	drawstring(170.0,335.0,1.0," N  E  T  W  O  R  K       M  A  P  P  I  N  G ");

    glColor3f(1.0,1.0,1.0);
	drawstring(210.0,265.0,1.0,"SUBMITTED   BY");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,230.0,1.0," CHANNABASAVA H	              1PE16CS045");

	glColor3f(0.0,1.0,1.0);
	drawstring(180.0,210.0,1.0," KARTHIK DAKDAR                1PE16CS067");

	glColor3f(1.0,1.0,1.0);
	drawstring(190.0,150.0,1.0,"UNDER THE GUIDANCE OF");

	glColor3f(0.0,1.0,1.0);
	drawstring(70.0,120.0,1.0,"Prof SHUBHA K RAJ ");

    setFont(GLUT_BITMAP_HELVETICA_12);
    glColor3f(0.0,1.0,1.0);
	drawstring(70.0,105.0,1.0,"  Asst.Prof, Dept of CSE");

	glColor3f(0.0,1.0,1.0);
	drawstring(70.0,90.0,1.0,"  PESIT,BANGALORE");

    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0.0,1.0,1.0);
	drawstring(280.0,120.0,1.0,"         Prof LAKSHMI NAGAPRASANNA ");
	setFont(GLUT_BITMAP_HELVETICA_12);

    glColor3f(0.0,1.0,1.0);
	drawstring(285.0,105.0,1.0,"          Asst.Prof Dept of CSE");

	glColor3f(0.0,1.0,1.0);
	drawstring(285.0,90.0,1.0,"          PESIT,BANGALORE");

    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(400.0,450.0,1.0," Press C to continue");
	glFlush();
}
void text()
{
     setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
	drawstring(400.0,450.0,1.0," Press C to continue");
}
void display1(void){
    glClear(GL_COLOR_BUFFER_BIT);
    computers();
    createMenu();
    createMenu1();
    servers();
    if(value==1) {
        info();
    }
    else if(value==3){
        connect1_2();
    }
    else if(value==4){
        connect1_3();
    }
    else if(value==5){
        connect2_3();
    }
    else if(value==10){
        move1();
    }
    else if(value==11){
        move2();
    }
    else if(value==12){
        move3();
    }
    else if(value==6){
        glFlush();
    }
glFlush();
 }
//Computers
void computer(int a,int b)
{
    glColor3f(0.0,1.0,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(a+107,b+387);
	glVertex2f(a+107,b+405);
	glVertex2f(a+128,b+405);
	glVertex2f(a+128,b+387);
	glEnd();
	glFlush();

    glColor3f(1.0,0.0,0.0);// INNER monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(a+109,b+389);
	glVertex2f(a+109,b+403);
	glVertex2f(a+126,b+403);
	glVertex2f(a+126,b+389);
	glEnd();
	glFlush();

	glColor3f(0.7,0.0,0.2);//vertical stand
	glBegin(GL_LINES);
	glVertex2f(a+112,b+387);
	glVertex2f(a+112,b+380);
	glVertex2f(a+123,b+380);
	glVertex2f(a+123,b+387);
	glEnd();
	glFlush();

	glColor3f(0.0,0.0,1.0); //horizontal stand
	glBegin(GL_QUADS);
	glVertex2f(a+105,b+379);
	glVertex2f(a+105,b+383);
	glVertex2f(a+130,b+383);
	glVertex2f(a+130,b+379);

    glEnd();
	glFlush();

    //CPU
    glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,1.0);
	glVertex2f(a+103,b+379);
	glVertex2f(a+103,b+369);
	glVertex2f(a+132,b+369);
	glVertex2f(a+132,b+379);
	glEnd();
	glFlush();

    glColor3f(0.0,0.0,0.0);  //CPU CD DRIVE
	glBegin(GL_QUADS);
	glVertex2f(a+107,b+373);
	glVertex2f(a+107,b+376);
	glVertex2f(a+114,b+376);
	glVertex2f(a+114,b+373);
	glEnd();
	glFlush();

    glColor3f(0.0,0.0,0.0);  //CPU USB
	glBegin(GL_QUADS);
	glVertex2f(a+123,b+373);
	glVertex2f(a+123,b+376);
	glVertex2f(a+127,b+376);
	glVertex2f(a+127,b+373);
	glEnd();
	glFlush();
}
void box(int a,int b)
{
    glColor3f(0.0,0.0,1.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(a+60,b+100);
	glVertex2f(a+60,b+150);
	glVertex2f(a+95,b+150);
	glVertex2f(a+95,b+100);
	glEnd();
    glColor3f(0.0,1.0,0.0);// INNER monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(a+58,b+97);
	glVertex2f(a+58,b+153);
	glVertex2f(a+97,b+153);
	glVertex2f(a+97,b+97);
	glEnd();

    glColor3f(0.7,0.2,0.8);
	glBegin(GL_LINES);
	glVertex2f(135,357);
	glVertex2f(168,250);

	glVertex2f(135,93);
	glVertex2f(168,197);

	glVertex2f(105,225);
	glVertex2f(168,225);

	glVertex2f(207,225);
	glVertex2f(258,225);

	glVertex2f(297,225);
	glVertex2f(348,225);

	glVertex2f(297,253);
	glVertex2f(329,357);

	glVertex2f(297,197);
	glVertex2f(329,93);
    glEnd();
	glLineWidth(2.0f);
	glFlush();
    wifidisk();
}
//Router
void wifidisk(int a)
{
    glColor3f(1.0,0.0,1.0);
    //router
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
	glVertex2f(173,204);
	glVertex2f(173,211);
	glVertex2f(203,211);
	glVertex2f(203,204);
	glEnd();
	glFlush();
	cir(176,207);
	cir(181,207);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(194,206);
	glVertex2f(194,209);
	glVertex2f(202,209);
	glVertex2f(202,206);
	glEnd();
	glFlush();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(186,211);
	glVertex2f(186,231);
	glVertex2f(189,231);
	glVertex2f(189,211);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(264,208);
	glVertex2f(291,208);
    glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
    for(int i=0;i<360;i++)
    {
        theta=i*3.142/180;
        glVertex2f(265+3*cos(theta),218+10*sin(theta));
    }
    glEnd();
    glLineWidth(3.0f);
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    for(int i=0;i<360;i++)
    {
        theta=i*3.142/180;
        glVertex2f(278+11*cos(theta),227+14*sin(theta));
    }
    glEnd();
    glLineWidth(3.0f);
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    for(int i=270;i<590;i++)
    {
        theta=i*3.142/180;
        glVertex2f(291+3*cos(theta),218+10*sin(theta));
    }
    glEnd();
    glLineWidth(3.0f);
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    for(int i=0;i<360;i++)
    {
        theta=i*3.142/180;
        glVertex2f(278+13*cos(theta),219+11*sin(theta));
    }
    glEnd();
    glLineWidth(3.0f);
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
	glVertex2f(265,208);
	glVertex2f(265,214);
	glVertex2f(290,214);
	glVertex2f(290,208);
	glEnd();
	glFlush();
}
void servers()
{
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(333,367);
	glVertex2f(333,400);
	glVertex2f(342,400);
	glVertex2f(342,367);
	glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(342.5,363);
	glVertex2f(342.5,408);
	glVertex2f(354,408);
	glVertex2f(354,363);
	glEnd();
	glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(354.5,367);
	glVertex2f(354.5,400);
	glVertex2f(364,400);
	glVertex2f(364,367);
	glEnd();
	glFlush();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(351,208);
	glVertex2f(351,241);
	glVertex2f(360.5,241);
	glVertex2f(360.5,208);
	glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(361,204);
	glVertex2f(361,248);
	glVertex2f(373,248);
	glVertex2f(373,204);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(373.5,208);
	glVertex2f(373.5,241);
	glVertex2f(383.5,241);
	glVertex2f(383.5,208);
	glEnd();
	glFlush();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(331.5,47);
	glVertex2f(331.5,80);
	glVertex2f(341.5,80);
	glVertex2f(341.5,47);
	glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(342,43);
	glVertex2f(342,87);
	glVertex2f(354,87);
	glVertex2f(354,43);
	glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
	glVertex2f(354.5,47);
	glVertex2f(354.5,80);
	glVertex2f(364,80);
	glVertex2f(364,47);
	glEnd();
    glFlush();
}
void computers()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);
    arc(185,230,180,230,190,230,195,230);
    computer(0,-2);
    computer(-33,-162);
    computer(0,-322);
    glColor3f(0.0f,0.0f,0.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
 	drawstring(100.0,420.0,1.0,"COM-2");
	box(7,100);

	glColor3f(0.0f,0.0f,0.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
 	drawstring(57.0,255.0,1.0,"COM-1");
    box(40,260);

    glColor3f(0.0f,0.0f,0.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
 	drawstring(90.0,102.0,1.0,"COM-3");
    box(40,-60);

    glColor3f(0.0f,0.0f,0.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
 	drawstring(167.0,257.0,1.0,"Router");
    box(110,100);

    glColor3f(0.0f,0.0f,0.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
 	drawstring(257.0,257.0,1.0,"Internet");
    box(200,100);

    glColor3f(0.0f,0.0f,0.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
 	drawstring(347.0,257.0,1.0,"www.facebook.com");
    box(290,100);

    glColor3f(0.0f,0.0f,0.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
 	drawstring(327.0,418.0,1.0,"www.google.com");
    box(270,260);

    glColor3f(0.0f,0.0f,0.0f);
	setFont(GLUT_BITMAP_HELVETICA_18);
 	drawstring(327.0,100.0,1.0,"www.gmail.com");
    box(270,-60);
}
void arc(int a,int b,int c,int d,int e,int f,int g,int h)
{
    glLineWidth(3.0f);
    float theta;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    for(int i=115;i<245;i++)
    {
        theta=i*3.142/180;
        glVertex2f(a+3*cos(theta),b+6*sin(theta));
    }
    glEnd();
    glLineWidth(3.0f);
    glFlush();

    glBegin(GL_LINE_STRIP);
    for(int i=95;i<260;i++)
    {
        theta=i*3.142/180;
        glVertex2f(c+4*cos(theta),d+10*sin(theta));
    }
    glEnd();
    glFlush();
    glBegin(GL_LINE_STRIP);
    for(int i=-50;i<70;i++)
    {
        theta=i*3.142/180;
        glVertex2f(e+3*cos(theta),f+8*sin(theta));
    }
    glEnd();
    glLineWidth(3.0f);
    glFlush();

    glBegin(GL_LINE_STRIP);
    for(int i=-80;i<80;i++)
    {
        theta=i*3.142/180;
        glVertex2f(g+4*cos(theta),h+10*sin(theta));
    }
    glEnd();
    glFlush();
}
void cir(int e,int f)
{
    float theta;
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
	glColor3f(1.0,1.0,1.0);
        theta=i*3.142/180;
        glVertex2f(e+1.5*cos(theta),f+2.5*sin(theta));
    }
    glEnd();
    glFlush();
}
void connect1_2()
{
    float i,j,temp=0.2;
    for(j=31,i=12;j,i<45;j=j+temp,i=i+0.065) //movement of data packet from top to down
    {

        glColor3f(0.7,0.2,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex2i(70+i,223+j);glVertex2i(70+i,225+j);glVertex2i(72+i,225+j);glVertex2i(72+i,223+j);
        glEnd();
        glFlush();
        glColor3f(0.7,0.2,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex2i(70+i,223+j);glVertex2i(70+i,225+j);glVertex2i(72+i,225+j);glVertex2i(72+i,223+j);
        glEnd();
        glFlush();

    }
}
void connect1_3()
{
    float i,j,temp=0.2;
    for(j=0,i=12;j,i<44;j=j+temp,i=i+0.065) //movement of data packet from top to down
    {

        glColor3f(0.7,0.2,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex2i(70+i,193-j);glVertex2i(70+i,195-j);glVertex2i(72+i,195-j);glVertex2i(72+i,193-j);
        glEnd();
        glFlush();
        glColor3f(0.7,0.2,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex2i(70+i,193-j);glVertex2i(70+i,195-j);glVertex2i(72+i,195-j);glVertex2i(72+i,193-j);
        glEnd();
        glFlush();

    }
}
void connect2_3()
{
    float i,j,temp=0.2;
    for(j=0;j<258;j=j+temp) //movement of data packet from top to down
    {

        glColor3f(0.7,0.2,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex2i(125,355-j);glVertex2i(125,353-j);glVertex2i(127,353-j);glVertex2i(127,355-j);
        glEnd();
        glFlush();
        glColor3f(0.7,0.2,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex2i(125,355-j);glVertex2i(125,353-j);glVertex2i(127,353-j);glVertex2i(127,355-j);
        glEnd();
        glFlush();

    }
}
//packet movement
void move1()
{
    glColor3f(1.0,0.0,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(62,193);
	glVertex2f(62,256);
	glVertex2f(107,256);
	glVertex2f(107,193);
	glEnd();
	glColor3f(1.0,0.0,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(345,195);
	glVertex2f(345,257);
	glVertex2f(390,257);
	glVertex2f(390,195);
	glEnd();

	float i,j,temp=0.3,k=0;
    glColor3f(1.0,0.8,0.4);
    for(j=0;j<5;j=j+temp) //movement of data packet from top to down
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(85,150-j);glVertex2i(85,165-j);glVertex2i(92,165-j);glVertex2i(92,150-j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(85,150-j);glVertex2i(85,165-j);glVertex2i(92,165-j);glVertex2i(92,150-j);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(85,177-j);glVertex2i(85,192-j);glVertex2i(92,192-j);glVertex2i(92,177-j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(85,177-j);glVertex2i(85,192-j);glVertex2i(92,192-j);glVertex2i(92,177-j);
        glEnd();
        glFlush();
    }
    for(i=45;i<295;i=i+temp) //movement of data packet sidewise
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(60+i,138);glVertex2i(60+i,148);glVertex2i(70+i,148);glVertex2i(70+i,138);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(60+i,138);glVertex2i(60+i,148);glVertex2i(70+i,148);glVertex2i(70+i,138);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(40+i,138);glVertex2i(40+i,148);glVertex2i(50+i,148);glVertex2i(50+i,138);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(40+i,138);glVertex2i(40+i,148);glVertex2i(50+i,148);glVertex2i(50+i,138);
        glEnd();
        glFlush();
    }
    for(j=20;j<40;j=j+temp) //to move the  packet from bottom to top
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(365,115+j);glVertex2i(365,130+j);glVertex2i(370,130+j);glVertex2i(370,115+j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(365,115+j);glVertex2i(365,130+j);glVertex2i(370,130+j);glVertex2i(370,115+j);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(365,140+j);glVertex2i(365,155+j);glVertex2i(370,155+j);glVertex2i(370,140+j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(365,140+j);glVertex2i(365,155+j);glVertex2i(370,155+j);glVertex2i(370,140+j);
        glEnd();
        glFlush();
    }
}
void move2()
{
    glColor3f(1.0,0.0,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(95,355);
	glVertex2f(95,415);
	glVertex2f(140,415);
	glVertex2f(140,355);
	glEnd();
	glColor3f(1.0,0.0,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(325,355);
	glVertex2f(325,415);
	glVertex2f(370,415);
	glVertex2f(370,355);
	glEnd();

	float i,j,temp=0.3,k=0;
    glColor3f(1.0,0.8,0.4);
    for(j=0;j<25;j=j+temp) //movement of data packet from top to down
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(115,335-j);glVertex2i(115,350-j);glVertex2i(122,350-j);glVertex2i(122,335-j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(115,335-j);glVertex2i(115,350-j);glVertex2i(122,350-j);glVertex2i(122,335-j);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(115,307-j);glVertex2i(115,322-j);glVertex2i(122,322-j);glVertex2i(122,307-j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(115,307-j);glVertex2i(115,322-j);glVertex2i(122,322-j);glVertex2i(122,307-j);
        glEnd();
        glFlush();
    }
    for(i=45;i<252;i=i+temp) //movement of data packet sidewise
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(95+i,278);glVertex2i(95+i,288);glVertex2i(105+i,288);glVertex2i(105+i,278);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(95+i,278);glVertex2i(95+i,288);glVertex2i(105+i,288);glVertex2i(105+i,278);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(75+i,278);glVertex2i(75+i,288);glVertex2i(85+i,288);glVertex2i(85+i,278);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(75+i,278);glVertex2i(75+i,288);glVertex2i(85+i,288);glVertex2i(85+i,278);
        glEnd();
        glFlush();
    }
    for(j=20;j<57;j=j+temp) //to move the  packet from bottom to top
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(345,255+j);glVertex2i(345,270+j);glVertex2i(350,270+j);glVertex2i(350,255+j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(345,255+j);glVertex2i(345,270+j);glVertex2i(350,270+j);glVertex2i(350,255+j);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(345,280+j);glVertex2i(345,295+j);glVertex2i(350,295+j);glVertex2i(350,280+j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(345,280+j);glVertex2i(345,295+j);glVertex2i(350,295+j);glVertex2i(350,280+j);
        glEnd();
        glFlush();
    }
}
void move3()  //MOVEMENT OF FRAME 0  (in safe sending)
{
    glColor3f(1.0,0.0,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(95,34);
	glVertex2f(95,96);
	glVertex2f(140,96);
	glVertex2f(140,34);
	glEnd();
	glColor3f(1.0,0.0,0.0);//monitor
	glBegin(GL_LINE_LOOP);
	glVertex2f(325,34);
	glVertex2f(325,95);
	glVertex2f(370,95);
	glVertex2f(370,34);
	glEnd();

	float i,j,temp=0.3,k=0;
    glColor3f(1.0,0.8,0.4);
    for(j=0;j<22;j=j+temp) //movement of data packet from bottom to up
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(116,99+j);glVertex2i(116,114+j);glVertex2i(123,114+j);glVertex2i(123,99+j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(116,99+j);glVertex2i(116,114+j);glVertex2i(123,114+j);glVertex2i(123,99+j);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(116,125+j);glVertex2i(116,140+j);glVertex2i(123,140+j);glVertex2i(123,125+j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(116,125+j);glVertex2i(116,140+j);glVertex2i(123,140+j);glVertex2i(123,125+j);
        glEnd();
        glFlush();
    }
    for(i=0;i<200;i=i+temp) //movement of data packet sidewise
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(116+i,150);glVertex2i(116+i,160);glVertex2i(126+i,160);glVertex2i(126+i,150);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(116+i,150);glVertex2i(116+i,160);glVertex2i(126+i,160);glVertex2i(126+i,150);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(136+i,150);glVertex2i(136+i,160);glVertex2i(146+i,160);glVertex2i(146+i,150);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(136+i,150);glVertex2i(136+i,160);glVertex2i(146+i,160);glVertex2i(146+i,150);
        glEnd();
        glFlush();
    }
    for(j=-3;j<18;j=j+temp) //to move the  packet from bottom to top
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(346,150-j);glVertex2i(346,165-j);glVertex2i(353,165-j);glVertex2i(353,150-j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(346,150-j);glVertex2i(346,165-j);glVertex2i(353,165-j);glVertex2i(353,150-j);
        glEnd();
        glFlush();

        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(346,125-j);glVertex2i(346,140-j);glVertex2i(353,140-j);glVertex2i(353,125-j);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glVertex2i(346,125-j);glVertex2i(346,140-j);glVertex2i(353,140-j);glVertex2i(353,125-j);
        glEnd();
        glFlush();
    }
}
void mymenu(int id){
    glClear(GL_COLOR_BUFFER_BIT);
    switch(id){
        case 1 : exit(0);
        case 2 : choice = 1;
                 break;
        case 3 : choice =2;
                 break;
    }
    glutPostRedisplay();
}
void mykeyboard(unsigned char key,int x,int y)
{
    switch(key)
	{
	    case 'C':
		case 'c':flag=1;glutPostRedisplay();break;
		default:return;
	}
}
void display(void)
{	glClear(GL_COLOR_BUFFER_BIT);
    if(flag==0)
	{
        title();
        text();
	}
    if(flag==1){
        display1();

    }
}
void myInit()
{
    glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(5.0);
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glShadeModel(GL_FLAT);
    glEnable(GL_MAP1_VERTEX_3);
}
int main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
  	glutInitWindowPosition(0,0);
	glutInitWindowSize(2000,700);
    glutCreateWindow("Network Mapping");
    glutKeyboardFunc(mykeyboard);
    glutDisplayFunc(display);
    int sub_menu = glutCreateMenu(mymenu);
    glutAddMenuEntry("Mapping",2);
    glutAddMenuEntry("No of Systems",3);
    glutCreateMenu(mymenu);
    glutAddMenuEntry("EXIT",1);
    glutAddSubMenu("START",sub_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	myInit();
    glutMainLoop();
}
