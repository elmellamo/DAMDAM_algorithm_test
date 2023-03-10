#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int N;
char map[26][26];
int visited[26][26];

int xx, yy;
int ans;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0,-1,1,0};

int isArea(int x, int y){
    if(x>-1 && x<N && y>-1 && y<N) return 1;
    else    
        return 0;
}

void dfs(int x, int y){
    visited[x][y] =1;
    ans++;

    for(int i=0; i<4; i++){
        xx = x + dx[i];
        yy = y+ dy[i];

        if(isArea(xx, yy) && map[xx][yy]=='1' && !visited[xx][yy]){
            dfs(xx, yy);
        }
    }

}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0;j<N;j++){
            if(map[i][j]=='1' && !visited[i][j]){
                dfs(i, j);
                v.push_back(ans);
                ans=0;
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size()<<"\n";
    for(int a:v){
        cout << a <<"\n";
    }

}