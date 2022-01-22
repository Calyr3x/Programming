#include <stdio.h>
#include <math.h>

long long factorial(int n) {
    return n ? n * factorial(n - 1) : 1;
}

int main(void){
    int x, e, k = 3, k1, sign = -1;
    double sinx;
    scanf("%d", &x);
    scanf("%d", &e);
    sinx = x;
    while(pow(x, k)/factorial(k) > e){
        printf("%lf  %d  %lf %lld\n", (pow(x, k))/factorial(k), k, pow(x, k), factorial(k));
        sinx += sign*(pow(x, k))/factorial(k);
        sign *= -1;
        k += 2;
    }
    printf("%lf %lf\n", sinx, sin(x));
}