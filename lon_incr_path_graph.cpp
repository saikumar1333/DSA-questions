//longest incresing path of graph
//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5237694#overview
#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int> > &grid,int row,int col){
    int p=grid.size();
    int q=grid[0].size();
    int size1=1,size2=1,size3=1,size4=1;
    int p1=row-1,q1=col,p2=row,q2=col-1,p3=row,q3=col+1,p4=row+1,q4=col;
        if(p1>=0 and p1<p and q1>=0 and q1<q){
           if(grid[p1][q1]>grid[row][col]){
            size1=size1+dfs(grid,p1,q1);
           }
        }
        if(p2>=0 and p2<p and q2>=0 and q2<q){
           if(grid[p2][q2]>grid[row][col]){
            size2=size2+dfs(grid,p2,q2);
           }
        }
        if(p3>=0 and p3<p and q3>=0 and q3<q){
           if(grid[p3][q3]>grid[row][col]){
            size3=size3+dfs(grid,p3,q3);
           }
        }
        if(p4>=0 and p4<p and q4>=0 and q4<q){
           if(grid[p4][q4]>grid[row][col]){
            size4=size4+dfs(grid,p4,q4);
           }
        }
        int size = max(size1, max(size2, max(size3, size4))); 
    return size;
}

int longestPathSequence(vector<vector<int> > grid){
    
    int p=grid.size();
    int q=grid[0].size();
    int largest=0;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
                largest=max(largest,dfs(grid,i,j));
        }
    }
    return largest;
}
int main()
{
    vector<vector<int>> grid = {{1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {6,19,17,80},
                                {13,20,21,23},
                                };
    //ans = 1-2-3-7-11-17-19-20-21-23-80 so length=11
    cout<<"length of longest incresing path in graph : "<<longestPathSequence(grid);
    return 0;
}