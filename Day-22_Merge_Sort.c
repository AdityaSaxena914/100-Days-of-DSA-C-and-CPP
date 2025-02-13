// Implementing Merge sort using array
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

void Merge(int arr[], int low, int mid, int high)
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}
void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;    // find mid index
        MergeSort(a,low,mid);    // dort left subarray
        MergeSort(a, mid + 1, high); // sort right subarray
        Merge(a, low, mid, high); // merge the sorted subarrays back together
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
    MergeSort(arr, 0, n - 1);
    printf("Sorted array is \n");
    Display(arr, n);
    return 0;
}
