#include<bits/stdc++.h>
using namespace std;

/*
###############################################
input format from the given example:
10 9
0 1 2 3 4 5 6 7 8 9 10
1 3
1 6
1 2
3 4
6 8
2 7
2 5
8 9
8 10

output:
edge: 1-3 can be deleted
edge: 1-6 can be deleted
################################################
Now suppose we have node 3 weight as 0
10 9
0 1 2 0 4 5 6 7 8 9 10
1 3
1 6
1 2
3 4
6 8
2 7
2 5
8 9
8 10

output:
edge: 1-6 can be deleted

*/

vector<int>adj_ls[11];
bool is_visited[11];
int node_weight[11];

int max_edges(int node)
{
    is_visited[node]=true;
    int num_vertex=0;
    for(int i=0;i<adj_ls[node].size();i++)
    {
        if(!is_visited[adj_ls[node][i]])
        {
            int num_nodes=max_edges(adj_ls[node][i]);
            if(num_nodes%2==0){
                cout<<"edge: "<<node<<"-"<<adj_ls[node][i]<<" can be deleted"<<endl;
            }
            else{
                num_vertex+=num_nodes;
            }
        }
    }
    if(node_weight[node]!=0){
        return num_vertex+1;
    }
    else{
        return num_vertex;
    }
}

int main() {
    int start=1;
    int src,dest;
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<(nodes+1);i++){
        cin>>node_weight[i];
    }
    for(int j=0;j<edges;j++)
    {
        cin>>src>>dest;
        adj_ls[src].push_back(dest);
        adj_ls[dest].push_back(src);
    }
    max_edges(start);
    return 0;
}
