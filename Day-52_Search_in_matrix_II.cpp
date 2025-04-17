#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();

    int Row = 0, column = n - 1;

    while (Row < m && column >= 0)
    {
        if (target == mat[Row][column])
        {
            return true;
        }
        mat[Row][column] > target ? column-- : Row++;
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    int target = 19;

    cout << searchMatrix(mat, target) << endl; // 1 for true, 0 for false
    return 0;
}