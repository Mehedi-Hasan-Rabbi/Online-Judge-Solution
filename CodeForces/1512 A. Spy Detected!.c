#include<stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int size, i, j, count;
        scanf("%d", &size);
        int arr1[size], arr2[size];
        for (i=0; i<size; i++)
        {
            scanf("%d", &arr1[i]);
            arr2[i] = arr1[i];
        }
        for (i=0; i<size; i++)
        {
            count = 0;
            for (j=0; j<size; j++)
            {
                if (arr1[i] == arr2[j])
                {
                    count++;
                }
            }
            if (count < 2)
            {
                printf("%d\n", i+1);
                break;
            }

        }
    }
    return 0;
}
