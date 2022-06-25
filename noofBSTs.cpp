//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/25682812#overview
#include<bits/stdc++.h>
using namespace std;
int countbst(int n,int dp[]){
    if(n==0 or n==1){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=(countbst(i-1,dp)*countbst(n-i,dp));
    }
    return dp[n]=ans;
}
int bottomup(int n,int dp[]){
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]+=(dp[j-1]*dp[i-j]);
        }
    }
    return dp[n];
}
int main(){
    int n=5;
    int dp[n+1]={0};
    cout<<countbst(n,dp)<<endl;
    cout<<bottomup(n,dp);
}