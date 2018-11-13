#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int mat[1000][1000]={0},l=1000,b=1000;
void dda(int x1,int x2,int y1,int y2)
{
    float x=x1,y=y1,dx,dy;
    int m,i;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
        m=abs(dx);
    else
        m=abs(dy);
    dy=dy/m;
    dx=dx/m;
    for(i=0;i<=m;i++)
    {
        mat[(int)(y+0.5)][(int)(0.5+x)]=124;

        x=(x+dx);
        y=(y+dy);

    }
}

int main()
{
    int xc,yc,x[7],y[7],temp,i,j,k,xi[6],p;
    float s[6],dx,dy,r,h=30*3.14/180;
    printf("Enter xc,yc,r :");
    scanf("%d%d%f",&xc,&yc,&r);

    x[0]=xc;
    y[0]=yc-r;

    x[1]=xc+r*cos(h);
    y[1]=yc-r*sin(h);

    x[2]=xc+r*cos(h);
    y[2]=yc+r*sin(h);

    x[3]=xc;
    y[3]=yc+r;

    x[4]=xc-r*cos(h);
    y[4]=yc+r*sin(h);

    x[5]=xc-r*cos(h);
    y[5]=yc-r*sin(h);

    x[6]=x[0];
    y[6]=y[0];



     for(i=0;i<6;i++)
    {
        dx=x[i+1]-x[i];
        dy=y[i+1]-y[i];
        if(dx==0)
            s[i]=0;
        if(dy!=0 && dx!=0)
            s[i]=dx/dy;
   }

     p=0;
   while(p<b)
   {
       k=0;
        for(i=0;i<6;i++)
        {

        if( ((y[i]<=p)&&(y[i+1]>p))||
        ((y[i]>p)&&(y[i+1]<=p)))
        {
        xi[k]=(int)(x[i]+s[i]*(p-y[i]));
        k++;
        }
        }

        for(j=0;j<k-1;j++) /*- Arrange x-intersections in order -*/
        for(i=0;i<k-1;i++)
        {
        if(xi[i]>xi[i+1])
        {
        temp=xi[i];
        xi[i]=xi[i+1];
        xi[i+1]=temp;
        }
        }


        if(k>0)
        {
        for(i=0;i<k-1;i++)
        {
            int c=xi[i]+1;
            while(c<=xi[i+1])
            {
                mat[p][c]=255;
                c++;
            }
        }
        }

        p++;

   }
    for(i=0;i<6;i++)
        dda(x[i],x[i+1],y[i],y[i+1]);

       FILE* scanline;
    scanline=fopen("scanline.pgm","wb");

    fprintf(scanline,"P2\n");
    fprintf(scanline,"%d %d\n",l,b);
    fprintf(scanline,"255\n");


    for(i=0;i<l;i++)
    {
        for(j=0;j<b;j++)
        {
            temp=mat[i][j];
           fprintf(scanline,"%d ",temp);
        }
        fprintf(scanline,"\n");
    }

    fclose(scanline);
    return 0;
}
