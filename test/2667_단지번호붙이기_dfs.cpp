#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char map[30][30];
int visited[30][30];
int N, ans;
vector<int> v;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int isArea(int a, int b){
    if(a>-1&&a<N&&b>-1&&b<N) return 1;
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

        if(map[xx][yy]=='1'&&!visited[xx][yy]&&isArea(xx,yy)){
            dfs(xx,yy);
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            if(map[i][j]=='1'&&!visited[i][j]){
                dfs(i,j);
                v.push_back(ans);
                ans=0;
            }
        }
    }

    sort(v.begin(), v.end());
    cout<<v.size()<<"\n";
    for(int i:v){
        cout<<i<<"\n";
    }


}