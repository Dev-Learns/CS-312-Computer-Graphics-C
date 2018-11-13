#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int M[100][100];
void drawcircle(int,int,int);
void drawsemi_r(int,int,int);
void drawsemi_l(int,int,int);
void drawline(int ,int ,int, int);
int main()
{
	int x1,y1,r,i,j,temp;

    for(i=0;i<100;i++)
    for (j=0;j<100;j++)
        M[i][j]=0;

	printf("entre the centre of the circle: (x1,y1):\n");
	scanf("%d%d",&x1,&y1);
	printf("enter the radius\n");
	scanf("%d",&r);
	drawcircle(x1,y1,r);
	drawsemi_r(x1-2*r,y1,r);
	drawsemi_l(x1+2*r,y1,r);
	drawline(x1-3*r,y1,x1+3*r,y1);

     FILE* circle;
    circle = fopen("circle.pgm", "wb");

    // Writing Magic Number to the File
    fprintf(circle, "P2\n");

    // Writing Width and Height
    fprintf(circle, "%d %d\n", 100, 100);

    // Writing the maximum gray value
    fprintf(circle, "255\n");
    int count = 0;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            temp = M[j][i];
            fprintf(circle, "%d ", temp);
        }
        fprintf(circle, "\n");
    }
    fclose(circle);



	return 0;
}
void drawcircle(int a,int b,int c)
{
	int x0,y0;
	float pk;
	x0=0;
	y0=c;
	pk=1.25-c;

	while(x0<=y0)
	{

	if(pk>=0)
	{
		x0=x0+1;
		y0=y0-1;
		pk=pk+2*x0+1-2*y0;
	}
	else
	{
		x0=x0+1;
		y0=y0;
		pk=pk+2*x0+1;
	}
	if(x0>y0)
		break;

		M[x0+a][y0+a]=255;
	M[-x0+a][y0+b]=255;
	M[x0+a][-y0+b]=255;
	M[-x0+a][-y0+b]=255;

		M[y0+a][x0+b]=255;
		M[-y0+a][x0+b]=255;
		M[y0+a][-x0+b]=255;
		M[-y0+a][-x0+b]=255;

	}
}
void drawsemi_r(int a,int b,int c)
{
       int x0,y0;
	float pk;
	x0=0;
	y0=c;
	pk=1.25-c;

	while(x0<=y0)
	{

	if(pk>=0)
	{
		x0=x0+1;
		y0=y0-1;
		pk=pk+2*x0+1-2*y0;
	}
	else
	{
		x0=x0+1;
		y0=y0;
		pk=pk+2*x0+1;
	}
	if(x0>y0)
		break;
	M[x0+a][-y0+b]=255;
	M[-x0+a][-y0+b]=255;
	M[y0+a][-x0+b]=255;
	M[-y0+a][-x0+b]=255;
	}

}
void drawsemi_l(int a,int b,int c)
{
      int x0,y0;
	float pk;
	x0=0;
	y0=c;
	pk=1.25-c;

	while(x0<=y0)
	{

	if(pk>=0)
	{
		x0=x0+1;
		y0=y0-1;
		pk=pk+2*x0+1-2*y0;
	}
	else
	{
		x0=x0+1;
		y0=y0;
		pk=pk+2*x0+1;
	}
	if(x0>y0)
		break;
	M[x0+a][y0+b]=255;
	M[-x0+a][y0+b]=255;
	M[y0+a][x0+b]=255;
	M[-y0+a][x0+b]=255;
      }
}


void drawline(int m,int n,int o,int p)
{
	int dx,dy,s,x_in,y_in;
	int i;
	dx=(o-m);
	dy=(p-n);
	if(dx==0)
	{
		x_in=0;
		if(n<p)
		y_in=1;
		else
		y_in=-1;
		s=abs(p-n);
	}
	else if(dy==0)
	{
		y_in=0;
		if(m<o)
		x_in=1;
		else
		x_in=-1;
		s=abs(o-m);
	}
	else
	{
	if(abs(dx)>abs(dy))
		s=abs(dx);
	else
		s=abs(dy);
	x_in=(dx/s);
	y_in=(dy/s);
	}
	for(i=0;i<s;i++)
	{
		m=m+x_in;
		n=n+y_in;
		M[m][n]=255;
	}
}
