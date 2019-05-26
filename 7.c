#include<stdio.h>
#include<GL/glut.h>
typedef float point[3];
point v[]={{0,0,1},{0,0.94289,-.33333},{-0.816497,-.471405,-0.33333},{0.814697,-0.471405,-0.333333}};
int n;
void triangle(point a,point b,point c)
{
glBegin(GL_POLYGON);
glNormal3fv(a);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glEnd();
}
void devide_triangle(point a,point b,point c,int m)
{
int j;
point v1,v2,v3;
if(m>1)
{
for(j=0;j<3;j++) v1[j]=(a[j]+b[j])/2;
for(j=0;j<3;j++) v2[j]=(a[j]+c[j])/2;
for(j=0;j<3;j++) v3[j]=(b[j]+c[j])/2;
devide_triangle(a,v1,v2,m-1);
devide_triangle(c,v2,v3,m-1);
devide_triangle(b,v3,v1,m-1);
}
else
{
triangle(a,b,c);
}
}
void tetrahedron(int m)
{
glColor3f(1.0,1.0,1.0);
devide_triangle(v[0],v[1],v[2],m);
glColor3f(0.0,1.0,1.0);
devide_triangle(v[1],v[2],v[3],m);
glColor3f(0.0,0.0,1.0);
devide_triangle(v[0],v[1],v[3],m);
glColor3f(0.0,1.0,0.0);
devide_triangle(v[0],v[2],v[3],m);
}
void myReshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
else
glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
tetrahedron(n);
glFlush();
}
int main(int argc,char** argv)
{
printf("enter no of divisions\n");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutCreateWindow("pp");
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}
