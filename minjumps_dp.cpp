//min no of jumps to reach arr[n] if arr[i] is maximum jump value of i
#include<bits/stdc++.h>
using namespace std;
int minjumps(vector<int> arr,int i,int n,vector<int> dp){
    if(i==n-1){
        return 0;
    }
    if(i>=n){
        return INT_MAX;
    }
    if(dp[i]!=0){
        return dp[i];
    }
    int steps=INT_MAX;
    for(int jump=1;jump<=arr[i];jump++){
        int k=minjumps(arr,i+jump,n,dp);
        if(k!=INT_MAX){
        steps=min(steps,k+1);
        }
    }
    return dp[i]=steps;
}
int main(){
    vector<int> arr={1,2,2,4,5,2,2,2,2,10};
    int n=arr.size();
    vector<int> dp(n,0);
    cout<<minjumps(arr,0,n,dp);
}