#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct{
    int x,y;
}fire;
typedef struct{
    int x, y, num;
}info;

queue<fire> fireq;
queue<info> escapeq;

int T, w, h;
int key;
char map[1007][1007];
int visited[1007][1007];
int mapvisited[1007][1007];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int x, y, xx, yy, firenum;
int escapex, escapey, escapexx, escapeyy, num;
int escapenum;
int a,b;

int isArea(int a, int b){
    if(a>-1 && a<h && b>-1 && b<w) return 1;
    else
        return 0;
}

void firebfs(){
    
    while(!escapeq.empty()){

        firenum = fireq.size();
        
        for(int i=0; i<firenum; i++){
        x = fireq.front().x;
        y = fireq.front().y;
        fireq.pop();

        //cout<<x<<" "<<y<<'\n';
        
        
        for(int i=0; i<4; i++){
            xx = x + dx[i];
            yy = y + dy[i];

            if(isArea(xx, yy)&& map[xx][yy]=='.'){
                map[xx][yy] = '*';
                fireq.push({xx, yy});
            }
        }}

        escapenum = escapeq.size();
        for(int i=0; i<escapenum; i++){
        escapex = escapeq.front().x;
        escapey = escapeq.front().y;
        num = escapeq.front().num;

        
        escapeq.pop();

        
        //cout<<escapex<<" "<<escapey<<'\n'; 
        if(escapex==0 || escapex==h-1 ||escapey==0 ||escapey==w-1){
            key=1;
            return;
        }


        for(int i=0; i<4; i++){
            escapexx = escapex + dx[i];
            escapeyy = escapey + dy[i];

            if(isArea(escapexx, escapeyy) && map[escapexx][escapeyy]=='.' && !visited[escapexx][escapeyy]){
                        escapeq.push({escapexx, escapeyy, num+1});
                        visited[escapexx][escapeyy] = 1;
            }
        }
        }   

        }

    }
    



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T;
    for(int t=0; t<T;t++){
        cin >>w>>h;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        memset(mapvisited, 0, sizeof(mapvisited));


        for(int i=0; i<h; i++){
            for(int j=0; j<w;j++){
                cin>>map[i][j];
                if(map[i][j]=='*')
                    fireq.push({i, j});
                if(map[i][j]=='@'){
                    a = i;
                    b = j;
                    map[i][j] = '.';
                }
            }
        }
        visited[a][b] = 1;
        escapeq.push({a,b,1});


        firebfs();
        if(key!=1) cout<<"IMPOSSIBLE"<<"\n";
        else
            cout<<num<<"\n";

        while(!fireq.empty()){
            fireq.pop();}
        while(!escapeq.empty()){
            escapeq.pop();
        }

        key=0;

    }





}
