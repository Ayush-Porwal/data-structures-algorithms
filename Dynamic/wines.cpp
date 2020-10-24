#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

// top down approach
int maxWineProfit(vector<int> prices, int i, int j, int year, int dp[][MAX]){
    // base case
    if(i>j){
        return 0;
    }

    //memory lookup
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    
    //recursive case
    int leftSold = maxWineProfit(prices, i+1,  j, year+1, dp) + prices[i]*year;
    
    int rightSold = maxWineProfit(prices, i, j-1, year+1, dp) + prices[j]*year;
    
    return dp[i][j] = max(leftSold, rightSold);
}

int main(){
    vector<int> prices = {2, 3, 5};
    int dp[MAX][MAX] = {0};
    cout << maxWineProfit(prices, 0, 2, 1, dp) << endl;
    return 0;
}
