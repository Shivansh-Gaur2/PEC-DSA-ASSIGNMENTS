#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionOutPlace(int arr[], int n)
{
    int helperArr[n];
    for (int i = 0; i < n; i++)
    {
        helperArr[i] = arr[i];
    }
    int i, key, j;
    for (int i = 1; i < n; i++)
    {
        key = helperArr[i];
        j = i - 1;

        while (j >= 0 && helperArr[j] > key)
        {
            helperArr[j + 1] = helperArr[j];
            j = j - 1;
        }
        helperArr[j + 1] = key;
    }
    cout << "Insertion Sort using Out-place Algortihm :- ";
    for (int i = 0; i < n; i++)
    {
        cout << helperArr[i] << " ";
    }
    cout << endl;
    cout << "Orignal Array:- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of array:- " << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter data of element at " << i << " index" << endl;
        cin >> arr[i];
    }
    cout << endl;
    insertionOutPlace(arr, n);
    cout << "Insetion Sort using In-Place algorithm :- ";

    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
