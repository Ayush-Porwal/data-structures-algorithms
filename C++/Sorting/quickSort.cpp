#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int i = start - 1;
    int j = start;

    for (; j <= end - 1; j++)
    {
        if (arr[j] <= arr[end])
        { //end is my pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);

    return i + 1;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = partition(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (auto item : arr)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}