#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    //Can use next_permutation(nums.begin(),nums.end());
    
    //finding the pivot
    int pivot = -1, n = nums.size();

    for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        reverse(nums.begin(), nums.end()); // in place changes
        return;
    }

    //Finding next larger element
    for(int i = n-1; i > pivot; i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i],nums[pivot]);
            break;
        }
    }

    //Reverse the remaining elements
    int i = pivot + 1, j = n-1;
    while(i <= j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
vector<int>nums = {1,4,2,5,3};
nextPermutation(nums);
printArray(nums);
return 0;
}