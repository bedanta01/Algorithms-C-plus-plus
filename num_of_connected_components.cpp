#include <iostream>
using namespace std;

//check the bleow code..This is wrong

bool visit[5];

int islands;

int mat[5][5] = {{1, 1, 0, 0, 0},
             {0, 1, 0, 0, 1},
             {1, 0, 0, 1, 1},
             {0, 0, 0, 0, 0},
             {1, 0, 1, 0, 1}};

void island(int node){
    if(!visit[node]){
        visit[node]=true;
        for(int i=0;i<5;i++){
            if(mat[node][i]==1){
                island(i);
            }
        }
        islands++;
    }
}


int main() {
    islands = 0;
    for(int i=0;i<5;i++){
        visit[i] = false;
    }
    for(int i=0;i<5;i++){
        island(0);
    }
        
    cout<<islands;
    
	return 0;
}
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> adj[100005];
bool visit[100005];
int groups;

void dfs(int node){
    if(!visit[node]){
        visit[node] = true;
        for(int i=0;i<adj[node].size();i++){
            dfs(adj[node][i]);
        }
    }
}

void num_of_groups(int n){
    for(int i=0;i<n;i++){
        if(!visit[i]){
            dfs(i);
            groups++;
        }
    }
}

int main() {
    for(int i=0;i<100005;i++){
        visit[i] = false;
    }
    int n,p;
    cin>>n>>p;
    for(int i=0;i<p;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
    num_of_groups(n);
    cout<<groups;
    return 0;
}

*/