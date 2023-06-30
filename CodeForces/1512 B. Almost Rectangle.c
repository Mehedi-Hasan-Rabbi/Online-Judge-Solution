#include<stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int size, i, j;
        int row[4], col[4], c = 0;
        scanf("%d", &size);
        char rectangle[size][size];
        for (i=0; i<size; i++)
        {

            for (j=0; j<size; j++)
            {
                scanf(" %c", &rectangle[i][j]);
                if (rectangle[i][j] == '*')
                {
                    row[c] = i;
                    col[c] = j;
                    c++;
                }

            }
        }
        if(size==2)
        {
            printf("**\n**\n");
        }
        if (size>2 && row[0] == row[1] && row[0]+1<size) // In the same row
        {
            rectangle[row[0]+1][col[0]]='*';
            rectangle[row[1]+1][col[1]]='*';
        }
        if (size>2 && row[0] == row[1] && row[0]+1==size) // In the same row
        {
            rectangle[row[0]-1][col[0]]='*';
            rectangle[row[1]-1][col[1]]='*';
        }
        if (size>2 && col[0] == col[1] && col[0]+1<size) // In the same col
        {
            rectangle[row[0]][col[0]+1]='*';
            rectangle[row[1]][col[1]+1]='*';
        }
        if (size>2 && col[0] == col[1] && col[0]+1==size) // In the same col
        {
            rectangle[row[0]][col[0]-1]='*';
            rectangle[row[1]][col[1]-1]='*';
        }
        if (size>2 && row[0]!=row[1] && col[0]!=col[1])
        {
            rectangle[row[0]][col[1]]='*';
            rectangle[row[1]][col[0]]='*';
        }
        if (size>2)
        {
            for (i=0; i<size; i++)
        {

            for (j=0; j<size; j++)
            {
                printf("%c", rectangle[i][j]);
            }
            printf("\n");
        }
        }
    }
    return 0;
}
