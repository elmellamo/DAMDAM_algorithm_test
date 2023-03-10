#include <iostream>
#include <vector> 
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, M, V;
int a, b, x;
vector<int> v[1007];
int visited[1007];
queue<int> q;

void bfs(int start){
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()){
        x = q.front();
        q.pop();
        cout << x <<" ";
        
        for(int i:v[x]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }

}


void dfs(int start){
    visited[start] = 1;
    cout<<start<<" ";

    for(int i:v[start]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>V;

    for(int i=0; i<M; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1;i<=N;i++){
        sort(v[i].begin(), v[i].end());
    }

    dfs(V);
    memset(visited, 0, sizeof(visited));
    cout<<"\n";
    bfs(V);



}