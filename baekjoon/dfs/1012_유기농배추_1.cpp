#include <iostream>
#include <memory.h>
using namespace std;

int T, N, M, K;
int ans, tmpx, tmpy;
int map[57][57];
int visited[57][57];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int isArea(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < M) {
		return 1;
	}
	else {
		return 0;
	}
}

void dfs(int x, int y) {
	int xx, yy;
	visited[x][y] = 1;

	for (int d = 0; d < 4; d++) {
		xx = x + dx[d];
		yy = y + dy[d];

		if (isArea(xx, yy) && map[xx][yy] && !visited[xx][yy]) {
			dfs(xx, yy);
		}
	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++) {
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));


		cin >> M >> N >> K;

		for (int k = 0; k < K; k++) {
			cin >> tmpy >> tmpx;
			map[tmpx][tmpy] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !visited[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << "\n";
	}

}