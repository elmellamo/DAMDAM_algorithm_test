#include <iostream>
using namespace std;

int N, M;
int ans[10];

void BT(int pos, int depth){
    if(depth==M){
        for(int d=0; d<depth; d++){
            cout<<ans[d]<<" ";
        }
        cout<<"\n";
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