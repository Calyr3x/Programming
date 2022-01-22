#include <stdio.h>
#include <math.h>
//переделать
int factorial(int n) {
    return n ? n * factorial(n - 1) : 1;
}

int main(void){
    int e, n = 0;
    double x, asn = 0;
    scanf("%lf", &x);
    if(fabs(x) < 1){
        scanf("%d", &e);
        for(int i = 0; i < e; i++){
            asn += ((factorial(2*n))/((2*n+1)*factorial(n)*factorial(n)
            *pow(4,n)))*pow(x, 2*n+1);
            n++;
            printf("%d %lf\n", n, asn);
        }
        printf("%lf %lf\n", asn, asin(x));
    }
    else printf("|%lf| > 1\n", x);
}