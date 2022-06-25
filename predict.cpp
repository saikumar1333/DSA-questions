//predict the winner leetcode
#include <iostream>
#include <bits/stdc++.h>
#include<vector>
int main(){
int nums[]={1,5,2};
//1,5,2 false 1,5,233,7 true
int e=sizeof(nums);
        int turn=1;
        int s=0,sum=0;
        while(s<=e){
            
            if(turn==1){
                if(nums[s]>=nums[e]){
                    sum+=nums[s];
                    s++;
                }
                else{
                    sum+=nums[e];
                    e--;
                }
                turn=-1;
            }
            else{
                if(nums[s]>=nums[e]){
                    sum-=nums[s];
                    s++;
                }
                else{
                    sum-=nums[e];
                    e--;
                }
                turn=1;
            }
            if(s==e){
                sum+=nums[s]*turn;
            }
        }
        if(sum>=0){
            std::cout<<true;
        }
        else{
            std::cout<<false;
        }
        return 0;
        }