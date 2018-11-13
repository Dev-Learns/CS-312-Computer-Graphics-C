// C program for DDA rectangle generation
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

//Function for finding absolute value
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}
int check(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
 int d1,d2,d3,d4,di1,di2;
 d1=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
 d2=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
 d3=(x4-x3)*(x4-x3)+(y4-y3)*(y4-y3);
 d4=(x1-x4)*(x1-x4)+(y1-y4)*(y1-y4);
 di1=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
 di2=(x2-x4)*(x2-x4)+(y2-y4)*(y2-y4);
 if((d1==d3 && d2==d4) &&(di1==di2))
 return 1;
 return 0;
}

//DDA Function
void DDA(int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
    int i;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    float X = X0;
    float Y = Y0;
    for ( i = 0; i <= steps; i++)
    {
	putpixel (X,Y,WHITE);
	X += Xinc;
	Y += Yinc;
	delay(100);

    }
}

void main()
{
    int gd = DETECT, gm;
    int x1,y1,x2,y2,x3,y3,x4,y4;
    clrscr();
    printf("enter the co-ordinate of (x1 y1): ");
    scanf("%d %d",&x1,&y1);
     printf("enter the co-ordinate of (x2 y2): ");
    scanf("%d %d",&x2,&y2);
     printf("enter the co-ordinate of (x3 y3): ");
    scanf("%d %d",&x3,&y3);
     printf("enter the co-ordinate of (x4 y4): ");
    scanf("%d %d",&x4,&y4);
    printf("<press any key >");
    getch();

    initgraph (&gd, &gm, "C:\\TC\\BGI");
    DDA(x1,y1,x2,y2);
    DDA(x2,y2,x3,y3);
    DDA(x3,y3,x4,y4);
    DDA(x4,y4,x1,y1);
    getch();
    closegraph();
}