#include <iostream>
using namespace std;

int N, M;
int visited[10];
int answer[10];

void BT(int depth){
    if(depth==M){
        for(int i=0;i<depth;i++){
            cout<<answer[i]<<" ";
        }
        cout<<"\n";
        return;
    }



    for(int i=1;i<N+1;i++){
        if(!visited[i]){
            answer[depth]=i;
            visited[i]=1;
            BT(depth+1);
            visited[i]=0;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    BT(0);

}