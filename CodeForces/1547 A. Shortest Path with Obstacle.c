#include<stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    int rowA, rowB, rowF, colA, colB, colF, distance;
    while(t--)
    {
        printf("\n");
        scanf("%d %d", &colA, &rowA);
        scanf("%d %d", &colB, &rowB);
        scanf("%d %d", &colF, &rowF);

        if (rowA==rowB && rowA!=rowF)
        {
            distance = abs(colA-colB);
            printf("%d\n", distance);
        }

        else if (colA==colB && colA!=colF)
        {
            distance = abs(rowA-rowB);
            printf("%d\n", distance);
        }

        else if (rowA==rowB && rowA==rowF)
        {
            if ((colF>colA && colF<colB) || (colF<colA && colF>colB))
            {
                distance = abs(colA-colB)+2;
                printf("%d\n", distance);
            }
            else
            {
                distance = abs(colA-colB);
                printf("%d\n", distance);
            }
        }

        else if (colA==colB && colA==colF)
        {
            if ((rowF>rowA && rowF<rowB) || (rowF<rowA && rowF>rowB))
            {
                distance = abs(rowA-rowB)+2;
                printf("%d\n", distance);
            }
            else
            {
                distance = abs(rowA-rowB);
                printf("%d\n", distance);
            }
        }

        else
        {
            int i = abs(colA-colB);
            int j = abs(rowA-rowB);
            distance = i+j;
            printf("%d\n", distance);
        }
    }
    return 0;
}