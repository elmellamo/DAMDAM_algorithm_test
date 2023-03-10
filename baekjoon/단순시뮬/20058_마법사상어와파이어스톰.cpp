#include <iostream>
#include <memory.h>
#include <math.h>
#include <queue>
using namespace std;

typedef struct{
    int x, y;
}info;

queue<info> q;

int map[100][100];
int copymap[100][100];
int maxIce, cntIce;
int visited[100][100];
int N,Q,N2,L;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int isArea(int a, int b){
    return 0<a&&a<=N2&&0<b&&b<=N2;
}

void dfs(int x, int y){
    int xx,yy;
    visited[x][y]=1;
    cntIce++;

    for(int i=0; i<4; i++){
        xx = x+dx[i];
        yy = y+dy[i];

        if(!visited[xx][yy]&&map[xx][yy]>0&&isArea(xx,yy)){
            dfs(xx,yy);
        }
    }
    
}

void testRec(int L){
    int how, l, t;
    how = pow(2, N-L);
    l = pow(2, L);

    if(L!=0 && L!=N){
        //T==row 기준
    for(int T=1; T<=how; T++){
        t = l*(T-1)+1;
        for(int h=0; h<how; h++){
            int tmpy=0;
            for(int i=t; i<t+l; i++){
                int tmpx=0;
                for(int j=h*l+1 ; j<l*(h+1)+1; j++){
                        copymap[t+tmpx][l*(h+1)-tmpy] = map[i][j];
                        tmpx++;
                }
                tmpy++;
            }
        }
    }
    }else if(L==N){
        int tmpy=0;
        for(int i=1; i<1+l; i++){
            int tmpx=0;
            for(int j=1 ; j<l+1; j++){
                //cout<<1+tmpx<<" "<<l-tmpy<<", "<<i<<" "<<j<<"\n";
                copymap[1+tmpx][l-tmpy] = map[i][j];
                tmpx++;
            }
            tmpy++;
        }
    }else{
        for(int i=1; i<=N2; i++){
            for(int j=1; j<=N2; j++){
                copymap[i][j] = map[i][j];
            }
        }
    }
    
}

void changeMap(){
    for(int i=1; i<=N2; i++){
        for(int j=1; j<=N2; j++){
            map[i][j] = copymap[i][j];
        }
    }
}

void shrinkIce(){
    int x, y, key;
    for(int i=1; i<=N2; i++){
        for(int j=1; j<=N2; j++){
            if(map[i][j]>0){
                for(int t=0; t<4; t++){
                    x = i + dx[t];
                    y = j + dy[t];
                    if(!isArea(x,y) || map[x][y]==0){
                        key++;
                    }
                }

                if(key>1){
                    q.push({i, j});
                }
                key=0;
            }
        }
    }

    int xx, yy;
    while(!q.empty()){
        xx = q.front().x;
        yy = q.front().y;
        
        map[xx][yy] = map[xx][yy] -1;
        q.pop();
    }
}

void printMap(){
    for(int i=1; i<=N2; i++){
        for(int j=1; j<=N2; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

void printcopyMap(){
    for(int i=1; i<=N2; i++){
        for(int j=1; j<=N2; j++){
            cout<<copymap[i][j];
        }
        cout<<"\n";
    }
}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>Q;
    N2 = pow(2,N);

    for(int i=1; i<=N2; i++){
        for(int j=1; j<=N2; j++){
            cin>>map[i][j];
        }
    }

    for(int q=0; q<Q; q++){
        cin>>L;
        memset(copymap, 0, sizeof(copymap));
        testRec(L);
        //cout<<q+1<<"time copymap>> \n";
        //printcopyMap();
        changeMap();
        //cout<<q+1<<"not change map>> \n";
        //printMap();
        shrinkIce();
        //cout<<q+1<<"time map>> \n";
        //printMap();
        //cout<<"\n";
    }

    for(int i=1; i<=N2; i++){
        for(int j=1; j<=N2; j++){
            if(!visited[i][j]&&map[i][j]>0){
                dfs(i,j);
                maxIce = maxIce>cntIce?maxIce:cntIce;
                cntIce=0;
            }
        }
    }

    cntIce=0;
    for(int i=1; i<=N2; i++){
        for(int j=1; j<=N2; j++){
            cntIce+=map[i][j];
        }
    }

    cout<<cntIce<<"\n"<<maxIce;

    
}