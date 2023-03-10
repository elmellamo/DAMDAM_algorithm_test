#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
int x,y,xx,yy, num, key;
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
char map[1001][1001];
int visited[2][1001][1001];

typedef struct{
    int x,y, num, key;
}info;

priority_queue<int, vector<int>, greater<int>> pq;
queue<info> q;

int isArea(int a, int b){
    if(a>-1 && a<N && b>-1 && b<M) return 1;
    else
        return 0;
}

void bfs(){
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        num = q.front().num;
        key = q.front().key;

        q.pop();


        for(int i=0;i<4;i++){
            xx = x + dx[i];
            yy = y + dy[i];

            if(isArea(xx,yy)){
                if(key==0){
                    if(map[xx][yy]=='0' && visited[0][xx][yy]==0){
                    q.push({xx, yy, num+1, key});
                    visited[0][xx][yy] = 1;
                    }
                    if(map[xx][yy]=='1' && visited[0][xx][yy]==0){
                        q.push({xx, yy, num+1, key+1});
                        visited[1][xx][yy] = 1;
                    }

                }
                
                else{
                    if(map[xx][yy]=='0' &&visited[1][xx][yy]==0){
                    q.push({xx, yy, num+1, key}); 
                    visited[1][xx][yy] = 1;
                    }

                }
                
                
            }
        }

    }

    if(x == N-1 && y ==M-1){
        pq.push(num);
    }

    memset(visited, 0, sizeof(visited));
}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>> map[i][j];
        }
    }

    q.push({0,0,1,0});
    visited[0][0][0] = 1;
    visited[1][0][0] = 1;
    bfs();
    //cout<<num<<'\n';

    if(pq.empty()){
        cout<<-1;
    }
    else{
        cout<<pq.top();
    }

    
}