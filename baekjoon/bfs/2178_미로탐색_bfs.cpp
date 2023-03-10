#include <iostream>
#include <queue>
using namespace std;

typedef struct{
    int x,y;
    int num;
}info; 

queue<info> q;
int N, M;
char map[107][107];
int visited[107][107];

int x,y,xx,yy, num;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0,-1,1,0};
int ans;

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
    q.pop();


    if(x==N-1 && y == M-1){
        ans = num;
        break;
    }

    for(int i=0; i<4; i++){
        xx = x + dx[i];
        yy = y + dy[i];

        if(isArea(xx, yy) && map[xx][yy] == '1' && !visited[xx][yy]){
            q.push({xx, yy, num+1});
            visited[xx][yy] = 1;
        }

    }

    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }

    q.push({0,0, 1});
    bfs();
    cout<<ans;

}