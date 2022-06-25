#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int> > &grid,int row,int col){
    int p=grid.size();
    int q=grid[0].size();
    int size=1;
    grid[row][col]=0;
    vector<int> udlr({0,1,0,-1,0});
    for(int i=0;i<4;i++){
        int nrow=row+udlr[i];
        int ncol=col+udlr[i+1];
        if(nrow>=0 and nrow<p and ncol>=0 and ncol<q and grid[nrow][ncol]==1){
            size=size+dfs(grid,nrow,ncol);
        }
    }
    return size;
}
int largest_island(vector<vector<int> > grid){
    //return the size of largest island in grid
    int p=grid.size();
    int q=grid[0].size();
    int largest=0;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(grid[i][j]==1){
                largest=max(largest,dfs(grid,i,j));
            }
        }
    }
    return largest;
}
int main()
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,1,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,1,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    
    
    cout<<"Area of largest island = "<<largest_island(grid);
    
    return 0;
}