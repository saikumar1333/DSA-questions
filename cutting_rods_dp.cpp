#include<bits/stdc++.h>
using namespace std;
int bestrod(int n,vector<int> prices){
int size=n;
if(n<=0){
    return 0;
}
int ans=INT_MIN;
for(int i=0;i<size;i++){
    ans=max(ans,(prices[i]+bestrod(n-(i+1),prices)));
}
return ans;
}
int bestrod_dp(int n,vector<int> prices){
    int dp[n+1];
    dp[0]=0;
    for(int len=1;len<=n;len++){
        int ans=INT_MIN;
        for(int i=0;i<len;i++){
            ans=max(ans,prices[i]+dp[len-(i+1)]);
        }
        dp[len]=ans;
    }
    return dp[n];
}
int main(){
    int n=8;
    vector<int> prices={1,3,5,6,9,10,11,13}; //5 with size 3 and 9 with size 5 brings max=14
    cout<<bestrod(n,prices)<<endl;
    cout<<bestrod_dp(n,prices)<<endl;   
    return 0;
}