#include<stdio.h>
#include<GL/glut.h>
int x1,x2,y1,y2;
void myInit()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,500,0,500);
}
void draw_pixel(int x,int y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void draw_line(int x1,int x2,int y1,int y2)
{
int i,e,x,y,incx,incy,inc1,inc2,dx,dy;
dx=x2-x1;
dy=y2-y1;
if(dx<0) dx=-dx;
if(dy<0) dy=-dy;
incx=1;
incy=1;

if(x2<x1) incx=-1;
if(y2<y1) incy=-1;
x=x1;y=y1;

if(dx>dy)
{
draw_pixel(x,y);
inc1=2*(dy-dx);
e=2*dy-dx;
inc2=2*dy;
for(i=0;i<dx;i++)
{
if(e>0)
{
y=y+incy;
e=e+inc1;
}
else
e=e+inc2;
x=x+incx;
draw_pixel(x,y);
}
}
else
{
draw_pixel(x,y);
inc1=2*(dx-dy);
e=2*dx-dy;
inc2=2*dx;
for(i=0;i<dy;i++)
{
if(e>0)
{
x=x+incx;
e=e+inc1;
}
else
e=e+inc2;
y=y+incy;
draw_pixel(x,y);
}
}
}
void myDisplay()
{
draw_line(x1,y1,x2,y2);
glFlush();
}
int main(int argc,char **argv)
{
printf("enter x1,y1,x2,y2");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("line draw");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}









