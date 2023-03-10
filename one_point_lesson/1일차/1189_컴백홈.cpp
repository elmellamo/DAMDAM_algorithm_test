#include <iostream>
#include <memory.h>
using namespace std;

int R,C,K;
int ans;
char map[7][7];
int visited[7][7];
int copymap[7][7];

int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};

int isArea(int x, int y){
    if(x>-1 && x<R && y>-1 && y<C) return 1;
    else
        return 0;
}

void BT(int stx, int sty, int depth){
    int xx, yy; 
    visited[stx][sty] = 1;

    if(stx==0 && sty==C-1){
        if(depth==K-1){
            ans++;
        }
        /*
        cout<<"how:  "<<depth<<"\n";
        for(int i=0;i<R;i++){
            for(int j=0; j<C; j++){
                cout<<copymap[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
        */
        return;
    }


    for(int i=0; i<4; i++){
        xx = stx + dx[i];
        yy = sty + dy[i];

        if(map[xx][yy]=='.'&&!visited[xx][yy]&&isArea(xx,yy)){
            //copymap[xx][yy]=depth+1;
            BT(xx,yy,depth+1);
            visited[xx][yy]=0;
            //copymap[xx][yy]=0;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>R>>C>>K;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
        }
    }

    BT(R-1, 0, 0);
    cout<<ans;
}