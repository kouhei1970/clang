#include <stdio.h>
#include <math.h>

double integ(double x, double xo, double h, double s);

struct robo {

    double x,y;
    double vx,vy,v;
    double dvx,dvy,dv;
    double theta;
    double angv;
    double dangv;
}


main()
{
    struct robo drone[2];
    short i,j;
    double h;

//Init
    for (i=0; i<2; i++) {
        drone[i].x=0.0;
        drone[i].y=0.0;
        drone[i].vx=0.0;
        drone[i].vy=0.0;
        drone[i].v=0.0;
        drone[i].dv=0.0;
        drone[i].dvx=0.0;
        drone[i].dvy=0.0;
        drone[i].theta=0.0;
        drone[i].angv=0.0;
        drone[i].dangv=0.0;
    }

    drone[1].x=1.0;
    drone[1].y=0.0;
    drone[0].v=1.0;
    drone[1].v=2.0;
    drone[0].theta=M_PI/2.0;
    drone[0].angv= M_PI/2.0;
    drone[1].angv=-M_PI/2.0;
    h=0.01;

    for (j=0; j<500; j++) {
        for (i=0; i<2; i++) {
            printf("%f %f ",drone[i].x,drone[i].y);
            drone[i].vx=cos(drone[i].theta)*drone[i].v;
            drone[i].vy=sin(drone[i].theta)*drone[i].v;
            drone[i].x=integ(drone[i].vx,drone[i].dvx,h,drone[i].x);
            drone[i].y=integ(drone[i].vy,drone[i].dvy,h,drone[i].y);
            drone[i].theta=integ(drone[i].angv,drone[i].dangv,h,drone[i].theta);

            drone[i].dvx=drone[i].vx;
            drone[i].dvy=drone[i].vy;
            drone[i].dangv=drone[i].angv;
        }
        printf("\n");

    }
}


double integ(double x, double xo, double h, double s)
{
    return s+(x + xo)*h*0.5;
}
