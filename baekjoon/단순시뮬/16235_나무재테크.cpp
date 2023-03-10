#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int map[17][17];
queue<int> death[17][17];
queue<int> copytree[17][17];
queue<int> tree[17][17];
vector<int> tmptree;
int winter[17][17];
int N, M, K, ans;
int dx[10]={-1,-1,-1,0,1,1,1,0};
int dy[10]={-1,0,1,1,1,0,-1,-1};

int isArea(int a, int b){
    return 0<a&&a<=N&&0<b&&b<=N;
}

void spring(){
    int nutri, treesize, treeyear;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            treesize = tree[i][j].size();

            if(treesize>1){
                while(!tree[i][j].empty()){
                    tmptree.push_back(tree[i][j].front());
                    tree[i][j].pop();
                }
                sort(tmptree.begin(), tmptree.end());

                for(int t=0; t<treesize; t++){
                    tree[i][j].push(tmptree[t]);
                }

                while(!tmptree.empty()){
                    tmptree.pop_back();
                }
            }

            for(int t=0; t<treesize; t++){
                nutri = map[i][j];
                treeyear = tree[i][j].front();
                if(nutri<treeyear){
                    death[i][j].push(tree[i][j].front());
                    tree[i][j].pop();
                }else{
                    map[i][j]= map[i][j]-treeyear;
                    tree[i][j].pop();
                    tree[i][j].push(treeyear+1);
                }
            }
        }
    }
}

void summer(){
    int dnutri;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            while(!death[i][j].empty()){
                dnutri = death[i][j].front();
                dnutri = dnutri/2;
                map[i][j] = map[i][j] + dnutri;
                death[i][j].pop();
            }
        }
    }
}

void fall(){
    int treesize, treeyear;
    int x,y;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            treesize = tree[i][j].size();
            for(int t=0; t<treesize; t++){
                treeyear = tree[i][j].front();
                if(treeyear%5==0){
                    for(int k=0; k<8; k++){
                        x = i + dx[k];
                        y = j + dy[k];

                        if(isArea(x,y)){
                            copytree[x][y].push(1);
                        }
                    }
                }
                copytree[i][j].push(treeyear);
                tree[i][j].pop();
            }
        }
    }
}

void moveCopy(){
    int copytreesize;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            copytreesize = copytree[i][j].size();
            for(int t=0; t<copytreesize; t++){
                tree[i][j].push(copytree[i][j].front());
                copytree[i][j].pop();
            }
        }
    }
}

void winterN(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] = map[i][j] + winter[i][j];
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j]=5;
            cin>>winter[i][j];
        }
    }

    int a,b,year;
    for(int i=0; i<M; i++){
        cin>>a>>b>>year;
        tree[a][b].push(year);
    }

    for(int k=0; k<K;k++){
        spring();
        summer();
        fall();
        moveCopy();
        winterN();
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(!tree[i][j].empty()){
                ans += tree[i][j].size();
            }
        }
    }

    cout<<ans;



}