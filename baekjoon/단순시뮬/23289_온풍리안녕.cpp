#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct{
    int x, y, dir;
}info;

typedef struct{
    int x, y;
}INFO;

typedef struct{
    int x, y, num, dir;
}blow;

int chocoAns, hotternum;
queue<blow> blowq;
vector<INFO> whatT;
vector<info> makeHot;
vector<INFO> chain[27][27];
int R,C,K,W;
int key;
int map[27][27];
int devidemap[27][27];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int visited[27][27];

int isArea(int x, int y){
    if(-1<x && x<R && -1<y && y<C) return 1;
    else
        return 0;
}

int checkChain(int a, int b, int c, int d){
    int chainsize;
    chainsize = chain[a][b].size();

    int chainkey=0; 
    for(INFO checkinfo : chain[a][b]){
        if(c==checkinfo.x && d==checkinfo.y){
            chainkey=1;
            break;
        }
    }

    return chainkey;
}

void printMap(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int isComplete(){
    int whatsize;
    int ckey = 1;
    whatsize = whatT.size();

    int r, c;
    for(int i=0; i<whatsize; i++){
        r = whatT[i].x;
        c = whatT[i].y;

        if(map[r][c]<K){
            ckey=0;
            break;
        }
    }

    return ckey;
}

void controlF(){
    for(int i=0; i<R; i++){
        if(map[i][0]>0){
            map[i][0] -= 1;
        }
    }
    for(int i=0; i<R; i++){
        if(map[i][C-1]>0){
            map[i][C-1] -= 1;
        }
    }
    for(int j=1; j<C-1; j++){
        if(map[0][j]>0){
            map[0][j] -= 1;
        }
    }
    for(int j=1; j<C-1; j++){
        if(map[R-1][j]>0){
            map[R-1][j] -= 1;
        }
    }
}

void controlT(){
    int xx, yy, howmuch, rst;

    memset(devidemap, 0, sizeof(devidemap));

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j]>0){
                howmuch=0; rst=map[i][j];

                for(int d=0; d<4; d++){
                    xx = i + dx[d];
                    yy = j + dy[d];

                    if(isArea(xx, yy)){
                        if(!checkChain(i, j, xx, yy)){
                            howmuch = (map[i][j] - map[xx][yy])/4;
                            if(howmuch >0){
                                devidemap[xx][yy] += howmuch;
                                rst -= howmuch;
                            }
                        }
                    }
                }

                devidemap[i][j] += rst;
            }
        }
    }

    memset(map, 0, sizeof(map));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            map[i][j] = devidemap[i][j];
        }
    }
}

void blowHot(){
    int x, y, xx, yy, num, dir;
    while(!blowq.empty()){
        x = blowq.front().x;
        y = blowq.front().y;
        num = blowq.front().num;
        dir = blowq.front().dir;

        blowq.pop();

        if(num>1){
            if(dir<2){
                for(int i=-1; i<2; i++){
                    xx = x + i;
                    yy = y + dy[dir];
                    if(isArea(xx,yy) && !visited[xx][yy]){
                        if(!checkChain(xx,y, xx, yy) && !checkChain(x,y, xx, y)){
                            map[xx][yy] += (num-1);
                            visited[xx][yy] = 1;
                            blowq.push({xx, yy, num-1, dir});
                        }
                }
            }
            }else if(dir>1){
                for(int i=-1; i<2; i++){
                    xx = x + dx[dir];
                    yy = y + i;
                    if(isArea(xx,yy) && !visited[xx][yy]){
                        if(!checkChain(x,yy,xx,yy)&& !checkChain(x,y, x, yy)){
                            map[xx][yy] += (num-1);
                            visited[xx][yy] = 1;
                            blowq.push({xx, yy, num-1, dir});
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>R>>C>>K;

    int tmp;
    for(int r=0;r<R; r++){
        for(int c=0; c<C; c++){
            cin>>tmp;
            if(0<tmp && tmp<5){
                hotternum++;
                makeHot.push_back({r,c,tmp-1});
            }else if(tmp==5){
                whatT.push_back({r, c});
            }
        }
    }

    cin>>W;

    int r, c;
    for(int w=0; w<W; w++){
        cin>>r>>c>>tmp;
        if(tmp==0){
            chain[r-1][c-1].push_back({r-2, c-1});
            chain[r-2][c-1].push_back({r-1, c-1});
        }else{
            chain[r-1][c-1].push_back({r-1, c});
            chain[r-1][c].push_back({r-1, c-1});
        }
    }

    key=0;
    int cnt=0;
    while(!key){
        //한 번 시행 시 
        cnt++;
        for(int t=0; t<hotternum; t++){
            memset(visited, 0, sizeof(visited));
            //바람 불기
            int hx, hy, hd;
            hx = makeHot[t].x;
            hy = makeHot[t].y;
            hd = makeHot[t].dir;
            int hhx, hhy;
            hhx = hx + dx[hd];
            hhy = hy + dy[hd];
            map[hhx][hhy] += 5;
            blowq.push({hhx, hhy, 5, hd});
            blowHot();
            //cout<<hx<<","<<hy<<" >> cnt>>"<<cnt<<"\n" ;   
            //printMap();
        }
        controlT();
        controlF();
        chocoAns++;
        key = isComplete();

        if(chocoAns>100){
            break;
        }
    }

    //cout<<"\n\n최종최종\n";
    //printMap();

    if(chocoAns>100){
        cout<<101;
    }else{
        cout<<chocoAns;
    }
}