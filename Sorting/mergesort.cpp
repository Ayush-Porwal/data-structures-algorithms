#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int end)
{
    int k = 0;
    int i = start;
    int mid = (start + end) / 2;
    int j = mid + 1;

    vector<int> ans(end - start + 1, 0);

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            ans[k++] = arr[i++];
        }
        else
        {
            ans[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        ans[k++] = arr[i++];
    }
    while (j <= end)
    {
        ans[k++] = arr[j++];
    }

    k = 0;
    for (int a = start; a <= end; a++)
    {
        arr[a] = ans[k++];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
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

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}