#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int N;
int cnt, tmpx, tmpy, cntsize;
char map[27][27];
int visited[27][27];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<int> cntArray;

int isArea(int x, int y) {
	if (0 < x && x <= N && 0 < y && y <= N) {
		return 1;
	}
	else {
		return 0;
	}
}

void dfs(int x, int y) {
	int xx, yy;
	visited[x][y] = 1;
	cnt++;

	for (int d = 0; d < 4; d++) {
		xx = x + dx[d];
		yy = y + dy[d];

		if (isArea(xx, yy) && map[xx][yy]=='1' && !visited[xx][yy]) {
			dfs(xx, yy);
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
			if (map[i][j] == '1' && !visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				cntArray.push_back(cnt);
			}
		}
	}

	sort(cntArray.begin(), cntArray.end());
	cntsize = cntArray.size();
	cout << cntsize<< "\n";

	for (int s = 0; s < cntsize; s++) {
		cout << cntArray[s] << "\n";
	}

	
}