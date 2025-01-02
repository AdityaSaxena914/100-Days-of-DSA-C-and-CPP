// Insertion in Array

#include <stdio.h>

void Display(int arr[],int n){
    //code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
int indInsertion(int arr[], int size, int element, int capacity, int index){
    // code for insertion
    if (size>=capacity)
    {
        return -1; // out of capacity
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]= element;
    return 1;
}
int main(){
    int arr[100]={7,8,12,27,88,56,34,23};
    int size = 8, element = 45, index = 5,Inserted;
    printf("Default Array\n");
    Display(arr,size);
    printf("\n");
    Inserted=indInsertion(arr, size, element, 100, index);
    size++;
    if (Inserted==1)
    {
        printf("Insertion successful\n");
        printf("Modified Array\n");
        Display(arr,size);
    }
    else{
        printf("Insertion failed\n");
    }
    return 0;
}