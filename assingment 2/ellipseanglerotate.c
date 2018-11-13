#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
void ellipse(int,int,long,long,double);
int M[100][100];
#define PI 3.14159265
int main()
{

   int xc,yc,i,j,temp;
   long rx,ry;
   double val,theta;
   val = PI / 180;
   printf("Enter coordinates of centre : ");
   scanf("%d %d",&xc,&yc);
   printf("Enter rx and ry lengths of ellipse: ");
   scanf("%d %d",&rx,&ry);
   printf("Enter value of theta by which ellipse will rotate : ");
   scanf("%lf",&theta);
   for(i=0;i<100;i++)
   for(j=0;j<100;j++)
   M[i][j]=0;
   theta=-theta*val;
ellipse(xc,yc,rx,ry,theta);
    FILE* ellipse;
   ellipse = fopen("ellipse.pgm", "wb");

    // Writing Magic Number to the File
    fprintf(ellipse, "P2\n");

    // Writing Width and Height
    fprintf(ellipse, "%d %d\n", 100, 100);

    // Writing the maximum gray value
    fprintf(ellipse, "255\n");
    //int count = 0;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            temp = M[j][i];

            // Writing the gray values in the 2D array to the file
            fprintf(ellipse, "%d ", temp);
        }
        fprintf(ellipse, "\n");
         }
    fclose(ellipse);


    return 0;

}

 void ellipse(int xc,int yc,long rx,long ry,double theta)
 {
    float p,theta1;
    int x,y,xf,yf;
theta1=-theta;
x=0;
y=ry;

int x1,y1,x2,y2;
  //Region 1
   p=ry*ry-rx*rx*ry+rx*rx/4;
   x=0;y=ry;
   while(2.0*ry*ry*x <= 2.0*rx*rx*y)
   {
	if(p < 0)
	{
		x++;
		p = p+2*ry*ry*x+ry*ry;
	}
	else
	{
		x++;y--;
		p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
	}


    x1=x*cos(theta) - y*sin(theta);
    y1=x*sin(theta) + y*cos(theta);

    x2=x*cos(theta1) - y*sin(theta1);
    y2=x*sin(theta1) + y*cos(theta1);

	M[xc+x2][yc-y2]=255;
	M[xc+x1][yc+y1]=255;
	M[xc-x1][yc-y1]=255;
	M[xc-x2][yc+y2]=255;
   }

  //Region 2
   p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
   while(y > 0)
   {
	if(p <= 0)
	{
		x++;y--;
		p = p+2*ry*ry*x-2*rx*rx*y+rx*rx;
	}
	else
	{
		y--;
		p = p-2*rx*rx*y+rx*rx;
	}

    x1=x*cos(theta) - y*sin(theta);
    y1=x*sin(theta) + y*cos(theta);

    x2=x*cos(theta1) - y*sin(theta1);
    y2=x*sin(theta1) + y*cos(theta1);

	M[xc+x2][yc-y2]=255;
	M[xc+x1][yc+y1]=255;
	M[xc-x1][yc-y1]=255;
	M[xc-x2][yc+y2]=255;
   }

}
