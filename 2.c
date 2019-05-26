#include<stdio.h>
#include<GL/glut.h>
GLfloat tri[3][3]={{200,200,0},{400,200,0},{300,400,0}};
GLfloat arbx=200,arby=200;
GLfloat rotangle;
void init()
{

glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,500,0,500);

}
void draw_tri()
{
glBegin(GL_LINE_LOOP);
glVertex3fv(tri[0]);
glVertex3fv(tri[1]);
glVertex3fv(tri[2]);
glEnd();
}
void display()
{glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(arbx,arby,0.0);
glRotatef(rotangle,0.0,0.0,1.0);
glTranslatef(-arbx,-arby,0.0);
glColor3f(0,1,0);
draw_tri();
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glColor3f(1,0,0);
draw_tri();
glFlush();
}
int main(int argc,char **argv)
{
printf("enter rotation angle\n");
scanf("%f",&rotangle);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("triangle rotation");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

