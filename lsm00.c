#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double urandom(double x);

double Data[10][2]={
  0.000000, -0.360751,
  1.000000, 3.422468,
  2.000000, 3.867603,
  3.000000, 5.806240,
  4.000000, 7.353411,
  5.000000, 12.209795,
  6.000000, 13.659109,
  7.000000, 13.927082,
  8.000000, 17.888901,
  9.000000, 18.784120
};

main()
{
  short i,j;
  double J,a,b,x,y;
  //printf("%f,%f\n",Data[0][0],Data[0][1]);
  for (i=0;i<10000;i++){
    J=0.0;
    a=urandom(5.0);
    b=urandom(5.0);
    for(j=0;j<10;j++){
      x=Data[j][0];
      y=Data[j][1];
      J=J+pow(a*x+b-y,2.0);
    }
    printf("%f %f %f\n",a,b,J);
  }
}

double urandom(double x){
  return x*(1.0-2.0*rand()/RAND_MAX);
}


