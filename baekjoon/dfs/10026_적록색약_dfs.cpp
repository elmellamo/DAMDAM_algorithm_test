#include <iostream>
#include <memory.h>
using namespace std;

char tmp;
int map[101][101];
int visited[101][101];

int N;
int xx, yy;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int ans;

int isArea(int a, int b){
    if(a>-1&&a<N&&b>-1&&b<N) return 1;
    else   
        return 0;
}

void dfs_R(int x, int y){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        xx = x+dx[i];
        yy = y+dy[i];
        if(isArea(xx,yy) && map[xx][yy]==1 && !visited[xx][yy]){
            dfs_R(xx,yy);
        }
    }
}

void dfs_G(int x, int y){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        xx = x+dx[i];
        yy = y+dy[i];
        if(isArea(xx,yy) && map[xx][yy]==2 && !visited[xx][yy]){
            dfs_G(xx,yy);
        }
    }
}

void dfs_B(int x, int y){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        xx = x+dx[i];
        yy = y+dy[i];
        if(isArea(xx,yy) && map[xx][yy]==0 && !visited[xx][yy]){
            dfs_B(xx,yy);
        }
    }
}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int i=0 ; i<N;i++){
        for(int j=0;j<N;j++){
            cin>>tmp;
            if(tmp == 'R') map[i][j] = 1;
            else if(tmp=='G') map[i][j] =2;
            else
                map[i][j]=0;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            if(map[i][j]==1 && !visited[i][j]){
                dfs_R(i,j);
                ans++;
            }
            else if(map[i][j]==2 && !visited[i][j]){
                dfs_G(i, j);
                ans++;
            }
            else if(map[i][j]==0 && !visited[i][j]){
                dfs_B(i, j);
                ans++;
            }
        }
    }

    cout<< ans<<" ";

    memset(visited, 0, sizeof(visited));
    ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]>0) map[i][j]=1;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            if(map[i][j]==1 && !visited[i][j]){
                dfs_R(i,j);
                ans++;
            }
            else if(map[i][j]==0 && !visited[i][j]){
                dfs_B(i, j);
                ans++;
            }
        }
    }

    cout<<ans;
}