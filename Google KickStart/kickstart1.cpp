#include<bits/stdc++.h>

using namespace std;

vector<int> countSort(vector<int> arr){

    int size = *max_element(arr.begin(), arr.end());
    vector<int> pos(size, 0);
    vector<int> newArr(arr.size());
    
    for(int i=0; i<arr.size(); i++){
        pos[arr[i]-1]++;
    }

    for(int i=1; i<pos.size(); i++){
        pos[i+1] += pos[i];
    }

    for(auto item : pos){
        cout << item << " ";
    }
    cout << endl;

    for(int i=0; i<arr.size(); i++){
        newArr[pos[arr[i]]] = arr[i];
    }

    return newArr;
}

int main(){
    int t;
    cin >> t;
    int k = 0;

    while(t--){
        int n, b;
        cin >> n >> b;
        
        vector<int> houses;
        
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            houses.push_back(x);
        }
        
        houses = countSort(houses);
        int house = 0;
        
        while(b>0 && houses[house] <= b){
            b -= houses[house++];
        }
        
        cout << "Case #" << ++k <<": " << house << endl;

        for(auto item : houses){
            cout << item << " ";
        }
        cout << endl;

    }
    
    return 0;
}