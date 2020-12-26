#include <bits/stdc++.h>

using namespace std;

int convertRomanToInt(string s){
    int n = s.size();
    int ans = 0;

    map<char, int> mapping = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    for (int i = 0; i < n; i++){

        if(i+1<n && mapping[s[i]] < mapping[s[i+1]]){
            // case Xl = 40
            ans -= mapping[s[i]];
        }
        else{
            ans += mapping[s[i]];
        }
    }

    return ans;
}

vector<string> splitString(string s){
    
    stringstream streamstr(s); // tream s as some cin stream, just use streamstr instead of cin in getline

    vector<string> ans;
    string item;

    while(getline(streamstr, item,' ')){
        ans.push_back(item);
    }

    return ans;
}

bool comp(string a, string b){
    vector<string> fromA = splitString(a);
    vector<string> fromB = splitString(b);

    if(fromA[0]==fromB[0]){
        return convertRomanToInt(fromA[1]) < convertRomanToInt(fromB[1]);
    }
    else{
        return fromA[0] < fromB[0];
    }
}

int main(){
    vector<string> names = {"Richard V","Henry VI","Edward II","Richard XXV","Henry IX","Edward LII"};
    sort(names.begin(), names.end(), comp);

    for(auto item : names){
        cout << item << endl;
    }
    return 0;
}