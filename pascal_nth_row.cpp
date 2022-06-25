#include<bits/stdc++.h>
using namespace std;
void getrow(int A){
    vector<int> ans;
    int ncr=1;
    ans.push_back(ncr);
    for(int i=1;i<=A;i++){
        int pres=(ncr*(A-i+1))/i;
        ans.push_back(pres);
        ncr=pres;
    }
    for(auto K:ans){
        cout<<K<<" ";
    }
}
int main(){
    int n=5;
    getrow(n);
    return 0;
}