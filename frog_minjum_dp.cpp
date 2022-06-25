//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/25680194#overview
//can jump to next 2 positions and jump differences will add. so final minimum path to reach end
//30 10 60 10 60 50 (1-3-5-6) =60-30 + 60-60  + 60-50=40
#include<bits/stdc++.h>
using namespace std;
int minpath(vector<int> arr,int n,vector<int> dp){
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        int a=dp[i-1]+abs(arr[i]-arr[i-1]);
        int b=dp[i-2]+abs(arr[i]-arr[i-2]);
        dp[i]=min(a,b);
    }
    return dp[n-1];
}
int main(){
    vector<int> arr={30,10,60,10,60,50};
    int n=arr.size();
    vector<int> dp(n,0);
    cout<<minpath(arr,n,dp);
}