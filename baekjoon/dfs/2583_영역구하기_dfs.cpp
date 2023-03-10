#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M, K;
int map[101][101];
int visited[101][101];
int a,b,c,d;
int xx, yy;
int dx[4] = {0,0,-1, 1};
int dy[4] = {-1,1,0,0};
int ans;
int tmp;
vector<int> v;

int isArea(int a, int b){
    if(a>-1&&a<N&&b>-1&&b<M) return 1;
    else
        return 0;
}

void dfs(int x, int y){
    visited[x][y]=1;
    tmp++;
    for(int i=0;i<4;i++){
        xx= x+dx[i];
        yy = y+dy[i];
        if(isArea(xx,yy)&&map[xx][yy]&&!visited[xx][yy]){
            dfs(xx,yy);
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M>>K;

    memset(map, 1, sizeof(map));
    for(int i=0; i<K; i++){
        cin >> a>>b>>c>>d;
        for(int i=b;i<d;i++){
            for(int j=a;j<c;j++){
                map[i][j] = 0;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]&&!visited[i][j]){
                tmp = 0;
                dfs(i, j);
                v.push_back(tmp);
                ans++;
            }
        }
    }

    cout<< ans<<'\n';
    sort(v.begin(), v.end());
    for(int i:v){
        cout<<i<<" ";
    }

}