#include <bits/stdc++.h>
using namespace std;

// Function to partition the array
int partitionLeft(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]); 
    return i;
}

// Function to perform random partition
int partitionRight(int arr[], int low, int high)
{
    // srand(time(NULL));
    int r = low + rand() % (high - low);
    swap(arr[r], arr [high]);
    return partitionLeft(arr, low, high);
}

// Recursive function for quicksort
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partitionRight(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}
// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout<<"Enter number of elements in an array: "<<endl;
    cin>>n;

    int arr[n];
    cout<<"\nEnter the elements of the array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout << "\nOriginal array: ";
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    cout << "\nSorted array: ";
    printArray(arr, n);
    return 0;
}  