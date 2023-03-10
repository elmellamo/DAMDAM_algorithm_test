#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int rst;
int L,C;
char ans[17];
char map[17];

void BT(int pos, int depth){
    int tmp=0;

    if(depth==L){
        for(int i=0; i<L; i++){
            if(ans[i]=='a'||ans[i]=='e'||ans[i]=='i'||ans[i]=='o'||ans[i]=='u'){
                tmp++;
            }
        }

        if(tmp>0 && L-tmp>1) {
            for(int i=0; i<L; i++){
                cout<<ans[i];
            }
            cout<<"\n";
        }

        return;
    }

    for(int next=pos+1; next<C; next++){
         ans[depth] = map[next];
         BT(next, depth+1);

    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>L>>C;

    for(int i=0; i<C; i++){
        cin>> map[i];
    }

    sort(map, map+C);

    BT(-1,0);

    
}