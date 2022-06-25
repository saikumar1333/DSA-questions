#include<bits/stdc++.h>
using namespace std;
int findmin(int sum,vector<int> coins){
    int t=coins.size();
    if(sum==0){
        return 0;
    }
    int mini=INT_MAX;
    for(int i=0;i<t;i++){
        if(sum-coins[i]>=0){
           mini=min(mini,findmin(sum-coins[i],coins));
        }
    }
    return mini+1;
}
int bottomupdp(int sum,vector<int> coins){
    int t=coins.size();
    vector<int> dp(sum+1,0);
    for(int i=1;i<=sum;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<t;j++){
            if(i-coins[j]>=0 and dp[i-coins[j]]!=INT_MAX){
               dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        
    }
    return dp[sum];
}
int main(){
    int sum=15;
    vector<int> coins={12,2,7,9};
    cout<<findmin(sum,coins)<<endl;
    cout<<bottomupdp(sum,coins);
}