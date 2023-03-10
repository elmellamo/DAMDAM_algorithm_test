#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int map[27];
int visited[27];
int ans[27];
int rst;
int tmp;

void BT(int pos, int depth, int exact){
    if(depth==exact){
        for(int i=0; i<depth; i++){
            tmp+=ans[i];
        }
        if(tmp==S) rst++;
        tmp=0;
        return;
    }
    for(int next=pos+1; next<N; next++){
        if(!visited[next]){
            visited[next] = 1;
            ans[depth] = map[next];
            BT(next, depth+1, exact);
            visited[next] = 0;
        }
    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>> N>>S;
    for(int i=0; i<N; i++){
        cin>>map[i];
    }

    sort(map, map+N);

    for(int i=1; i<=N;i++){
        BT(-1, 0, i);
    }
    cout<<rst;
}