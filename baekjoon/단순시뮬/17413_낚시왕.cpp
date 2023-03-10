#include <iostream>
#include <queue>
using namespace std;
typedef struct{
    int s, d, z;
}info;

queue<info> map[107][107];
queue<info> tmpmap[107][107];
queue<info> copymap[107][107];
int R, C, M, ans;
int sharkr, sharkc, sharks, sharkd, sharkz;

int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,1,-1};

void eatShark(int c){
    for(int i=1; i<=R; i++){
        if(!map[i][c].empty()){
            ans += map[i][c].front().z;
            map[i][c].pop();
            break;
        }
    }
}

void oneMove(int r, int c, int speed, int ori, int size){
    int x,y, tmpspeed;
    x = r; y = c;
    tmpspeed = speed;
    if(ori<3){
        if(x==1&&ori==1&&speed!=0){
            ori = 2;
        }else if(x==R &&ori==2&&speed!=0){
            ori=1;
        }

        speed = speed%(2*R-2);
        for(int s=0; s<speed; s++){
            if(x==1&&ori==1){
                ori = 2;
            }else if(x==R &&ori==2){
                ori=1;
            }
                x = x+dx[ori];
        }
        
    }else{
        if(y==1&&ori==4&&speed!=0){
            ori = 3;
        }else if(y==C&&ori==3&&speed!=0){
            ori=4;
        }
        speed = speed%(2*C-2);
        for(int s=0; s<speed; s++){
            if(y==1&&ori==4){
                ori = 3;
            }else if(y==C&&ori==3){
                ori=4;
            }
            
            y = y+dy[ori];
        }
    }
    map[r][c].pop();
    //cout<<x<<" "<<y<<" "<<tmpspeed<<" "<<ori<<" "<<size<<"\n";
    tmpmap[x][y].push({tmpspeed, ori, size});
}

void moveShark(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(!map[i][j].empty()){
                oneMove(i, j, map[i][j].front().s, map[i][j].front().d, map[i][j].front().z);
            }
        }
    }

    int tmpmapsize;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            tmpmapsize = tmpmap[i][j].size();
            if(tmpmapsize>0){
                for(int t=0; t<tmpmapsize;t++){
                    map[i][j].push({tmpmap[i][j].front().s,tmpmap[i][j].front().d, tmpmap[i][j].front().z});
                    tmpmap[i][j].pop();
                }
            }
        }
    }
}

void deleteShark(){
    int sharksize, maxtmp;
    int ss,dd,zz;
    for(int i=1;i<=R;i++){
        for(int j=1; j<=C;j++){
            sharksize = map[i][j].size();
            if(sharksize>0){
                maxtmp = map[i][j].front().z;
                for(int s=0; s<sharksize; s++){
                    ss= map[i][j].front().s;
                    dd = map[i][j].front().d;
                    zz = map[i][j].front().z;
                    if(zz<maxtmp){
                        map[i][j].pop();
                    }else{
                        maxtmp = zz;
                        if(!copymap[i][j].empty()){
                            copymap[i][j].pop();
                        }
                        copymap[i][j].push({ss,dd,zz});
                        map[i][j].pop();
                    }
                }
            }

        }
    }
}

void copyShark(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(!copymap[i][j].empty()){
                map[i][j].push({copymap[i][j].front().s,copymap[i][j].front().d, copymap[i][j].front().z});
                copymap[i][j].pop();
            }
        }
    }
}

void printMap(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<map[i][j].front().z<<" ";
        }
        cout<<"\n";
    }
}

void printSize(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<map[i][j].size()<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>R>>C>>M;
    for(int i=0; i<M; i++){
        cin>>sharkr>>sharkc>>sharks>>sharkd>>sharkz;
        map[sharkr][sharkc].push({sharks, sharkd, sharkz});
    }

    for(int i=1; i<=C; i++){
        eatShark(i);
        //cout<<i<<"eat>>>\n";
        //printMap();
        //cout<<"x,y,speed,ori,size\n";
        moveShark();
        //cout<<i<<"move>>>>\n";
        //printSize();
        deleteShark();
        copyShark();
        //cout<<i<<"finish<<<<\n";
        //printMap();
    }

    cout<<ans;
}