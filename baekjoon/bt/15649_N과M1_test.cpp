#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include <string.h>
#include <algorithm>
using namespace std;
const int SIZE = 20;
int answer[SIZE];
int visited[SIZE];
int n, r;

void BT(int depth) {
   if (depth == r) {
      for (int i = 0; i < depth; i++)
         cout << answer[i] << " ";
      cout << "\n";
      return;
   }
   for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
         visited[i] = 1;
         answer[depth] = i;
         BT(depth + 1);
         visited[i] = 0;
      }
   }
}

int main(void)
{
   cin.tie(NULL);
   cin.sync_with_stdio(false);
   
   cin >> n >> r;
   BT(0);

   return 0;
}