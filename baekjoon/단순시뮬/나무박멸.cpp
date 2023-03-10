#include <iostream>
#include <vector>
using namespace std;
typedef struct{
    int x,y,cnt;
}info;

int ans=0;
int N, M, K, C;
int map[27][27];
int visited[27][27];
vector<info> grow;
vector<info> love;
int dx[4]={-1,1,0,0};
int dy[4] = {0,0,-1,1};
int ddx[4]={-1,-1,1,1};
int ddy[4]={-1,1,1,-1};

void vanishD(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]>0){
                visited[i][j] = visited[i][j]-1;
            }
        }
    }
}
int isArea(int a, int b){
    return -1<a&&a<N&&-1<b&&b<N;
}
void growTree(){
    int x,y, cnt;
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            if(map[i][j]>0){
                cnt = 0;
                for(int t=0; t<4;t++){
                    x = i + dx[t];
                    y = j + dy[t];

                    if(isArea(x,y)&&map[x][y]>0){
                        cnt++;
                    }
                }
                if(cnt>0){
                    grow.push_back({i,j,cnt});
                }
            }
        }
    }

    int growsize;
    growsize = grow.size();
    for(int g=0; g<growsize; g++){
        x = grow[g].x;
        y = grow[g].y;
        cnt = grow[g].cnt;

        map[x][y] = map[x][y]+cnt;
    }

    while(!grow.empty()){
        grow.pop_back();
    }
}
void loveTree(){
    int x,y, cnt, child;
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            if(map[i][j]>0){
                cnt = 0;
                child = 0;
                for(int t=0; t<4;t++){
                    x = i + dx[t];
                    y = j + dy[t];

                    if(isArea(x,y)&&map[x][y]==0 &&visited[x][y]==0){
                        cnt++;
                    }
                }

                if(cnt>0){
                    child = map[i][j]/cnt;
                    for(int t=0; t<4;t++){
                        x = i + dx[t];
                        y = j + dy[t];

                        if(isArea(x,y)&&map[x][y]==0 &&visited[x][y]==0){
                            love.push_back({x,y,child});
                        }
                    }
                }
                
            }
        }
    }

    int lovesize;
    lovesize = love.size();
    for(int l=0; l<lovesize; l++){
        x = love[l].x;
        y = love[l].y;
        cnt = love[l].cnt;
        map[x][y]= map[x][y]+cnt;
    }

    while(!love.empty()){
        love.pop_back();
    }
}
void testDelete(){
    int x, y, cnt, key, cntMax;
    int cntx,cnty;

    cntMax = 0;    cntx=0;    cnty=0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j]>-1){
                cnt = map[i][j];
                for(int t=0; t<4;t++){
                    x = i;
                    y = j;
                    for(int k=0; k<K;k++){
                        x = x+ddx[t];
                        y = y+ddy[t];
                        if(isArea(x,y)&&map[x][y]>0){
                            cnt += map[x][y];
                        }else{
                            break;
                        }
                    }
                }
                
                if(cntMax<cnt){
                    cntx = i;
                    cnty = j;
                    cntMax = cnt;
                }
            }
        }
    }

    vanishD();
    
    if(cntMax!=0){
        //cout<<cntx<<" "<<cnty<<"select\n";
        ans = ans+ map[cntx][cnty];
        map[cntx][cnty] = 0;
        visited[cntx][cnty] = C;

        for(int t=0; t<4; t++){
            x = cntx;
            y = cnty;
            for(int k=0; k<K; k++){
                x = x+ddx[t];
                y = y+ddy[t];

                if(isArea(x,y)){
                    if(map[x][y]>0){
                        ans = ans+ map[x][y];
                        map[x][y]=0;
                        visited[x][y] = C;
                    }
                    else if(map[x][y]==0){
                        visited[x][y]=C;
                        break;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }
        }
    }

    
}
void printMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void printvisit(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>K>>C;
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            cin>>map[i][j];
        }
    }

    for(int m=0; m<M; m++){
        growTree();
        //cout<<"grow "<<m+1<<"\n";
        //printMap();
        loveTree();
        //cout<<"love "<<m+1<<"\n";
        //printMap();
        testDelete();
        //cout<<"delete "<<m+1<<"\n";
        //printMap();
        //cout<<"delete visited "<<m+1<<"\n";
        //printvisit();
    }

    cout<<ans;

}