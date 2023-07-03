#include<stdio.h>
int main (void)
{
    double A,n,r;
    n = 3.14159;
    scanf("%lf", &r);
    A = n*(r*r);
    printf("A=%0.4lf\n",A);
    return 0;
}