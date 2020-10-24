#include<bits/stdc++.h>

using namespace std;

int merge(vector<int> arr, int left ,int right){
    int mid = left + (right-left)/2;
    int i = left;
    int j = mid+1;

    vector<int> temp;

    int count = 0;

    while(i<=mid && j<=right){
        if(arr[i]>arr[j]){
            count += mid-i+1;
            temp.push_back(arr[j++]);
        }
        else{
            temp.push_back(arr[i++]);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=right){
        temp.push_back(arr[j++]);
    }

    for(int i=left; i<=right; i++){
        arr[i] = temp[i];
    }

    return count;

}

int inversion_count(vector<int> arr, int left, int right){
    if(left>=right){
        return 0;
    }

    int mid = left + (right-left)/2;

    int x = inversion_count(arr, left, mid);
    int y = inversion_count(arr, mid+1, right);

    int z = merge(arr, left, right);

    return x+y+z;
}

int main(){
    vector<int> arr = {1,5,2,6,3,0};
    vector<int> arr2 = {6,5,4,3,7,8};

    //cout << inversion_count(arr, 0, arr.size()-1);

    cout << "merge: " << merge(arr2, 0, 5) << endl; 

    return 0;
}