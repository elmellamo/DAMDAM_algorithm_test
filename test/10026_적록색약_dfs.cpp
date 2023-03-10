#include <iostream>
using namespace std;

int N;
char map[107][107];
int visited[107][107];
int blindvisited[107][107];

int ans, blindans;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int isArea(int a, int b){
    if(a>-1&&a<N&&b>-1&&b<N) return 1;
    else
        return 0;
}

void dfs(int x,int y,char z){
    visited[x][y]=1;

    int xx,yy;
    for(int i=0; i<4;i++){
        xx = x+dx[i];
        yy = y+dy[i];

        if(map[xx][yy]==z&&!visited[xx][yy]&&isArea(xx,yy)){
            dfs(xx,yy,z);
        }
    }
}

void blinddfs(int x,int y,char z){
    blindvisited[x][y]=1;

    int xx,yy;
    for(int i=0; i<4;i++){
        xx = x+dx[i];
        yy = y+dy[i];

        if(z=='B'){
            if(map[xx][yy]==z&&!blindvisited[xx][yy]&&isArea(xx,yy)){
            blinddfs(xx,yy,z);
            }
        }
        else{
            if(map[xx][yy]!='B'&&!blindvisited[xx][yy]&&isArea(xx,yy)){
            blinddfs(xx,yy,z);
        }
        }
        
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                dfs(i,j,map[i][j]);
                ans++;
            }

            if(!blindvisited[i][j]){
                blinddfs(i,j,map[i][j]);
                blindans++;
            }
        }
    }

    cout<<ans<<" "<<blindans;


}