#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int N;
int cnt, cntRG, tmpx, tmpy;
char map[107][107];
int visited[107][107];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };


int isArea(int x, int y) {
	if (0 < x && x <= N && 0 < y && y <= N) {
		return 1;
	}
	else {
		return 0;
	}
}

void dfs(int x, int y, char color){
	int xx, yy;
	visited[x][y] = 1;

	for (int d = 0; d < 4; d++) {
		xx = x + dx[d];
		yy = y + dy[d];

		if (isArea(xx, yy) && map[xx][yy]== color && !visited[xx][yy]) {
			dfs(xx, yy, color);
		}
	}

}


void dfsRG(int x, int y, char color) {
	int xx, yy;
	visited[x][y] = 1;

	for (int d = 0; d < 4; d++) {
		xx = x + dx[d];
		yy = y + dy[d];

		if (isArea(xx, yy) && !visited[xx][yy]) {
			if (color == 'B'&&map[xx][yy]=='B') {
				dfsRG(xx, yy, color);
			}
			else if(color != 'B' && map[xx][yy] !='B'){
				dfsRG(xx, yy, color);
			}
			
		}
	}

}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				dfs(i, j, map[i][j]); 
				cnt++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				dfsRG(i, j, map[i][j]);
				cntRG++;
			}
		}
	}

	cout << cnt << " " << cntRG;

	
}