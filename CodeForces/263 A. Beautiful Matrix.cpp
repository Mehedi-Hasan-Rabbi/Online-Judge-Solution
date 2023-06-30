#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int matrix[5][5], row, col;
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                row = i;
                col = j;
            }
        }
    }
    int move_row = abs(row-2);
    int move_col = abs(col-2);

    cout << move_col + move_row << '\n';
    return 0;
}
