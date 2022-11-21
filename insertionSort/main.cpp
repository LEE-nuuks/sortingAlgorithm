#include<iostream>

using namespace std;

/*
@ Time complexity: O(N^2)
@ Auxiliary Space: O(1)

@ Worst-case: O(N^2) comparisons and swaps
@ Best-case: O(N^2) comparisons and O(1) swaps
@ Average: O(N) comparisons and swaps
*/

void insertionSort(int ar[], int n)
{
    int key, j;

    for(int i =1; i<n; i++)
    {
        key = ar[i];
        j = i - 1;

        while(j >= 0 && ar[j] > key)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
    }

    for(int p = 0; p < n; p++)
    {
        cout << ar[p] << " ";
    }
    cout << endl;
}

int main()
{
    int sArr[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int s = sizeof(sArr) / sizeof(sArr[0]);

    insertionSort(sArr, s);

    return 0;
}

// ref: https://en.wikipedia.org/wiki/Insertion_sort