#include <stdio.h>
#include <stdlib.h>

double urandom(double x);

main()
{
  short i;
  double x,y;
  for (i=0;i<10;i++)
  {
    x=i*1.0;
    y=2.0*x + 1.0 + urandom(2.0);
    printf("%f %f\n",x,y);
  }
}

double urandom(double x)
{
  return x*(1.0-2.0*rand()/RAND_MAX);
}
