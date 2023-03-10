#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
vector<int> v;
int check[101];
int map[101];
int i;

void bt(int start, int summ, int howmany){
    
    if(summ>M) return;
    else if(summ<M && howmany ==3){
        v.push_back(summ);
        return ;
    }
    for(int i=start+1; i<N; i++){
        if(!check[i]){
            check[i] =1;
            bt(i, summ+map[i], howmany+1);
            check[i] = 0;
        }
    }


}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    for(int t=0; t<N; t++){
        cin >> map[t];
    }
    
    for(int t=0; t<N; t++){
        bt(t, 0, 0);
    }
    sort(v.begin(), v.end());
    cout << v.back();


}