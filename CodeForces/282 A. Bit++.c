#include<stdio.h>
int main(void)
{
    int t, x=0;
    scanf("%d", &t);
    while(t--)
    {
        char bit[3];
        for (int i=0; i<3; i++)
            scanf(" %c", &bit[i]);
        if (bit[0]=='+' || bit[2]=='+')
            x++;
        else
            x--;
    }
    printf("%d\n", x);
    return 0;
}
