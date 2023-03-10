#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <math.h>
using namespace std;

typedef struct {
    int x, y;
}info;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<info> chicken;
vector<int> minD;
vector<int> selectmin;
int N, M, chickenans, cnt, cityCnt;
int map[57][57];
int copymap[57][57];
int selectchicken[17];
int ans[17];
int visited[57][57];

int isArea(int a, int b) {
    return -1 < a && a < N && -1 < b && b < N;
}

void initCopyMap() {
    int x, y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                copymap[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        x = chicken[ans[i]].x;
        y = chicken[ans[i]].y;

        copymap[x][y] = 2;
    }
}

int dmin(int r, int c) {
    int tmp;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(copymap[i][j]==2){
                tmp = abs(i-r)+abs(j-c);
                selectmin.push_back(tmp);
            }
        }
    }
    sort(selectmin.begin(), selectmin.end());
    return selectmin[0];
}

void printcopyMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<copymap[i][j];
        }
        cout<<"\n";
    }
}

void chickenBT(int pos, int depth) {
    if (depth == M) {
        initCopyMap();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (copymap[i][j] == 1) {
                    cnt = dmin(i, j);
                    cityCnt += cnt;
                    //cout<<"copymap "<<i<<" "<<j<<" cnt>>"<<cnt<<"\n";
                    while(!selectmin.empty()){
                        selectmin.pop_back();
                    }
                }
            }
        }

        minD.push_back(cityCnt);
        cityCnt = 0;
        memset(copymap, 0, sizeof(copymap));
        return;
    }

    for (int next = pos + 1; next < chickenans; next++) {
        if (!selectchicken[next]) {
            ans[depth] = next;
            selectchicken[next] = 1;
            chickenBT(next, depth + 1);
            selectchicken[next] = 0;
        }
    }
}




int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                chicken.push_back({ i,j });
                chickenans++;
            }
        }
    }

    chickenBT(-1, 0);
    sort(minD.begin(), minD.end());

    cout << minD[0];


}