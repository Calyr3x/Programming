#include <stdio.h>
#include <math.h>

long long factorial(int n) {
    return n ? n * factorial(n - 1) : 1;
}

long long binc(int n, int k){
    return factorial(n)/(factorial(k)*factorial(n-k));
}

int main(void){
    int x, n, t, binSum = 1;
    printf(">");
    scanf("%d", &x);
    printf(">");
    scanf("%d", &n);
    printf(">");
    scanf("%d", &t);
    for(int i = 1; i <= n; i++){
        if(binc(n, i)*pow(x, i) < abs(t)) binSum += binc(n, i)*pow(x, i);
        else break;
    }
    printf("%d %lf\n", binSum, pow(1+x,n));
}