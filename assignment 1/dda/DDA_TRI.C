// C program for DDA triangle  generation
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

//Function for finding absolute value
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

//DDA Function
void DDA(int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
     int i;
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (i = 0; i <= steps; i++)
    {
	putpixel (X,Y,RED);  // put pixel at (X,Y)
	X += Xinc;
	Y += Yinc;
	delay(100);

    }
}
int check(int x1,int y1,int x2,int y2,int x3,int y3)
{
 float d1,d2,d3;
	d1 = sqrt(abs((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
	d2 = sqrt(abs((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)));
	d3 = sqrt(abs((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3)));

	if(((d1+d2)<=d3) || ((d1+d3)<=d2) || ((d2+d3)<=d1))
	{
		return 1;
	}
	return 0;
	}
void main()
{
    int gd = DETECT, gm;
    int  x1,y1,x2,y2,x3,y3;
    clrscr();
   printf("enter the value of x1 & y1: ");
   scanf("%d %d",&x1,&y1);
   printf("enter the value of x2 & y2 : ");
   scanf("%d %d",&x2,&y2);
   printf("enter the value of x3 & y3 : ");
   scanf("%d %d",&x3,&y3);
   printf("<press any key to be continue>");
   getch();
   initgraph (&gd, &gm, "C:\\TC\\BGI");
   if(check(x1,y1,x2,y2,x3,y3))
   {
   DDA(x1,y1,x2,y2);
   DDA(x2,y2,x3,y3);
   DDA(x3,y3,x1,y1);
    }
    else
    {
    printf("no triangle is posible.");
    }
    getch();
    closegraph();
}