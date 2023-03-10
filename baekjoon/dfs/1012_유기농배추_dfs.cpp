#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int map[51][51];
int visited[51][51];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};


int T, N, M, K; //N이 행
int a,b;
int ans;
int xx, yy;

int isArea(int a, int b){
    if(a>-1 && a<N && b>-1 && b<M) return 1;
    else
        return 0;
}

void dfs(int x, int y){
    visited[x][y] = 1;

    for(int i=0; i<4; i++){
        xx = x + dx[i];
        yy = y + dy[i];

        if(isArea(xx, yy)&&!visited[xx][yy] &&map[xx][yy]){
            dfs(xx, yy);
        }
    }
}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> T;

    for(int t=0; t<T; t++){
        cin >> M >> N >> K;
        //초기화
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        ans = 0; 

        for(int k=0; k<K; k++){
                cin >> a>>b;
                map[b][a] = 1;
        }
    
        //dfs 돌리기
        for(int i=0 ;i <N; i++){
            for(int j=0; j<M ; j++){
                if(map[i][j] && !visited[i][j]){
                    dfs(i, j);
                    ans++;
                }
            }
        }


        cout << ans<<'\n';
    }

}