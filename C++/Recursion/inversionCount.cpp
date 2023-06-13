#include<bits/stdc++.h>

using namespace std;

// recursive approach
int merge(vector<int> arr, int left, int right){
    int mid = left + (right-left)/2;

    int i = left;
    int j = mid+1;

    vector<int> temp;

    int count = 0;

    while(i<=mid && j<=right){
        if(arr[i]>arr[j]){
            count += mid-i+1;
            j++;
            temp.push_back(arr[j]);
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }

    // if some elements are left

    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=right){
        temp.push_back(arr[j++]);
    }

    for(int i=left; i<temp.size(); i++){
        arr[i] == temp[i];
    }

    return count;
}

int inversion_count(vector<int> arr, int left, int right){
    //base condition
    if(left==right){
        return 0;
    }

    // recursive logic
    int mid = left + (right-left)/2;

    int x = inversion_count(arr, left, mid);
    int y = inversion_count(arr, mid+1, right);

    int z = merge(arr, left, right);

    return x+y+z;
}

int main(){
    vector<int> arr = {1, 5, 2, 6, 3, 0};

    //brute force mathod O(n*n) time complexity
    set<pair<int, int>> ans;
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]>arr[j] && i<j){
                ans.insert({arr[i], arr[j]});
            }
        }
    }
    for(auto it = ans.begin(); it!=ans.end(); it++){
        cout << it->first << ", " << it->second << endl;
    }

    cout << "without using recursion: "<< ans.size() << endl;

    cout << "using recursion: " << inversion_count(arr, 0, arr.size()-1) << endl;

    return 0;
}