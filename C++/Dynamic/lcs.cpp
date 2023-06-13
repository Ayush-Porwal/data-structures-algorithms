#include <bits/stdc++.h>

using namespace std;

int lcs_recursive(string a, string b, int m, int n){
    if(m==0 || n==0){
        return 0;
    }

    if(a[m-1]==b[n-1]){
        return 1 + lcs_recursive(a, b, m-1, n-1);
    }

    int first = lcs_recursive(a, b, m-1, n);
    int second = lcs_recursive(a, b, m, n-1);

    return max(first, second);
}

vector<vector<int>> lcs_dynamic(string &a, string &b){
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp;
}

int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";

    int i = a.size();
    int j = b.size();

    cout << "recursive answer is : " << lcs_recursive(a, b, i, j) << endl;

    vector<vector<int>> ans = lcs_dynamic(a, b);

    cout << "dynamic answer is: " << ans[i][j] << endl;

    vector<string> lcs(ans[i][j], "X");

    while(i>0 && j>0){

        if(a[i-1]==b[j-1]){
            lcs[--ans[i][j]] = a[i-1];
            i--;
            j--;
            continue;
        }
        else if(ans[i-1][j]>ans[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    cout << "The longest common subsequence is: ";

    for(auto item : lcs){
        cout << item;
    }
    cout << endl;

    return 0;
}