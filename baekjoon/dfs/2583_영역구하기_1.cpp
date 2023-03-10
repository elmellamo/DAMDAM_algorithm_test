#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, xx, yy;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int map[107][107];
int visited[107][107];
int cnt, composecnt;
vector<int> composeArray;

int isArea(int x, int y){
    if(-1<x&& x<N &&-1<y&&y<M) return 1;
    else
        return 0;
}

void makeMap(int a, int b, int c, int d){
    for(int i=a; i<c; i++){
        for(int j=b; j<d; j++){
            map[i][j]=1;
        }
    }
}

void dfs(int x, int y){
    visited[x][y]=1;
    composecnt++;

    for(int d=0; d<4; d++){
        xx = x+dx[d];
        yy = y+dy[d];
        if(isArea(xx, yy)&& map[xx][yy]==0 && !visited[xx][yy]){
            dfs(xx,yy);
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>M>>N>>K;

    int a,b,c,d;
    for(int k=0; k<K; k++){
        cin>>a>>b>>c>>d;
        makeMap(a,b,c,d);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]==0 && !visited[i][j]){
                composecnt = 0;
                dfs(i,j);
                cnt++;
                composeArray.push_back(composecnt);
            }
        }
    }

    sort(composeArray.begin(), composeArray.end());
    cout<<cnt<<"\n";
    for(int ans:composeArray){
        cout<<ans<<" ";
    }

}
