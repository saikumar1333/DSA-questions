//question link :   https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5218786#overview

#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;
class node{
    public:
    int x;
    int y;
    int dist;
    node(int x,int y,int dist){
       this->x=x;
       this->y=y;
       this->dist=dist;
    }
};
class compare{
    public:
    bool operator()(int node &a,int node &b){
        return a.dist<=b.dist;
    }
};
int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    int p=grid.size();
    int q=grid[0].size();
    int i=0,j=0;
    //assigning infinity to all values in dist array
    vector<vector<int>> distance(p+1,vector<int>(q+1,INT_MAX));
    distance[i][j]=grid[0][0];
    int X[]={0,0,1,-1};
    int Y[]={1,-1,0,0};
    set<node,compare> s;
    s.insert(node(0,0,distance[0][0]));
    
    while(!s.empty()){
        auto it=s.begin();
        int pi=it->x;
        int pj=it->y;
        int pdist=it->dist;
        s.erase(it);
        for(int r=0;r<4;r++){
            int ni=pi+X[r];
            int nj=pj+Y[r];
            if(ni>=0 and nj>=0 and ni<p and nj<q and pdist+grid[ni][nj]<distance[ni][nj]){
                //As we are traversing four nodes surrounded some may repeat in other node surroundants
                //so we check and remove that if exists
                node check(ni,nj,distance[ni][nj]);
                if(s.find(check)!=s.end()){
                    s.erase(s.find(check));
                }
                int ndist=pdist+grid[ni][nj];
                distance[ni][nj]=ndist;
                s.insert(node(ni,nj,ndist));
            }
        }
    }
    return distance[p-1][q-1];
    
}
int main(){
    vector<vector<int> > grid={{2,3,2,3,4,5},{1,2,5,2,5,7}};
    cout<<shortest_path(grid)<<endl;
    return 0;

}