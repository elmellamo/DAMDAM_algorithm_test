#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int L, C;
char sortArr[17];
char selectArr[17]; //select collection
vector<char> tmpArr;

void BT(int pos, int depth){
    if(depth==L){
        int cnt;
        cnt=0;
        for(int d=0; d<L ; d++){
            if(selectArr[d]=='a'||selectArr[d]=='e'||selectArr[d]=='i'||selectArr[d]=='o'||selectArr[d]=='u'){
                cnt++;
            }
        }

        if(cnt>0 && cnt<L-1){
            for(int d=0; d<L ; d++){
                cout<<selectArr[d];
            }
            cout<<"\n";
        }

        return;    
    }
    for(int next= pos+1; next<C; next++){
        selectArr[depth] = sortArr[next]; //selectArr >> index 0 ~ M-1
        BT(next, depth+1); 
    }
}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char tmp; 
    cin>>L>>C;

    for(int c=0; c<C; c++){
        cin>>tmp;
        tmpArr.push_back(tmp);
    }
    
    sort(tmpArr.begin(), tmpArr.end());

    for(int c=0; c<C; c++){
        sortArr[c] = tmpArr[c];
    }

    BT(-1,0);
}