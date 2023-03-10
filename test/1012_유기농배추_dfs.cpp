#include <iostream>
#include <memory.h>
using namespace std;

int T, M, N, K, a,b;
int ans;
int xx,yy;
int map[57][57];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int visited[57][57];

int isArea(int a, int b){
    if(a>-1&&a<N&&b>-1&&b<M) return 1;
    else
        return 0;
}

void dfs(int x, int y){
    visited[x][y]=1;

    for(int i=0; i<4; i++){
        xx=x+dx[i];
        yy=y+dy[i];

        if(isArea(xx,yy)&&map[xx][yy]&&!visited[xx][yy]){
            dfs(xx,yy);
        }
    }
}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T;

    for(int t=0; t<T; t++){
        cin>>M>>N>>K;

        for(int k=0; k<K; k++){
            cin>>b>>a;
            map[a][b]=1;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j]&&!visited[i][j]){
                    dfs(i,j);
                    ans++;
                }
            }
        }

        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));

        cout<<ans<<"\n";
        ans=0;
    }

}