#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[107][107];
int visited[107][107];
int N,M,K, ans;
vector<int> v;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int isArea(int a, int b){
    if(a>-1&&a<N&&b>-1&&b<M) return 1;
    else
        return 0;
}

void dfs(int x,int y){
    visited[x][y]=1;
    ans++;

    int xx,yy;
    for(int i=0; i<4;i++){
        xx = x+dx[i];
        yy = y+dy[i];

        if(map[xx][yy]&&!visited[xx][yy]&&isArea(xx,yy)){
            dfs(xx,yy);
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        int a,b;
        cin>>a>>b;
        map[a-1][b-1]=1;
    }

    for(int i=0; i<N;i++){
        for(int j=0; j<M; j++){
            if(map[i][j]&&!visited[i][j]){
                dfs(i,j);
                v.push_back(ans);
                ans=0;
            }
        }
    }

    sort(v.begin(), v.end());
    cout<<v.back();


}