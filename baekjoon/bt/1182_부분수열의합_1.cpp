#include <iostream>
using namespace std;

int N, S, cnt;
int numberArr[27];
int ans[27];

int addM(int m){
    int tmp;
    tmp = ans[0];
    for(int t=1; t<m; t++){
        tmp += ans[t];
    }

    if(S==tmp) return 1;
    else  
        return 0;
}

void BT(int pos, int depth, int M){
    if(depth==M){
        if(addM(M)){
            cnt++;
        }
        return;
    }

    for(int next= pos+1; next<=N; next++){
        ans[depth] = numberArr[next];
        BT(next,depth+1,M);
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>S;
    for(int n=1; n<=N; n++){
        cin>>numberArr[n];
    }

    for(int m=1; m<=N; m++){
        BT(0, 0, m);
    }

    cout<<cnt;
}