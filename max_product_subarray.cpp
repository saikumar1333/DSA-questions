//https://www.interviewbit.com/problems/max-product-subarray/
#include<bits/stdc++.h>
using namespace std;
    int main(){
        vector<int> arr={4,5,-2,6,-2,3,4,-3,6};
    int n=arr.size();
   if(n==0){
       return 0;
   }
   int max_now=arr[0];
   int min_now=arr[0];
   int result=max_now;
   for(int i=1;i<n;i++){
       int now=arr[i];
       int temp_maxnow=max({now,max_now*now,min_now*now});
       min_now=min({now,max_now*now,min_now*now});
       max_now=temp_maxnow;
          result=max(result,max_now);

   }
   cout<<result;
    }