#include <iostream>
#include <memory.h>
using namespace std;

int num;
int numberArr[17];
int ans[7];

void BT(int pos, int depth){
    if(depth==6){
        for(int d=0; d<depth; d++){
            cout<<ans[d]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int next= pos+1; next<=num; next++){
        ans[depth] = numberArr[next];
        BT(next, depth+1);
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>num;
    while(num!=0){
        memset(ans, 0, sizeof(ans));
        memset(numberArr, 0, sizeof(ans));

        for(int n=1; n<=num; n++){
            cin>>numberArr[n];
        }

        BT(0, 0);
        cin>>num;
        if(num!=0){
        cout<<"\n";
        }
    }
}