#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, cnt, maxH;
vector<int> cntArray;
int xx, yy;
int map[107][107];
int visited[107][107];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int isArea(int x, int y){
    if(-1<x&& x<N && -1<y && y<N) return 1;
    else
        return 0;
}

void makeZ(int h){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]==h){
                    map[i][j]=0;
            }
        }
    }
}

void dfs(int x, int y){
    visited[x][y]=1;

    for(int d=0; d<4; d++){
        xx = x+dx[d];
        yy = y+dy[d];
        if(isArea(xx, yy)&& map[xx][yy]>0 && !visited[xx][yy]){
            dfs(xx, yy);
        }
    }
}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    int tmp; 
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            maxH = maxH>map[i][j]?maxH:map[i][j];
        }
    }

    for(int h=0; h<=maxH; h++){
        makeZ(h);
        cnt=0; 

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j]>0 && !visited[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cntArray.push_back(cnt);
        memset(visited, 0, sizeof(visited));
    }

    sort(cntArray.begin(), cntArray.end());
    int cntSize;
    cntSize = cntArray.size();
    cout<<cntArray[cntSize-1];

}