#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef struct{
    int x, y;
    int num;
}info;

queue<info> q;

int T, l;
int map[307][307];
int visited[307][307];
int gox, goy, stx, sty;
int xx,yy, num, x, y;
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int ans;

int isArea(int a, int b){
    if(a>-1 && a<l && b>-1 && b<l) return 1;
    else
        return 0;
}

void bfs(){
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        num = q.front().num;

        q.pop();

        if(x==gox && y == goy){
            ans = num;
            break;
        }

        for(int i=0; i<8;i++){
            xx = x +dx[i];
            yy = y + dy[i];

            if(isArea(xx, yy) && !visited[xx][yy]){
                q.push({xx, yy, num+1});
                visited[xx][yy] = 1;
            }
        }
    }
}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T;

    for(int t=0 ; t<T; t++){
        cin>>l;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));

        cin>>stx>>sty;
        cin>>gox>>goy;

        q.push({stx, sty, 0});

        bfs();
        
        cout<<ans<<'\n';

        while(!q.empty()){
            q.pop();
        }

    }
}