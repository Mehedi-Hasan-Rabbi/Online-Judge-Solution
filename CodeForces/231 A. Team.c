#include<stdio.h>
int main(void)
{
    int testCase,i,j,count=0,solve=0;
    scanf("%d",&testCase);
    for (i=0;i<testCase;i++)
    {
        int team[3];
        for (j=0;j<3;j++)
        {
            scanf("%d",&team[j]);
            if (team[j]==1)
                count++;
        }
        if (count>=2)
            solve++;
        count=0;
    }
    printf("%d\n",solve);
    return 0;
}
