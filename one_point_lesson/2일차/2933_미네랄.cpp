#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    int x,y;
}info;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

vector<int> v;
queue<info> q;
char map[107][107];
int copymap[107][107];
int visited[107][107];
int R, C, N, H;
int rstx, rsty;

int isArea(int a, int b){
    return 0<a&&a<=R&&0<b&&b<=C;
}
void destroyM(int ori, int h){
    if(ori){
        for(int i=1; i<=C; i++){
            if(map[R-h+1][i]=='x'){
                map[R-h+1][i]='.';
                break;
            }
        }
    }
    else{
        for(int i=C; i>0; i--){
            if(map[R-h+1][i]=='x'){
                map[R-h+1][i]='.';
                break;
            }
        }
    }
    
}

void testBfs(){
    int key;
    int x,y, xx,yy;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(map[i][j]=='x' && !visited[i][j]){
                q.push({i,j});
                visited[i][j]=1;
                key = 0;
                while(!q.empty()){
                    x = q.front().x;
                    y = q.front().y;
                    q.pop();

                    if(x==R){
                        key=1;
                    }

                    for(int i=0; i<4;i++){
                        xx = x+dx[i];
                        yy = y+dy[i];

                    if(isArea(xx,yy)&&map[xx][yy]=='x'&&!visited[xx][yy]){
                        q.push({xx,yy});
                        visited[xx][yy]=1;
                    }
                    }
                }

                if(!key){
                    rstx = x;
                    rsty = y;
                }
            }
        }
    }
}

void bfs(){
    q.push({rstx, rsty});
    map[rstx][rsty]='.';
    copymap[rstx][rsty]=1;
    visited[rstx][rsty]=1;

    int x,y, xx,yy;
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        q.pop();

        for(int i=0; i<4;i++){
            xx = x+dx[i];
            yy = y+dy[i];

            if(isArea(xx,yy)&&map[xx][yy]=='x'&&!visited[xx][yy]){
                q.push({xx,yy});
                map[xx][yy]='.';
                copymap[xx][yy]=1;
                visited[xx][yy]=1;
            }
        }

    }
}

void testAir(){
    int ground, crystal;
    int minR;

    for(int i=1; i<=C; i++){
        for(int j=R; j>0; j--){
            if(copymap[j][i]){
                ground = R-j;
                crystal=-1;
                for(int t=j;t<=R;t++){
                    if(map[t][i]=='x'){
                        crystal = t-j-1;
                        break;
                    }
                }

                if(crystal!=-1){
                    minR=ground>crystal?crystal:ground;
                }else{
                    minR = ground;
                }

                //cout<<j<<" "<<i<<" "<<minR<<"\n";

                v.push_back(minR);

                break;
            }
        }
    }
}

void changeMap(){
    int howMin;
    howMin = 0;
    sort(v.begin(), v.end());
    
    if(!v.empty()){
        howMin = v.front();
    }
    //cout<<"howMin"<<howMin<<"\n";
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(copymap[i][j]){
                map[i+howMin][j]='x';
            }
        }
    }

}

void printMap(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

void printcopyMap(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<copymap[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>R>>C;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin>>map[i][j];
        }
    }

    cin>>N;

    for(int i=1; i<=N; i++){
        cin>>H;
        destroyM(i%2, H);
        //cout<<"destroy\n";
        //printMap();
        testBfs();
        memset(visited, 0, sizeof(visited));
        
        if(rstx!=0 && rsty!=0){
            bfs();
            testAir();
            changeMap();
            //cout<<"changeMap\n";
            //printMap();

            memset(visited, 0, sizeof(visited));
            memset(copymap, 0, sizeof(copymap));
            while(!v.empty()){
                v.pop_back();
            }
        }
        //else{
            //cout<<"nthMap\n";
            //printMap();
        //}
        rstx = 0;
        rsty = 0;
        
    }
    //cout<<"final\n";
    printMap();
}