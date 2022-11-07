#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int comparision = 0, swaps = 0;
    for (int j = 0; j < n - 1; j++)
    {
        int iMin = j;
        for (int i = j + 1; i < n; i++)
        {
            cout << "comparing : " << arr[iMin] << " and " << arr[i] << endl;
            comparision += 1;
            if (arr[i] < arr[iMin])
            {
                iMin = i;
            }
        }
        if (iMin != j)
        {
            swaps += 1;
            cout << "swaping:- " << arr[j] << " and " << arr[iMin] << endl;
            swap(arr[j], arr[iMin]);
        }
    }
    cout << " total comparisions = " << comparision << " total swaps:- " << swaps << endl;
}

void bubbleSort(int arr[], int n)
{
    int comparision = 0, swaps = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cout << "comparing " << arr[j] << " and " << arr[j + 1] << endl;
            comparision += 1;
            if (arr[j] > arr[j + 1])
            {
                cout << "Swaping :- " << arr[j] << " and " << arr[j + 1] << endl;
                swap(arr[j], arr[j + 1]);
                swaps += 1;
            }
        }
    }
    cout << "comparisions = " << comparision << " swaps:- " << swaps << endl;
}

int main()
{
    int n = 5;
    int arr[5] = {2, 0, 1, 4, 3};
    cout << "SELECTION SORT" << endl;
    selectionSort(arr, n);
    cout << "The Sorted Array by using Selection Sort is : ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
    cout << "BUBBLE SORT" << endl;
    int arr2[5] = {8, 5, 2, 7, 6};
    bubbleSort(arr2, n);
    cout << "The Sorted Array by using Bubble Sort is : ";
    for (int i = 0; i < n; ++i)
        cout << arr2[i] << " ";
}
