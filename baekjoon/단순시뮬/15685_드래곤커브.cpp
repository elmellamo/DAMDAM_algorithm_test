#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, x, y, d, g;
int map[107][107];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans;
vector<int> dirdragon;

int changeori(int ori){
    if(ori==0) return 1;
    else if(ori==1) return 2;
    else if(ori==2) return 3;
    else
        return 0;
}

void dragontest(int stx, int sty, int ori, int generation){
    int xx,yy, sized, tmp;
    
    //0 generation
    dirdragon.push_back(ori);
    xx = stx+dx[ori];
    yy = sty+dy[ori];
    map[xx][yy]=1;
    //cout<<"0 generation >>"<<xx<<" "<<yy<<"\n";


    // after 1 generation
    for(int i=1; i<=generation; i++){
        sized = dirdragon.size();
        //cout<<"size>> "<<sized<<"\n";
 
        for(int j=sized-1; j>-1; j--){
            tmp = changeori(dirdragon[j]);
            xx += dx[tmp];
            yy += dy[tmp];
            //cout<<i<<"generation>> "<<xx<<" "<<yy<<" ori>> "<<tmp<<"\n";
            map[xx][yy]=1;
            dirdragon.push_back(tmp);
        }

        

    }
}

int isArea(int x, int y){
    if(x>-1 && x<101 && y>-1 && y<101) return 1;
    else
        return 0;
}

void printSqure(){
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }

}

void testSquare(){
    int testtmp;
    int ddx[3]={0,1,1};
    int ddy[3]={1,0,1};
    int xx, yy;

    //printSqure();

    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            testtmp=0;
            if(map[i][j]){
                for(int t=0; t<3; t++){
                    xx = i+ddx[t];
                    yy = j+ddy[t];
                    if(isArea(xx, yy) && map[xx][yy]) {
                        testtmp++;
                    }
                }
                //cout<<"left upper "<<xx<<" "<<yy<<"\n";
                if(testtmp==3) {
                    //cout<<"squre >>  "<<i<<" "<<j<<"\n";
                    ans++;
                }
            }
        }
    }
}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int n=0; n<N; n++){
        cin>>y>>x>>d>>g;
        x=100-x;
        //cout<<"dfsdf  "<<x<<" "<<y<<"\n";
        map[x][y] = 1;
        //함수 돌리기
        dragontest(x, y, d, g);

        while(!dirdragon.empty()){
            dirdragon.pop_back();
        }
    }

    testSquare();
    cout<<ans;

}