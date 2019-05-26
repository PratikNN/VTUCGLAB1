#include<GL/glut.h>
#define outcode int
double xmin=50,ymin=50,xmax=100,ymax=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;
const int TOP=8;
const int BOTTOM=2;
const int RIGHT=4;
const int LEFT=1;
outcode computeoutcode(double x,double y);
void cohensutherlandlineclipanddraw(double x0,double y0,double x1,double y1)
{
outcode outcode0,outcode1,outcodeout;
bool accept=false,done=false;
outcode0=computeoutcode(x0,y0);
outcode1=computeoutcode(x1,y1);
do{
if(!(outcode0|outcode1))
{
done=true;
accept=true;
} else if(outcode0&outcode1)
done=true;
else
{
double x,y;
outcodeout=outcode0?outcode0:outcode1;
if(outcodeout&TOP)
{
x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
y=ymax;
}
else if(outcodeout&BOTTOM)
{
x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
y=ymin;
}
else if(outcodeout&RIGHT)
{
y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
x=xmax;
}
else
{
y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
x=xmin;
}
if(outcodeout==outcode0)
{
x0=x;
y0=y;
outcode0=computeoutcode(x0,y0);
}
else if(outcodeout==outcode1)
{
x1=x;
y1=y;
outcode1=computeoutcode(x1,y1);
}
}
}while(!done);
if(accept)
{
double sy=(yvmax-yvmin)/(ymax-ymin);
double sx=(xvmax-xvmin)/(xmax-xmin);
double vx0=xvmin+(x0-xmin)*sx;
double vx1=xvmin+(x1-xmin)*sx;
double vy0=yvmin+(y0-ymin)*sy;
double vy1=yvmin+(y1-ymin)*sy;

glColor3f(0.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2d(xvmin,yvmin);
glVertex2d(xvmax,yvmin);
glVertex2d(xvmax,yvmax);
glVertex2d(xvmin,yvmax);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2d(vx0,vy0);
glVertex2d(vx1,vy1);
glEnd();
}
}
outcode computeoutcode(double x,double y)
{
outcode code=0;
if(y>ymax) code|=TOP;
if(y<ymin) code|=BOTTOM;
if(x>xmax) code|=RIGHT;
if(x<xmin) code|=LEFT;
return code;
}
void display()
{
double x0=60,y0=20,x1=80,y1=120;
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINES);
glVertex2d(x0,y0);
glVertex2d(x1,y1);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2d(xmin,ymin);
glVertex2d(xmax,ymin);
glVertex2d(xmax,ymax);
glVertex2d(xmin,ymax);
glEnd();
cohensutherlandlineclipanddraw(x0,y0,x1,y1);
glFlush();
}
void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,500,0,500);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutCreateWindow("aa");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

