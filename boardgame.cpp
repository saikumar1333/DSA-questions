#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define M 3
#define N 4

//trie
class node{
    public:
    char s;
    unordered_map<char,node*> children;
    string word;
    bool isterminal;
    node(char s){
        this->s=s;
        isterminal=false;
        word="";  //word is to store the ans at each terminal of trie
    }
};
class trie{
    public:
    node* root;
    trie(){
        root=new node('\0');
    }
    void addword(string word){
        node*temp=root;
        for(auto ch:word){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new node(ch);
            }
            temp=temp->children[ch];
        }
        temp->isterminal=true;
        temp->word=word;
    }
};
//8way dfs and trie guided search
void dfs(char boar[M][N],node* nod,int i,int j,bool visited[M][N],unordered_set<string> &dfswords){
     char ch=boar[i][j];
     if(nod->children.count(ch)==0){
         return;
     }
     visited[i][j]=true;
     nod=nod->children[ch];

     if(nod->isterminal){
         dfswords.insert(nod->word);
     }
     int x[]={0,1,1,1,0,-1,-1,-1};
     int y[]={-1,-1,0,1,1,1,0,-1};
     for(int k=0;k<8;k++){
         int ni=i+x[k];
         int nj=j+y[k];
         if(ni>=0 and nj>=0 and ni<M and nj<N and !visited[ni][nj]){
             dfs(boar,nod,ni,nj,visited,dfswords);
         }
     }
     visited[i][j]=false;
     return;
}

int main(){
string words[]={"snake","for","quez","snac","kast","cat"};
char board[M][N]={{'s','e','r','t'},{'u','n','k','s'},{'t','c','a','t'}};
//send words to trie
trie t;
for(auto w:words){
    t.addword(w);
}
//unordered set store words that are found in dfs
//we choose unordered set because many words may repeat
unordered_set<string> dfswords;

bool visited[M][N]={0};
for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
        dfs(board,t.root,i,j,visited,dfswords);
    }
}

for(auto word:dfswords){
    cout<<word<<endl;
}
}