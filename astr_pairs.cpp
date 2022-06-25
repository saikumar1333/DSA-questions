#include<bits/stdc++.h>
using namespace std;
void dfs(int v,vector<vector<int>> &adjlist,vector<bool> &visited,int &num){
    visited[v]=true;
    num+=1;
    for(int i=0;i<adjlist[v].size();i++){
        if(!visited[adjlist[v][i]]){
            dfs(adjlist[v][i],adjlist,visited,num);
        }
    }
}
int count_pairs(int N, vector<pair<int,int> > astronauts){
    //complete this method
    vector<vector<int>> adjlist(N);
    for(auto it:astronauts){
        adjlist[it[0]].push_back(it[1]);
        adjlist[it[1]].push_back(it[0]);
    }
    int ans=N*(N-1)/2;
    vector<bool> visited(N);
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            num = 0;
            dfs(i, adjlist, visited, num);
            ans -= (num* (num - 1) / 2);
        }
    }
    return ans;
}

//https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5219008#overview
//Input: N = 6, mat[][] = {{0, 1}, {0, 2}, {2, 5}}
//Output: 9
//Explanation:
//Astronauts with ID {0, 1, 2, 5} belong to first country, astronaut with ID {3} belongs to second country and astronaut with ID {4} belongs to third country. The number of ways to choose two astronauts from different countries is:
//Choose 1 astronaut from country 1 and 1 astronaut from country 2, then the total number of ways is 4*1 = 4.
//Choose 1 astronaut from country 1 and 1 astronaut from country 3, then the total number of ways is 4*1 = 4.
//Choose 1 astronaut from country 2 and 1 astronaut from country 3, then the total number of ways is 1*1 = 1.
//Therefore, the total number of ways is 4 + 4 + 1 = 9. 
//Input: N = 5, mat[][] = {{0, 1}, {2, 3}, {0, 4}}
//Output: 6