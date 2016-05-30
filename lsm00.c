#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double urandom(double x);

double Data[50][2]={
  0.000000,-0.360751,
  1.000000,3.422468,
  2.000000,3.867603,
  3.000000,5.806240,
  4.000000,7.353411,
  5.000000,12.209795,
  6.000000,13.659109,
  7.000000,13.927082,
  8.000000,17.888901,
  9.000000,18.784120,
  10.000000,21.090412,
  11.000000,22.484516,
  12.000000,25.540862,
  13.000000,26.946396,
  14.000000,27.191081,
  15.000000,29.335220,
  16.000000,32.457153,
  17.000000,34.130812,
  18.000000,38.433590,
  19.000000,38.572124,
  20.000000,42.934798,
  21.000000,44.028453,
  22.000000,46.451074,
  23.000000,45.783293,
  24.000000,50.373284,
  25.000000,51.396222,
  26.000000,54.480838,
  27.000000,56.564765,
  28.000000,55.004302,
  29.000000,60.126972,
  30.000000,60.948270,
  31.000000,61.643551,
  32.000000,64.549441,
  33.000000,67.815874,
  34.000000,68.449791,
  35.000000,70.902851,
  36.000000,73.025668,
  37.000000,73.108900,
  38.000000,77.829933,
  39.000000,77.914569,
  40.000000,80.893020,
  41.000000,81.920345,
  42.000000,85.399086,
  43.000000,85.433882,
  44.000000,89.866741,
  45.000000,91.590167,
  46.000000,91.769102,
  47.000000,93.323894,
  48.000000,98.720979,
  49.000000,97.202692
};

main()
{
  long i,j;
  double J,a,b,x,y;
  //printf("%f,%f\n",Data[0][0],Data[0][1]);
  for (i=0;i<100000;i++){
    J=0.0;
    a=2.0+urandom(1.0);
    b=1.0+urandom(5.0);
    for(j=0;j<50;j++){
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


