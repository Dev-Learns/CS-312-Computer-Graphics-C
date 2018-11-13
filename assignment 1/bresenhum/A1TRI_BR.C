//draw triangle by using bresenhum algo
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
 void slope_less(int,int,int,int);
 void slope_grt(int,int,int,int);
int check(int x1,int y1,int x2,int y2,int x3,int y3)
{
 float d1,d2,d3;
	d1 = sqrt(abs((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
	d2 = sqrt(abs((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)));
	d3 = sqrt(abs((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3)));

	if(((d1+d2)<=d3) || ((d1+d3)<=d2) || ((d2+d3)<=d1))
	{
		return 0;
	}
	return 1;

}

void draw_l(int x1,int y1,int x2,int y2)
{
	if (abs(y2 - y1) < abs(x2 - x1))
	{
		if (x1 > x2)
		{
			slope_less(x2, y2, x1, y1);
		}
		else
		{
			slope_less(x1, y1, x2, y2);
		}
	}
	else
	{
		if (y1 > y2)
		{
			slope_grt(x2, y2, x1, y1);
		}
		else
		{
			slope_grt(x1, y1, x2, y2);
		}
	}


}


void slope_less(int x1,int y1,int x2,int y2)
{
int dx, dy, x, y, yin, p;

	dx = x2 - x1;
	dy = y2 - y1;
	yin = 1;

	if ( dy < 0)
	{
		yin = -1;
		dy = -dy;
	}

	p = 2*dy - dx;
	y = y1;

	for (x = x1; x <= x2; x++)
	{
		putpixel(x, y, RED);
		if ( p > 0)
		{
			y = y + yin;
			p = p + 2*dy - 2*dx;
		}
		else{
			p = p + 2*dy;
		}
		delay(25);
	}


}

void slope_grt(int x1,int y1,int x2,int y2)

{
	int x, y, dx, dy, p, xin;

	dx = x2 - x1;
	dy = y2 - y1;
	xin = 1;

	if ( dx < 0)
	{
		xin = -1;
		dx = -dx;
	}

	p = 2*dx - dy;
	x = x1;

	for( y = y1; y <= y2; y++)
	{
		putpixel(x, y, RED);
		if( p > 0)
		{
			x = x + xin;
			p = p + 2*dx- 2*dy;
		}
		else
		{
			p = p + 2*dx;
		}
		delay(25);
	}

}


void main()
{
	int x1,y1,x2,y2,x3,y3;
	int gd=DETECT,gm;
       initgraph(&gd,&gm,"C:\\TC\\BGI");
	printf("enter the value of (x1 y1):\n");
	scanf("%d %d",&x1,&y1);
	printf("enter the value of (x2 y2):\n");
	scanf("%d %d",&x2,&y2);
	printf("enter the value of (x3 y3):\n");
	scanf("%d %d",&x3,&y3);

clrscr();
if (check(x1, y1, x2, y2, x3, y3))
	{
		draw_l(x1, y1, x2, y2);
		draw_l(x2, y2, x3, y3);
		draw_l(x3, y3, x1, y1);
	}
	else
	{
		printf("A triangle can't be drawn from the given points\n");

	}

	delay(4000);

	closegraph();

}


