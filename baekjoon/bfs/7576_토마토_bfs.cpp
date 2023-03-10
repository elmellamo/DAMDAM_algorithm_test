#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct{
    int x;     int y;    int day;
}tomato;

vector<int> dx = {-1,0,0,1};
vector<int> dy = {0,1,-1,0};
vector<vector<int>> map;
vector<vector<int>> visited;

queue<tomato> q;
int m, n; 
int x,y,day,xx,yy;
int rst;

int isArea(int a, int b){
    if(a<n&&a>=0&&b<m&&b>=0) return 1;
    else
        return 0;
}

void print_tomato(){
    for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                cout << map[i][j]<<" ";
        }
        cout <<endl;
    }
}

void bfs(){
    while(!q.empty()){
        x = q.front().x; //��
        y = q.front().y; //��
        day = q.front().day; //day
        
        q.pop();

        visited[x][y] =1;
        rst = day;


        for(int i=0;i<4;i++){
            xx = x+dx[i];
            yy = y+dy[i];

        if(isArea(xx,yy)){ 
                if(!visited[xx][yy] && map[xx][yy]==0){
                    map[xx][yy] = 1;
                    visited[xx][yy] = 1;
                    q.push({xx, yy, day+1});
                }
        }
        }
    }
}





int main(){
    cin>>m>>n;
    
    map.resize(n,vector<int>(m, -1));
    visited.resize(n,vector<int>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >>map[i][j];
            if (map[i][j]==1)
                q.push({i, j, 0});
        }
    }

    bfs();

    int key=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0){
                cout<<-1<<endl;
                return 0;
            }
        }
    }

    cout<<rst<<endl;
    
    return 0;
    



}


/*
1. n�� m���� (x, y)�� �򰥸�
2. resize�� n�� m���� �ʱ�ȭ�ϰ� �ߴµ� ���� ���� �ʰ����� ����? isArea() ���� ���ֱ�
*/