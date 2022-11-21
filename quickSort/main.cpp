#include<iostream>

using namespace std;

namespace cs
{
    void cSswap(int* n1, int* n2)
    {
        int t = *n1;
        *n1 = *n2;
        *n2 = t;
    }
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[right]; // rightmost element
    int i = left - 1; // pointer for greater element

    // traverse each element of the arr
    // compare then with the pivot
    for(int j = left; j < right; j++)
    {
        if(arr[j] <= pivot)
        {
            // if element is smaller than pivot is found
            // swap it with the greater element  pointed
            i++;

            // swap element at i with element at j
            cs::cSswap(&arr[i], &arr[j]);
        }
    }

    // swap pivot with greater element at i
    cs::cSswap(&arr[i+1], &arr[right]);

    return(i+1); // return partition point
}

/*

@ Time complexity:
  @ Best - O(n*log n)
  @ Worst - O(n^2)
  @ Average - O(n*log n)

@ Space complexity - O(log n)
@ Stability - No

*/

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(arr, low, high);

        // recursive call on the left of pivot
        quickSort(arr, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int vr[], int size)
{
    for(int i =0; i < size; i++)
    {
        cout << vr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int data[] = { 3, 7, 8, 5, 2, 1, 9, 5, 4 };
    int n = sizeof(data) / sizeof(data[0]);

    int l = 0;
    int h = n - 1;
    quickSort(data, l, h);
    printArray(data, n);

    return(0);
}


// ref: https://en.wikipedia.org/wiki/Quicksort