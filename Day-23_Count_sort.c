// implmenting count sort using array

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int maximum(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
void countSort(int arr[], int n)
{
    int i, j;
    int max = maximum(arr, n); // maximum element

    int *count = (int *)malloc((max + 1) * sizeof(int)); // count array
    // intialize array to 0
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    // increment the corresponding index in count array
    for (i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    i = 0; // counter for count araay
    j = 0; // counter for given array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j++] = i;
            count[i]--;
        }
        else{
            i++;
        }
    }
}

void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Given array is: ");
    display(arr, n);
    countSort(arr, n);
    printf("Sorted array is: ");
    display(arr, n);

    return 0;
}