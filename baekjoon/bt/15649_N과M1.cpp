#include <iostream>
using namespace std;

int N, M;
int visited[10];
int ans[10];

void BT(int depth){
    if(depth==M){
        for(int i=0; i<depth; i++){
            cout<<ans[i]<<" ";  
        }
        cout<<"\n";
    }

    for(int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i] = 1;
            ans[depth] = i;
            BT(depth+1);
            visited[i] = 0;
        }
    }
}

int main(){
    cin>>N>>M;
    BT(0);
}