#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, N2;
int score1, score2, tmpscore;
vector<int> minscore;
int map[27][27];
int ans1[17], ans2[17];
int visited[27];
int allans1[17], allans2[17];

void testVist(){
    int i=0;
    for(int n=1; n<=N; n++){
        if(!visited[n]){
            ans2[i] = n;
            i++;
        }
    }
}

void allP1(int pos, int depth){
    if(depth==2){
        score1 += map[allans1[0]][allans1[1]] + map[allans1[1]][allans1[0]];
        return;
    }

    for(int next=pos+1; next<=N2; next++){
        allans1[depth]= ans1[next];
        allP1(next, depth+1);
    }
}

void allP2(int pos, int depth){
    if(depth==2){
        score2 += map[allans2[0]][allans2[1]] + map[allans2[1]][allans2[0]];
        return;
    }

    for(int next=pos+1; next<=N2; next++){
        allans2[depth]= ans2[next];
        allP2(next, depth+1);
    }
}

int calScore(){
    score1=0; score2=0;
    allP1(-1,0); allP2(-1,0);
    if(score1>score2) return score1 - score2;
    else return score2 - score1;
}

void makeTeam(int pos, int depth){
    if(depth==N2){
        testVist();
        tmpscore = calScore();
        minscore.push_back(tmpscore);
        return;
    }

    for(int next = pos+1; next<= N; next++){
        if(!visited[next]){
            ans1[depth] = next;
            visited[next] = 1;
            makeTeam(next, depth+1);
            visited[next] = 0;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    N2 = N/2;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
        }
    }

    makeTeam(0, 0);
    sort(minscore.begin(), minscore.end());
    cout<<minscore.front();
}