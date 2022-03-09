#include<stdio.h>
#include<math.h>
#define EPS 1e-9

double func(double x)
{
  return x*x*x+4*x*x-10;
}
void bisection(double a, double b)
{
int count=0;
   if (func(a)*func(b)>=0)
  {
   printf("no solution");
   return;
   }

   double c=a;

   while ((b-a)>EPS)
   {
      c=(a+b)/2;
        count++;
      if(func(c)==0.0)
      {
        break;
      }

      else if(func(c)*func(a)<0)
      {
        b=c;
      }

      else
      {
        a=c;
      }
//count++;

}


   printf("root is %.9lf",c);
   printf("\niteration %d",count);


   }

int main()
{
   double a=1,b=2;
   bisection(a,b);
   return 0;
}


