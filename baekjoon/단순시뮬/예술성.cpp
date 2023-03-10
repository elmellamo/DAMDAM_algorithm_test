#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

typedef struct{
    int num, cnt;
}info;

int R,C, LL;
int N, groupcnt, ans, howmany, rst;
int first, sec, shareD, firstcnt, seccnt, firstnum, secnum;
int map[37][37];
int groupmap[37][37];
int visited[37][37];
int copymap[37][37];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int btvisited[900];
int btans[4];

vector<info> artGroup;

int isArea(int a, int b){
    return -1<a&&a<N&&-1<b&&b<N;
}

void rotateRC(){
    for(int i=0; i<LL; i++){
        for(int j=0; j<LL; j++){
            copymap[R+j][C+LL-1-i]=map[R+i][C+j];
        }
    }
}

void churchMap(){
    for(int i=0; i<LL; i++){
        copymap[LL][i] = map[i][LL];
        copymap[N-1-i][LL]=map[LL][i];
        copymap[LL][LL+1+i]=map[LL+1+i][LL];
        copymap[LL-1-i][LL]=map[LL][LL+1+i];
    }
}

void rotateMap(){

    copymap[LL][LL] = map[LL][LL];

    for(R=0;R<N;R+=(LL+1)){
        for(C=0; C<N; C+=(LL+1)){
            rotateRC();
        }
    }

    churchMap();

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            map[i][j] = copymap[i][j];
        }
    }
}

void makingGroup(int r, int c, int what){
    int x,y;

    visited[r][c]=1;
    groupmap[r][c]=howmany;
    groupcnt++;
    
    for(int i=0; i<4;i++){
        x = r +dx[i];
        y = c +dy[i];

        if(isArea(x,y)&&!visited[x][y]&&map[x][y]==what){
            makingGroup(x,y,what);
        }
    }

}

void shareGroup(int oneg, int secg){
    int x,y;
    
    rst = 0;

    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            if(groupmap[i][j]==oneg){
                for(int t=0; t<4; t++){
                    x = i + dx[t];
                    y = j + dy[t];

                    if(isArea(x,y) && groupmap[x][y]==secg){
                        rst++;
                    }
                }
            }
        }
    }
}

void BT(int pos, int depth){
    if(depth==2){
        first = btans[0];
        sec = btans[1];

        firstcnt = artGroup[first].cnt;
        seccnt = artGroup[sec].cnt;
        firstnum = artGroup[first].num;
        secnum = artGroup[sec].num;
        shareGroup(first+1, sec+1);

        ans += (firstcnt + seccnt)*firstnum*secnum*rst;
        //cout<<ans<<" ::::"<<first<<" "<<sec<<"!!!     "<<firstcnt<<" "<<seccnt<<" "<<firstnum<<" "<<secnum<<" "<<rst<<"\n";
    
        return;
    }

    for(int next=pos+1; next<howmany; next++){
        if(!btvisited[next]){
            btvisited[next]=1;
            btans[depth]=next;
            BT(next, depth+1);
            btvisited[next]=0;
        }
    }
}

void printMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void printGroup(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<groupmap[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    LL = N/2;
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }

    for(int T=0; T<4; T++){

        for(int i=0;i<N;i++){
            for(int j=0; j<N; j++){
                groupcnt=0;
                if(!visited[i][j]){
                    howmany++;
                    makingGroup(i,j,map[i][j]);
                    artGroup.push_back({map[i][j], groupcnt});
                }
            }
        }

        BT(-1,0);
        rotateMap();

        memset(visited, 0, sizeof(visited));
        memset(btvisited, 0, sizeof(btvisited));
        memset(copymap, 0, sizeof(copymap));
        memset(groupmap, 0, sizeof(groupmap));
        while(!artGroup.empty()){
            artGroup.pop_back();
        }
        howmany = 0;
    }




    cout<<ans;


}