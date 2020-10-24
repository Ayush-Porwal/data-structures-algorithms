    #include<bits/stdc++.h>
        
    using namespace std;
        
    #define H_MAX 100010

    int n;
    vector<int> height;

    int dp[H_MAX];
        
        
    //top down approach
    int minimumCost(int stone){
        //base case
        if(stone==n-1){
            return dp[stone] = 0;
        }
     
        // memory lookup
        if(dp[stone]!=INT_MAX){
            return dp[stone];
        }
        
        // recursion logic
        int oneStep = minimumCost(stone+1) + abs(height[stone]-height[stone+1]);
        
        int twoStep = INT_MAX;
        
        if(stone+2<n) twoStep = minimumCost(stone+2) + abs(height[stone]-height[stone+2]);
        
        return dp[stone] = min(oneStep, twoStep);
    }
        
    int main(){
        cin >> n;
        
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            height.push_back(x);
        }

        for(int i=0; i<H_MAX; i++){
            dp[i] = INT_MAX;
        }
        
        cout << minimumCost(0) << endl;
        
        return 0;
    }