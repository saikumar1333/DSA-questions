//bfs question
//https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002   
#include<queue>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> l[vertex];
    for(auto p:edges){
        l[p.second].push_back(p.first);
        l[p.first].push_back(p.second);
    }
    for(int i=0;i<vertex;i++){
        sort(l[i].begin(),l[i].end());
    }
    queue<int> q;
    vector<int> ans;
    bool visited[vertex]={0};
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int k=q.front();
        ans.push_back(k);
        q.pop();
        for(auto nbr:l[k]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=true;
            }
        }
    }
    for(int i=0;i<vertex;i++){
        if(find(ans.begin(), ans.end(), i) != ans.end()){
            int z=0;
        }
        else{
             ans.push_back(i);
        }
    }
    return ans;
}