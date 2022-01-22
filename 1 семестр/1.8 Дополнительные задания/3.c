#include <stdio.h>
#include <math.h>

int factorial(int n) {
    return n ? n * factorial(n - 1) : 1;
}

int main(void){
    int e, n = 0;
    int tp = 1;
    long long fp = 4;
    double sp;
    double x, sq = 0;
    scanf("%lf", &x);
    sp = x;
    if(fabs(x) < 1){
        scanf("%d", &e);
        for(int i = 0; i < e; i++){
            sq += tp*((factorial(2*n))/((1-2*n)*factorial(n)*factorial(n)
            *fp))*sp;
            n++;
            fp *= 4;
            sp *= x;
            tp *= -1;
            printf("%d %lf\n", n, sq);
        }
        printf("%lf %lf\n", sq, sqrt(1+x));
    }
    else printf("|%lf| > 1\n", x);
}