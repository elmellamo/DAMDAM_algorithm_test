#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

typedef struct{
    int x,y;
}info;

queue<info> q;
int T, k;
int n,m; // n이 행, m이 열
int x,y,xx,yy, a,b;
int ans;
vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

int map[55][55];
int visited[55][55];


int isArea(int a, int b){
    if(a>-1&&a<n&&b>-1&&b<m) return 1;
    else
        return 0;
}

void bfs(){
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        q.pop();

        for(int i=0;i<4;i++){
            xx = x+dx[i];
            yy = y+dy[i];

            if(isArea(xx, yy)){
                if(map[xx][yy]==1 && visited[xx][yy]==0){
                    q.push({xx,yy});
                    visited[xx][yy]=1;
                }
            }
        }
    }
}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    cin>>T;


    for(int t=0;t<T;t++){
        cin >>m>>n>>k;
        ans = 0;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));

        //큐 비우기
        while(!q.empty()) q.pop();

        for(int i=0;i<k; i++){
            cin>>a>>b;
            map[b][a]=1;
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]==1 && !visited[i][j]){
                    q.push({i,j});
                    visited[i][j]=1;
                    bfs();
                    ans++;
                }
            }
        }

        cout<<ans<<endl;
    }

}