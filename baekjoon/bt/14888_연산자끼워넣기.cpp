#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
int N;
int map[17]; // 수 저장 맵
int btmap[17]; // 백트래킹 돌릴 것
int visited[17]; // 연산자 방문 체크
int how[17]; // 연산자 넣을 공간
int finish[17]; // 순열 넣을 연산자 넣을 공간
int plusnum, minusnum, multinum, dividenum;

int howtoCal(int a, int b, int how){
    if(how==1)  return a+b;
    else if(how==2) return a-b;
    else if(how==3) return a*b;
    else return a/b;
}

void testAns(){
    int tmp;
    tmp = howtoCal(map[0], map[1], finish[0]);
    for(int i=1; i<N-1; i++){
        tmp = howtoCal(tmp, map[i+1], finish[i]);
    }

    ans.push_back(tmp);    
}

void BT(int depth){
    if(depth==N-1){
        for(int t=0; t<N-1;t++){
            finish[t] = how[btmap[t]];
        }
        testAns();
        return;
    }
    
    for(int i=0; i<N-1; i++){
        if(!visited[i]){
        visited[i] = 1;
        btmap[depth] = i;
        BT(depth+1);
        visited[i]=0;
        }
    }
    
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int i=0; i<N;i++){
        cin>>map[i];
    }
    cin>>plusnum>>minusnum>>multinum>>dividenum;

    int i=0; 
    for(int t=0; t<plusnum; t++){
        how[i] = 1;
        i++;
    }
    for(int t=0; t<minusnum; t++){
        how[i] = 2;
        i++;
    }
    for(int t=0; t<multinum; t++){
        how[i] = 3;
        i++;
    }
    for(int t=0; t<dividenum; t++){
        how[i] = 4;
        i++;
    }
    BT(0);

    sort(ans.begin(), ans.end());
    cout<<ans[ans.size()-1]<<"\n"<<ans[0];



}