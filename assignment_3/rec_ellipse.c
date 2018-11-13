#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void ellipse(int,int,long,long);
void pll();
int M[500][500]={0};
int xc,yc,i,j,temp,a,b;
   long rx,ry;
   float shx=.5;
int main()
{


   printf("Enter coordinates of centre : ");
   scanf("%d %d",&xc,&yc);
   printf("Enter x,y radius of ellipse: ");
   scanf("%d %d",&rx,&ry);
    printf("Enter the a & b: ");
   scanf("%d %d",&a,&b);
ellipse(xc,yc,rx,ry);
ellipse(xc,yc,rx,ry);
pll();
    FILE* rec;
    rec = fopen("rec.pgm", "wb");

    // Writing Magic Number to the File
    fprintf(rec, "P2\n");

    // Writing Width and Height
    fprintf(rec, "%d %d\n", 500, 500);

    // Writing the maximum gray value
    fprintf(rec, "255\n");
    int count = 0;
    for (i = 0; i < 500; i++) {
        for (j = 0; j < 500; j++) {
            temp = M[j][i];

            // Writing the gray values in the 2D array to the file
            fprintf(rec, "%d ", temp);
        }
        fprintf(rec, "\n");
         }
    fclose(rec);
return 0;
}
void pll()
{
    int i,j;

   for (i=0;i<=2*ry;i++)
    {


    M[xc-(a/2)-(int)(shx*i)][yc-ry+i] = 255;
    M[xc+(a/2)-(int)(shx*i)][yc-ry+i] = 255;
    M[xc - (a / 2)-(int)(shx*2*ry) + (int)(shx * i)][yc - ry + i+100] = 255;
    M[xc + (a / 2) -(int)(shx*2*ry) + (int)(shx * i)][yc - ry + i+100] = 255;
    }

for (j=0;j<=a;j++)
   {

    M[xc -(a/2)+j][yc-ry]= 255;
    M[xc -(a/2)+j-(int)(shx*i)][yc + ry] = 255;
    M[xc -(a/2)+j-(int)(shx*2*ry)][yc-ry+100] = 255;
    M[xc -(a/2)+j][yc + ry+100] = 255;
M[xc-a+2*j][yc+50]=255;
   }

}
 void ellipse(int xc,int yc,long rx,long ry)
 {
    float p;
    int x,y;
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
	M[xc+x][yc+y]=255;
	M[xc+x][yc-y]=255;
	M[xc-x][yc+y]=255;
	M[xc-x][yc-y]=255;
	//dwar dwon ellipse part
	M[xc+x][yc+y+100]=255;
	M[xc+x][yc-y+100]=255;
	M[xc-x][yc+y+100]=255;
	M[xc-x][yc-y+100]=255;
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
	M[xc+x][yc+y]=255;
	M[xc+x][yc-y]=255;
	M[xc-x][yc+y]=255;
	M[xc-x][yc-y]=255;
	//draw ellipse down part
	M[xc+x][yc+y+100]=255;
	M[xc+x][yc-y+100]=255;
	M[xc-x][yc+y+100]=255;
	M[xc-x][yc-y+100]=255;

   }
}
