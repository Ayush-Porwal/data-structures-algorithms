#include <bits/stdc++.h>

using namespace std;

int lps_recursive(string a, int i, int j){
    if(i==j){
        return 1;
    }
    
    if(a[i]==a[j] && j == i+1){
        return 2;
    }
    
    if(a[i]!=a[j]){
        return max(lps_recursive(a, i, j-1), lps_recursive(a, i+1, j));
    }
    
    return lps_recursive(a, i+1, j-1) + 2;
}

int lps_dynamic(string a){
    int n = a.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(i==j){
                dp[i][j] = 1;
            }
            if(a[i]==a[j] && j == i+1){
                dp[i][j] = 2;
            }
            if(a[i]==a[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            if(a[i]!=a[j]){
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}

int main(){
    string a = "GEEKSFORGEEKS";

    cout << "recursive is: " << lps_recursive(a, 0, 12) << endl;
    cout << "dynamic is: " << lps_dynamic(a) << endl;

    return 0;
}