#include <iostream>
using namespace std;

int N, M;
int visited[9];
int ans[9];

void BT(int pos, int depth){
    if(depth==M){
        for(int i=0; i<depth; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int next=pos+1; next<=N; next++){
         ans[depth] = next;
         BT(next, depth+1);

    }


}
int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    BT(0, 0);
}