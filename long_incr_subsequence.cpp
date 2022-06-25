//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/25680190#overview
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={50,4,10,8,30,100};
         int n=arr.size();
    vector<int> dp(n,1);
    dp[0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    int val=-1;
    for(int j=0;j<n;j++){
            val=max(val,dp[j]);
            cout<<dp[j]<<",";
        }
        cout<<endl;
    cout<<val<<endl;
}