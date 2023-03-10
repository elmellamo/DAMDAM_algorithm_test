#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct{
    int x,y;
}info;

queue<info> q;
queue<info> tmp[7];

int N, num;
int map[500][500];
int copymap[500][500];
int like[500][5];
int dx[4] = {1,0,0,-1}; 
int dy[4] = {0,1,-1,0}; 
int ans;


int isArea(int x,int y){
    if(x>-1 && x<N && y>-1 &&y<N) return 1;
    else    
        return 0;
}

int testisit(int num, int i, int j){
    if(map[i][j]==like[num][0] || map[i][j]==like[num][1] ||map[i][j]==like[num][2] ||map[i][j]==like[num][3]) return 1;
    else
        return 0;
}

//�ʿ� �����ϴ� ����� �ְ�, �� ��� �����¿� ���� ť�� �ֱ�
void verifylike(int num){
    int a, b;
    for(int i=N-1; i>-1; i--){
        for(int j=N-1; j>-1; j--){
            if(testisit(num, i,j)){
                for(int t=0; t<4; t++){
                    a = i +dx[t];
                    b = j + dy[t];
                    if(isArea(a, b) &&map[a][b]==0) {
                        copymap[a][b]+=1;
                    }
                }
            }
        }
    }
}

void emptysave(int num){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int key=0;

            if(map[i][j]==0){
            for(int t=0; t<4; t++){
                if(isArea(i+dx[t], j+dy[t])){
                    if(map[i+dx[t]][j+dy[t]]==0) key++;
                }
            }

            if(tmp[key].empty()) {tmp[key].push({i,j});}}
        }
    }

    for(int i=4; i>-1; i--){
        if(!tmp[i].empty()) {map[tmp[i].front().x][tmp[i].front().y] = num; break;}
    }
}

void printcopymap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<copymap[i][j];
        }
        cout<<"\n";
    }
}

//�ʿ� �����ϴ� ����� �ְ�, ���� �����ϴ� ������� ���� �����ϴ� ���� �з��ϱ�
void testcopymap(){
    int likemax=0;
    int x,y;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(copymap[i][j]>likemax){
                likemax = copymap[i][j];
            }
        }
    }

    if(likemax>0){
    for(int i=N-1; i>-1; i--){
        for(int j=N-1; j>-1; j--){
            if(copymap[i][j]==likemax){
                q.push({i,j});
            }
        }
    } }
    
}

//�ʿ� �����ϴ� ����� �ְ�,��/�� ��Ģ�� ���� �й�
void savemap(int num){
    int maxnum=0;    
    int maxx, maxy;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
    
        q.pop();

        int xx, yy;
        int key=0;

        for(int k=0; k<4;k++){
            xx = x+dx[k];
            yy = y+dy[k];
            if(isArea(xx, yy) && map[xx][yy]==0){
                key++;
            }
        }


        if(maxnum<=key){
            maxnum = key;
            maxx = x;
            maxy = y;
        }
        
        key=0;
    }
    map[maxx][maxy] = num;
}

void printmap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}




void howmuchans(){
    int x,y;
    int tmpans;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int t=0; t<4;t++){
                x = i+dx[t];
                y = j+dy[t];
                if(isArea(x,y) &&testisit(map[i][j], x,y)) tmpans++;
            }
            if(tmpans==2) tmpans=10;
            else if(tmpans ==3) tmpans = 100;
            else if(tmpans ==4) tmpans=1000;
            ans+=tmpans;
            tmpans=0;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    int N2;
    N2 = N*N;
    for(int i=1; i<=N2; i++){
        cin>>num;
        cin>>like[num][0]>>like[num][1]>>like[num][2]>>like[num][3];
        verifylike(num);
        testcopymap();

        if(q.empty()) {emptysave(num);}
        else{savemap(num);}

        while(!q.empty()){q.pop();}
        for(int k=0;k<5;k++){
            while(!tmp[k].empty()){tmp[k].pop();}
        }
        memset(copymap, 0, sizeof(copymap));
    }

    howmuchans();
    cout<<ans;
    

    


}