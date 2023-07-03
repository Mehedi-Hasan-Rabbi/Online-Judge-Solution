#include<stdio.h>
int main (void)
{
    double A,B,C,MEDIA;
    scanf("%lf %lf %lf", &A,&B,&C);
    A = A * 2;
    B = B * 3;
    C = C * 5;
    MEDIA =(A+B+C) / 10;
    printf("MEDIA = %0.1lf\n",MEDIA);
    return 0;
}