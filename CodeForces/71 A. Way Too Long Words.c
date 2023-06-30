#include<stdio.h>
#include<string.h>
int main()
{
    int testCase;
    scanf("%d",&testCase);
    for (int i=0;i<testCase;i++)
    {
        char ch[100];
        scanf("%s",ch);
        int length = strlen(ch);
        if (length>10)
        {
            printf("%c%d%c\n",ch[0],length-2,ch[length-1]);
        }
        else
            printf("%s\n",ch);
    }
    return 0;
}
