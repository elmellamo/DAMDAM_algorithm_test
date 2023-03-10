#include <iostream>
#include <math.h>
using namespace std;

int N, N2;
int visited[17];
int rvisited[37];
int lvisited[37];

int map[17][17];
int ans;
int dx[4]= {-1,1,1,-1};
int dy[4]= {1,1,-1,-1};

int isArea(int x, int y){
    if(x>-1 && x<N && y>-1 && y<N) return 1;
    else
        return 0;
}


void BT(int depth){
    int x, y, xx, yy;

    if(depth==N){
        ans++;
        return;
    }

    //visited가 열, depth가 행, rvisited, lvisited는 각각 오른쪽, 왼쪽 대각선 
    for(int i=0; i<N; i++){
        if(!visited[i] && !rvisited[N-1-depth+i] && !lvisited[depth+i]){
            visited[i]=1;
            rvisited[N-1-depth+i]=1;
            lvisited[depth+i]=1;
            

            BT(depth+1);

            visited[i]=0;
            rvisited[N-1-depth+i]=0;
            lvisited[depth+i]=0;
        }
    }
}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    BT(0);
    cout<<ans;
}