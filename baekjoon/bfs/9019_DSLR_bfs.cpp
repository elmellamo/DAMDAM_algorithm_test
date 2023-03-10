#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef struct{
    string ans;
    int num;
}info;

queue<info> q;
int visited[10007];
int T, A, B;
string what;
int num, tmp;

int changeD(int a){
    int rst;
    rst = a*2;
    if(rst>9999) 
        rst%=10000;

    return rst; 
}

int changeS(int a){
    int rst;
    rst = a-1;
    if(rst==-1) rst = 9999;

    return rst;
}

int changeL(int a){
    int tmp;
    tmp = (a%1000)*10 + (a/1000);
    return tmp;
}

int changeR(int a){
    int tmp;
    tmp = a%10;
    int rst;
    rst = (tmp*1000) + a/10;
    return rst;
}


void bfs(){
    while(!q.empty()){
        what = q.front().ans;
        num = q.front().num;
        
        //cout<<what<<" "<<num<<'\n';
        q.pop();

        if(num == B){
            cout<<what<<"\n";
            break;
        }
                                                                     
        tmp = changeD(num);
        if(!visited[tmp]){
        q.push({what+"D", tmp});
        visited[tmp]=1;}

        tmp = changeS(num);
        if(!visited[tmp]){
        q.push({what+"S", tmp});
        visited[tmp] = 1;}

        tmp = changeL(num);
        if(!visited[tmp]){
        q.push({what+"L", tmp});
        visited[tmp]=1;}

        tmp = changeR(num);
        if(!visited[tmp]){
        q.push({what+"R", tmp});
        visited[tmp]=1;}
    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T;
    for(int t=0; t<T; t++){
        
        cin>>A>>B;
        q.push({"",A});

        bfs();
        
        while(!q.empty()){
            q.pop();
        }
        memset(visited, 0, sizeof(visited));

    }

}