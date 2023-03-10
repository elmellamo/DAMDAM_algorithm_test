#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
//#include <queue>
using namespace std;

int Q, F, N, M;
int first, sec;
vector<int> squareN[100007];
vector<int>copyN[100007];
//queue<int>ans;

void init() {
	int whatnum;
	for (int m = 1; m <= M; m++) {
        scanf("%d", &whatnum);
		squareN[whatnum].push_back(m);
	}
}

int moveBlock(int mSrc, int mDst) {
	int ssize, dsize, copysize;
	ssize = squareN[mSrc].size();
	dsize = squareN[mDst].size();
	for (int i = 0; i < dsize; i++) {
		copyN[mDst].push_back(squareN[mDst].back());
		squareN[mDst].pop_back();
	}
	for (int i = 0; i < ssize; i++) {
		copyN[mDst].push_back(squareN[mSrc].back());
		squareN[mSrc].pop_back();
	}
	copysize = copyN[mDst].size();
	for (int i = 0; i < copysize; i++) {
		squareN[mDst].push_back(copyN[mDst].back());
		copyN[mDst].pop_back();
	}

	return squareN[mDst].size();
}

int swpBlock(int mSrc, int mDst) {
	int ssize, dsize;

	ssize = squareN[mSrc].size();
	dsize = squareN[mDst].size();
	if (ssize > 0 && dsize > 0) {
		for (int i = 0; i < ssize; i++) {
			copyN[mSrc].push_back(squareN[mSrc].back());
			squareN[mSrc].pop_back();
		}
		for (int i = 0; i < dsize; i++) {
			copyN[mDst].push_back(squareN[mDst].back());
			squareN[mDst].pop_back();
		}

		squareN[mSrc].push_back(copyN[mDst].back());
		squareN[mDst].push_back(copyN[mSrc].back());
		copyN[mDst].pop_back();
		copyN[mSrc].pop_back();

		for (int i = 0; i < dsize - 1; i++) {
			squareN[mDst].push_back(copyN[mDst].back());
			copyN[mDst].pop_back();
		}
		for (int i = 0; i < ssize - 1; i++) {
			squareN[mSrc].push_back(copyN[mSrc].back());
			copyN[mSrc].pop_back();
		}
	}else if (ssize == 0 && dsize > 0) {

		for (int i = 0; i < dsize; i++) {
			copyN[mDst].push_back(squareN[mDst].back());
			squareN[mDst].pop_back();
		}

		squareN[mSrc].push_back(copyN[mDst].back());
		copyN[mDst].pop_back();

		for (int i = 0; i < dsize - 1; i++) {
			squareN[mDst].push_back(copyN[mDst].back());
			copyN[mDst].pop_back();
		}
	}else if (ssize > 0 && dsize == 0) {
		for (int i = 0; i < ssize; i++) {
			copyN[mSrc].push_back(squareN[mSrc].back());
			squareN[mSrc].pop_back();
		}
		squareN[mDst].push_back(copyN[mSrc].back());
		copyN[mSrc].pop_back();

		for (int i = 0; i < ssize - 1; i++) {
			squareN[mSrc].push_back(copyN[mSrc].back());
			copyN[mSrc].pop_back();
		}
	}

	return squareN[mDst].size();
}

int divideBlock(int mSrc, int mDst) {
	int k;
	int ssize, dsize, copysize;
	ssize = squareN[mSrc].size();
	dsize = squareN[mDst].size();
	k = ssize / 2;
	if (k > 0) {

		for (int i = 0; i < dsize; i++) {
			copyN[mDst].push_back(squareN[mDst].back());
			squareN[mDst].pop_back();
		}
		for (int i = 0; i < ssize - k; i++) {
			copyN[mSrc].push_back(squareN[mSrc].back());
			squareN[mSrc].pop_back();
		}
		for (int i = 0; i < k; i++) {
			copyN[mDst].push_back(squareN[mSrc].back());
			squareN[mSrc].pop_back();
		}

		ssize = copyN[mSrc].size();
		dsize = copyN[mDst].size();
		for (int i = 0; i < ssize; i++) {
			squareN[mSrc].push_back(copyN[mSrc].back());
			copyN[mSrc].pop_back();
		}
		for (int i = 0; i < dsize; i++) {
			squareN[mDst].push_back(copyN[mDst].back());
			copyN[mDst].pop_back();
		}
	}

	return squareN[mDst].size();
}

int getInfo(int pnum) {
	int ssize, tmp, copysize, changesize;
	int A, B;
	int key = 0;

	for (int i = 1; i <= M; i++) {
		ssize = squareN[i].size();
		for (int s = 0; s < ssize; s++) {
			tmp = squareN[i].back();
			squareN[i].pop_back();
			if (tmp == pnum) {
				key = 1;
				copysize = copyN[i].size();
				if (copysize > 0) {
					B = copyN[i].back();
				}
				else {
					B = -1;
				}
				changesize = squareN[i].size();
				if (changesize > 0) {
					A = squareN[i].back();
				}
				else {
					A = -1;
				}
			}
			copyN[i].push_back(tmp);
		}

		for (int s = 0; s < ssize; s++) {
			squareN[i].push_back(copyN[i].back());
			copyN[i].pop_back();
		}

		if (key == 1) {
			break;
		}
	}

	return A + 2 * B;
}

int getBelt(int bnum) {
	int ssize, a, b;
	ssize = squareN[bnum].size();
	if (ssize > 0) {
		a = squareN[bnum].front();
		b = squareN[bnum].back();
	}
	else {
		a = -1;
		b = -1;
	}

	return a + 2 * b + 3 * ssize;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

    scanf("%d", &Q);
	for (int q = 0; q < Q; q++) {
        scanf("%d", &F);
		if (F == 100) {
            scanf("%d %d", &N, &M);
			init();
		}
		else if (F == 200) {
            scanf("%d %d", &first, &sec);
			printf("%d\n", moveBlock(first, sec));
		}
		else if (F == 300) {
            scanf("%d %d", &first, &sec);
            printf("%d\n", swpBlock(first, sec));
		}
		else if (F == 400) {
            scanf("%d %d", &first, &sec);
            printf("%d\n", divideBlock(first, sec));
		}
		else if (F == 500) {
            scanf("%d", &first);
            printf("%d\n", getInfo(first));
		}
		else {
			scanf("%d", &first);
            printf("%d\n", getBelt(first));
		}
	}

}