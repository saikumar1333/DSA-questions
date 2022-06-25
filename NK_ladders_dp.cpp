//timeo(k^n)
//no of ways to reach up of ladder if u can take atmost k jumps at a time
#include<bits/stdc++.h>
using namespace std;
int ladders_topdown(int n,int k){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ways=0;
    for(int jump=1;jump<=k;jump++){
        ways+=ladders_topdown(n-jump,k);
    }
    return ways;
}
int ladders_bottomdown(int n,int k){
    int dp[n+1]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int jump=1;jump<=k;jump++){
            if(i-jump>=0){
                dp[i]+=dp[i-jump];
            }
        }
    }
    return dp[n];
}
int ladders_bu(int n,int k){
    int dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++){
            dp[i]=2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}
int main(){
    int n=4,k=3;
    cout<<ladders_topdown(n,k)<<endl;
    cout<<ladders_bottomdown(n,k)<<endl;
    cout<<ladders_bu(n,k)<<endl;
    return 0;
}