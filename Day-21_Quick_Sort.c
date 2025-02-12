// Implementing Qucik sort using array
#include <stdio.h>
void Display(int arr[], int n)
{
    // code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j; // Index of pivot element in sorted array
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(a, low, high); // Index of pivot in array
        quickSort(a, low, partitionIndex - 1);        // sort left subarray
        quickSort(a, partitionIndex + 1, high);       // sort right subarray
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Given array is \n");
    Display(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array is \n");
    Display(arr, n);
    return 0;
}