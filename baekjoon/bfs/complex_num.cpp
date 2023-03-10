#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct{
    int x; int y;
}info;

queue<info> q;

vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,1,-1};
int x,y,xx,yy;
int n; //지도 크기
int ans;

priority_queue<int, vector<int>, greater<int>> pq;
vector<vector<int>> visited;
vector<vector<char>> map;

int isArea(int a, int b){
    if(a>-1&&a<n&&b>-1&&b<n) return 1;
    else
        return 0;
}


void bfs(int k){
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;

        k++;
        q.pop();

        for(int i=0;i<4;i++){
            xx = x+dx[i];
            yy = y +dy[i];
            
            if(isArea(xx, yy)){
                if(map[xx][yy]=='1' && visited[xx][yy]==0){
                    q.push({xx,yy});
                    visited[xx][yy]=1;
                }
            }
        }



    }
    
    //cout<<k;
    pq.push(k);
}

int main(){
    cin >> n;

    map.resize(n, vector<char>(n));
    visited.resize(n, vector<int>(n, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            }
        }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]=='1'&&visited[i][j]==0){
                q.push({i,j});
                ans=0;
                visited[i][j]=1;
                bfs(ans);
        }
    }}

    cout<<pq.size()<<endl;    
    
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }


}