#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int rst, key;
int R,C;
int mmax;
int visited[30];
char map[27][27];
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};

int isArea(int x, int y){
    if(x>-1 && x<R && y>-1 && y<C) return 1;
    else
        return 0;
}

void BT(int stx, int sty, int depth){
    int xx,yy, tmp, ttmp;
    ttmp = map[stx][sty]-65;
    visited[ttmp]=1;
    
    for(int i=0; i<4 ; i++){
        xx = stx + dx[i];
        yy = sty + dy[i];

        tmp = map[xx][yy]-65;

        if(!visited[tmp]&&isArea(xx,yy)){
            key++;
        }
    }

    if(key==0){
        mmax = mmax>depth?mmax:depth;
        return;
    }

    key=0;

    for(int i=0; i<4 ; i++){
        xx = stx + dx[i];
        yy = sty + dy[i];

        tmp = map[xx][yy]-65;

        if(!visited[tmp]&&isArea(xx,yy)){
            BT(xx,yy,depth+1);
            visited[tmp]=0;
        }
    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>R>>C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
        }
    }
    BT(0,0,1);

    cout<<mmax;

    
}