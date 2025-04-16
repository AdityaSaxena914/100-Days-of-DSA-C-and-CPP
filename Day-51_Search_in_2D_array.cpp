#include<bits/stdc++.h>
using namespace std;

bool searchInRow(vector<vector<int>>& mat, int target, int row){
    int st = 0, end = mat[0].size() - 1;

    while(st<=end){
        int mid = st + (end - st)/2;
        if(target == mat[row][mid]){
            return true;
        }else if(target > mat[row][mid]){
            st = mid +1;
        }else{
            end = mid -1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    // BS on total rows

    int startRow = 0, endRow = mat.size() - 1;

    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2;

        if (target >= mat[midRow][0] && target <= mat[midRow][mat[0].size()-1]){
            return searchInRow(mat, target, midRow);
        }else if(target >= mat[midRow][mat[0].size()-1]){
            startRow = midRow+1;
        }else{
            endRow = midRow -1;
        }
    }
    return false;
}

int main(){
vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

int target = 3;

cout<< searchMatrix(mat, target)<<endl;// 1 for true, 0 for false

return 0;
}