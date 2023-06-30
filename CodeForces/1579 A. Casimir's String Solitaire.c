#include<stdio.h>
#include<string.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a_c=0, b=0, i;
        char str[50];
        scanf(" %s", &str);
        int len = strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]=='B')
                b++;
            else if(str[i]=='A' || str[i]=='C')
                a_c++;
        }
        if(a_c==b)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

