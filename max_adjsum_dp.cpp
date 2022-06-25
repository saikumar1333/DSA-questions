#include<bits/stdc++.h>
using namespace std;
// int max_adjsum(vector<int> arr,int n,vector<int> dp){
//     dp[n-1]=arr[n-1];
//     dp[n-2]=arr[n-2];
//     for(int i=n-3;i>=0;i--){
//         int ans=INT_MIN;
//         for(int j=i+2;j<n;j++){
//             ans=max(ans,dp[j]);
//         }
//         dp[i]=arr[i]+ans;
//     }
//     return dp[0];
// }
int main(){
    vector<int> arr={6,10,12,7,9,14};
         int n=arr.size();
    vector<int> dp(n,0);
        dp[n-1]=arr[n-1];
    dp[n-2]=arr[n-2];
    for(int i=n-3;i>=0;i--){
        int ans=-1;
        for(int j=i+2;j<n;j++){
            ans=max(ans,dp[j]);
        }
        dp[i]=arr[i]+ans;
    }
    int val=-1;
    for(int j=0;j<n;j++){
            val=max(val,dp[j]);
        }
    cout<<val;
}