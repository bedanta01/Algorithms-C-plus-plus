/*
Topological Sort:

                0   2
                 \ / \
                  1   3
                   \ /
                    4
                    |
                    5

i/p:
6 6
0 1
1 4
2 1
2 3
3 4
4 5
*/

#include <iostream>
#include<vector>
using namespace std;

vector<int> adj[100];
bool visit[100];

vector<int> ans;

void dfs(int node){
    if(!visit[node]){
        visit[node] = true;
        for(int i=0;i<adj[node].size();i++){
            dfs(adj[node][i]);
        }
        ans.push_back(node);
    }
    
}

void print(int num_of_nodes){
    for(int i=0;i<num_of_nodes;i++){
        cout<<ans[i];
    }
    
}
void topologicalSort(int num_of_nodes,int num_of_edges){
    for(int i=0;i<num_of_nodes;i++){
        dfs(i);
    }
    //reverse (ans.begin(),ans.end());
    print(num_of_nodes);
}

int main() {
	
	int num_of_nodes,num_of_edges;
	cin>>num_of_nodes>>num_of_edges;
	for(int i=0;i<num_of_edges;i++){
	    int a,b;
	    cin>>a>>b;
	    adj[a].push_back(b);
	}
	for(int i=0;i<100;i++){
	    visit[i] = false;
	}
	
	topologicalSort(num_of_nodes,num_of_edges);
	
	
	
	return 0;
}