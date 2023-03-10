#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct{
    int x, num;
}info;

int N, K;
int present, num, minusone, plusone, multitwo;
int ans;
queue<info> q;
int visited[100007];

int isArea(int a){
    if(a>-1 &&a<100001) return 1;
    else
        return 0;
}

void bfs(){
    while(!q.empty()){
        present = q.front().x;
        num = q.front().num;
        q.pop();

        if(present == K){
            ans = num;
            break;
        }

        minusone = present - 1;
        plusone = present +1;
        multitwo = present * 2;

        if(isArea(minusone)){
            if(visited[minusone]!=1){
            q.push({minusone, num+1});
            visited[minusone]=1;
            }
        }

        if(isArea(plusone)){
            if(visited[plusone]!=1){
            q.push({plusone, num+1});
            visited[plusone]=1;
            }
        }

        if(isArea(multitwo)){
            if(visited[multitwo]!=1){
            q.push({multitwo, num+1});
            visited[multitwo]=1;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    memset(visited, 0, sizeof(visited));
    cin>>N>>K;
    visited[N]==1;
    q.push({N, 0});
    bfs();
    cout<<ans;
}