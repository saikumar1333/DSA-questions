#include<bits/stdc++.h>
using namespace std;
int ans(string s, string t,int i,int j){
    int p=s.length();
    int q=t.length();
    if(i==p or j==q){
        return 0;
    }
    if(s[i]==t[j]){
        return 1+ans(s,t,i+1,j+1);
    }
    int a1=ans(s,t,i+1,j);
    int a2=ans(s,t,i,j+1);
    return max(a1,a2);
}
int dp_ans(string s, string t,int i,int j,vector<vector<int>> &dp){
    int p=s.length();
    int q=t.length();
    if(i==p or j==q){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j]){
        return dp[i][j]=1+dp_ans(s,t,i+1,j+1,dp);
    }
    int a1=dp_ans(s,t,i+1,j,dp);
    int a2=dp_ans(s,t,i,j+1,dp);
    return dp[i][j]=max(a1,a2);
}
int bottomup(string s,string t){
 int p=s.length();
    int q=t.length();
    vector<vector<int>> dp(p+1,vector<int> (q+1,0));
        for(int i=1;i<=p;i++){
            for(int j=1;j<=q;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    int a1=dp[i-1][j];
                    int a2=dp[i][j-1];
                    dp[i][j]=max(a1,a2);
                }
            }
        }
        return dp[p][q];
}
int main(){
    string s="asdfgt";
    string t="asftgh";
    cout<<ans(s,t,0,0)<<endl;
    int p=s.length();
    int q=t.length();
    vector<vector<int>> dp(p,vector<int> (q,-1));
    cout<<dp_ans(s,t,0,0,dp)<<endl;
    cout<<bottomup(s,t);
}