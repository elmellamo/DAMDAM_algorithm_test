#include <iostream>
using namespace std;
int k=-1;
int map[17];
int ans[17];
int visited[17];

void BT(int pos, int depth){
    if(depth==6){
        for(int i=0; i<depth; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }

    for(int next= pos+1; next<=k; next++){
        if(!visited[next]){
            visited[next] = 1;
            ans[depth] = map[next];
            BT(next, depth+1);
            visited[next] = 0;
        }
    }

}
int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    while(k!=0){
        cin>>k;
        for(int i=1; i<=k;i++){
            cin>>map[i];
        }

        BT(0, 0);
        cout<<"\n";

    }
}