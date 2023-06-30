#include<stdio.h>
int main(void)
{
    int test,num1,num2;
    scanf("%d",&test);
    for (int i=1;i<=test;i++)
    {
        scanf("%d %d",&num1,&num2);
        printf("Case %d: %d\n",i,num1+num2);
    }
    return 0;
}