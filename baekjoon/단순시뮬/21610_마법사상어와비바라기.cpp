#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

typedef struct{
    int x,y;
}info;

vector<info> cloud;
vector<info> copycloud;
int N,M, dCloud,sCloud;
int dx[9]={0,0,-1,-1,-1,0,1,1,1};
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
int map[57][57];
int visited[57][57];

int isArea(int a, int b){
    return -1<a&&a<N&&-1<b&&b<N;
}

int checkRange(int a){
    if(a>N-1){
        a = a%N;
    }else if(a<0){
        a = (abs(a))%N;
        if(a!=0){
            a = N-a;
        }
    }

    return a;
}

void moveCloud(int d, int s){
    int cloudsize, x, y;
    cloudsize = cloud.size();

    for(int i=0; i<cloudsize; i++){
        x = cloud[i].x;
        y = cloud[i].y;

        for(int S=0; S<s; S++){
            x = x+dx[d];
            y = y+dy[d];
        }

        x = checkRange(x);
        y = checkRange(y);

        map[x][y] = map[x][y] + 1;
        visited[x][y] = 1;
        copycloud.push_back({x,y});
    }

    while(!cloud.empty()){
        cloud.pop_back();
    }

    for(int i=0; i<cloudsize; i++){
        cloud.push_back({copycloud[i].x, copycloud[i].y});
    }

    while(!copycloud.empty()){
        copycloud.pop_back();
    }
}

void checkCloud(){
    int cloudsize, x, y, xx, yy, key;

    cloudsize= cloud.size();
    for(int i=0; i<cloudsize; i++){
        x = cloud[i].x;
        y = cloud[i].y;
        key = 0;
        for(int t=1; t<5; t++){
            xx = x + dx[2*t];
            yy = y + dy[2*t];

            if(isArea(xx,yy)&&map[xx][yy]>0){
                key++;
            }
        }

        map[x][y] = map[x][y] + key;
    }

    while(!cloud.empty()){
        cloud.pop_back();
    }
}

void pushCloud(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && map[i][j]>1){
                cloud.push_back({i,j});
                map[i][j] = map[i][j]-2;
            }
        }
    }
}

void printMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }   

    cin>>dCloud>>sCloud;
    cloud.push_back({N-1,0});    cloud.push_back({N-1,1});    cloud.push_back({N-2,0});    cloud.push_back({N-2,1});
    moveCloud(dCloud,sCloud);
    //cout<<"1 move>> \n";
    //printMap();
    checkCloud();
    //cout<<"1 check>> \n";
    //printMap();
    pushCloud();
    //cout<<"1 push>> \n";
    //printMap();
    memset(visited, 0, sizeof(visited));


    if(M>1){
        for(int m=1; m<M; m++){
            cin>>dCloud>>sCloud;
            moveCloud(dCloud,sCloud);
            //cout<<m+1<<" move>> \n";
            //printMap();
            checkCloud();
            //cout<<m+1<<" check>> \n";
            //printMap();
            pushCloud();
            //cout<<m+1<<" push>> \n";
            //printMap();
            memset(visited, 0, sizeof(visited));
        }
    }

    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans+=map[i][j];
        }
    }

    cout<<ans;
}