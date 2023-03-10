#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, C;
char map[27][27];
int visited[30];
int ans;
int mmax;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int isArea(int x, int y){
    if(-1<x&&x<R&&-1<y&&y<C) return 1;
    else    
        return 0;
}

void checkC(int r, int c){
    mmax = ans>mmax? ans:mmax;
    
    for(int i=0; i<4; i++){
        int xx = r+dx[i];
        int yy = c+dy[i];
        if(isArea(xx,yy) &&!visited[map[xx][yy]-'A']){
            visited[map[xx][yy]-'A']=1;
            ans++;
            checkC(xx, yy);
            ans--;
            visited[map[xx][yy]-'A']=0;
        }
    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>R>>C;
    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            cin>>map[r][c];
        }
    }

    ans=1;
    visited[map[0][0]-'A']=1;

    checkC(0,0);
    cout<<mmax;
}