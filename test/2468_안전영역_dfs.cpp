#include <iostream>
#include <memory.h>
using namespace std;

int N;
int ans, max;
int map[107][107];
int visited[107][107];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int isArea(int a, int b){
    if(a>-1&&a<N&&b>-1&&b<N) return 1;
    else
        return 0;
}

void dfs(int x, int y){
    visited[x][y]=1;
    int xx,yy;
    for(int i=0; i<4; i++){
        xx = x+dx[i];
        yy = y+dy[i];

        if(map[i][j]>0 && isArea(xx,yy)&&!visited[xx][yy]){
            dfs(xx, yy);
        }
    }
}

void displayArea(int how){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==how) map[i][j]=0;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    int a,b; // b is the tallest area
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            a= map[i][j];
            b = b>a?b:a;
        }
    }

    for(int t=1;t<b+1;t++){
        displayArea(t);
        memset(visited, 0, sizeof(visited));
        
        for(int i=0; i<N;i++){
            for(int j=0; j<N; j++){
                if(!map[i][j])
        }
    }
    }

}