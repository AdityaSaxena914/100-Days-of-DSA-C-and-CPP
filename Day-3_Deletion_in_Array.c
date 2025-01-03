// Deletion in Array

#include <stdio.h>

void Display(int arr[],int n){
    //code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
int indDeletion(int arr[], int size, int capacity, int index){
    // code for Deletion
    if (index >=capacity)
    {
        return -1; // Index out of bounds
    }
    for (int i = index; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    return 1;
}
int main(){
    int arr[100]={7,8,12,27,88,56,34,23};
    int size = 8, index = 2,Deleted;
    printf("Default Array\n");
    Display(arr,size);
    Deleted=indDeletion(arr, size, 100, index);
    size--;
    if (Deleted==1)
    {
        printf("Deletion successful\n");
        printf("Modified Array\n");
        Display(arr,size);
    }
    else{
        printf("Deletion failed\n");
    }
    return 0;
}