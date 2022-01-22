#include <stdio.h>
#include <math.h>

int main(void){
    int x, cosx;
    scanf("%d", &x);
    cosx = 1 - ((x*x)/2) + ((pow(x, 4))/(2*3*4)) - ((pow(x, 6))/(2*3*4*5*6));
    printf("%f %f\n", cosx, cos(x));
}