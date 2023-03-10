#include <iostream>
#include <queue>
using namespace std;

typedef struct{
    int x, num;
}info;

queue<info> q;
int map[1000007];
int visited[1000007];

int F,S,G,U,D;
int x, num, xx;
int ans;

int isArea(int a){
    if(a>0 && a<F+1) return 1;
    else
        return 0;
}

void bfs(){
    while(!q.empty()){ 
        x= q.front().x;
        num = q.front().num;

        q.pop();

        if(x==G){
            ans = num;
            break;
        }

        xx = x+U;
        if(isArea(xx)&& !visited[xx]){
            q.push({xx, num+1});
            visited[xx] = 1;
        }

        xx = x - D;
        if(isArea(xx)&& !visited[xx]){
            q.push({xx, num+1});
            visited[xx] = 1;
        }

    }
}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>F>>S>>G>>U>>D;
    q.push({S, 0});
    
    ans=-1;
    bfs();

    if(ans==-1){
        cout<<"use the stairs"<<'\n';
    }
    else
        cout<<ans;
}