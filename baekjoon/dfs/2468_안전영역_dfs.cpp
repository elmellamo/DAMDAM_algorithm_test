#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;
int tmp, mm, m; //mm은 입력되는 최고 높이 m은 최저 높이
int xx, yy;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int map[101][101];
int visited[101][101];
int plusrain; // plusrain은 맵을 초기화할 때 쓰이는 변수
int tmpans;
vector<int> ans;

void setMap(int how){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(how == map[i][j]) map[i][j]=0;
        }
    }
}

void printMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j]<<' ';
        }
        cout<<"\n";
    }
}

int isArea(int a, int b){
    if(a>-1 && a<N && b>-1 && b<N) return 1;
    else 
        return 0;
}

void dfs(int x, int y){
    visited[x][y]=  1;
    for(int i=0 ; i<4; i++){
        xx = x+ dx[i];
        yy = y +dy[i];

        if(isArea(xx, yy)&& map[xx][yy]>0&& !visited[xx][yy]){
            dfs(xx, yy);
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    m=100;
    for(int i=0; i<N; i++){
        for(int j=0; j<N ; j++){
            cin >> tmp;
            map[i][j] = tmp;
            if(mm <tmp) mm = tmp;
            if(m>tmp) m = tmp;
        }
    }
    
    if(m == mm) cout<<"1";
    else{

    for(plusrain = m; plusrain<=mm; plusrain++){
        setMap(plusrain);
        //printMap();
        for(int i=0;i<N;i++){
            for(int j=0; j<N; j++){
                if(map[i][j]>0 && !visited[i][j]){
                dfs(i, j);
                tmpans++;
            }}
        }
        ans.push_back(tmpans);
        tmpans=0;
        memset(visited, 0 ,sizeof(visited));
    }

    sort(ans.begin(), ans.end());
    cout<<ans.back();
    
    }
}