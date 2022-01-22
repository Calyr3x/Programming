#include <stdio.h>

int main(){
    double a;
    int b;
    double *c;
    int *d;
    char *e;
    c = &a;
    d = &b;
    printf("&b = %p \nc, d, e = %lf %d %c \n&c, &d, &e = %p %p %p \n*c, *d, *e = %lf %d %c\n", 
    &b, c, d, e, &c, &d, &e, *c, *d, *e);
    printf("\n%d %d %d\n", sizeof(c), sizeof(d), sizeof(e));
}