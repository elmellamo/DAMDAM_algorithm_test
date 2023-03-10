#include <iostream>
#include <memory.h>

using namespace std;

int N,M;
int map[9][9];
int visited[9][9];
int x,y, xx, yy;
int ans, tmp;

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

void printMap(){
        for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

void countSafe(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && map[i][j]==0) tmp++;
        }
    }
}

int isArea(int a, int b){
    if(a>-1 && a<N && b>-1 && b<M) return 1;
    else
        return 0;
}

void virusDFS(int i, int j){
    visited[i][j] =1;
    
    for(int k=0; k<4; k++){
        xx = i + dx[k];
        yy = j + dy[k];

        if(map[xx][yy] ==0 && isArea(xx,yy) && !visited[xx][yy]){
            virusDFS(xx, yy);
        }
    }
}

void BT(int pos, int depth){
    if(depth==3){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j]==2 && !visited[i][j]){
                    virusDFS(i, j);
                }
            }
        }

        countSafe();
        
        //printMap();
        //cout<<tmp<<"\n"<<"========="<<'\n';

        if(ans<tmp) ans=tmp;
        memset(visited, 0, sizeof(visited));
        tmp=0;
        return;
    }

    for(int next=pos+1; next<N*M; next++){
        int r = next/M;
        int c = next%M;

        if(map[r][c]==0){
            map[r][c]=1;
            BT(next, depth+1);
            map[r][c]=0;
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

    BT(-1, 0);

    cout<<ans;

}