#include <iostream>
using namespace std;

int map[507][507];
int N, N2;
int x, y, ori, rst, ddx,ddy;
int t=1;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int orix[4][10]={{-1,1,-2,2,0,-1,1,-1,1,0},{-1,-1,0,0,2,0,0,1,1,1},{-1,1,-2,2,0,-1,1,-1,1,0},{1,1,0,0,-2,0,0,-1,-1,-1}};
int oriy[4][10]={{1,1,0,0,-2,0,0,-1,-1,-1},{-1,1,2,-2,0,-1,1,-1,1,0},{-1,-1,0,0,2,0,0,1,1,1},{-1,1,-2,2,0,-1,1,-1,1,0}};


int isArea(int a, int b){
    if(a>-1&&a<N&&b>-1&&b<N) return 1;
    else
        return 0;
}

void printmap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void tonado(int startx, int starty,int orientation){
    int xx, yy;
    int tmp=0;
    int ddone, dtwo, dfive, dseven, dten, detc;
    
    xx = startx+dx[orientation];
    yy = starty+dy[orientation];

    
    //cout<<">>������ ��"<<xx<<" "<<yy<<"\n";
    ddone = int(map[xx][yy]*0.01);
    dtwo = int(map[xx][yy]*0.02);
    dfive = int(map[xx][yy]*0.05);
    dseven = int(map[xx][yy]*0.07);
    dten = int(map[xx][yy]*0.1);

    detc = map[xx][yy]-2*(ddone+dseven+dtwo+dten)-dfive;

    //cout<<"**"<<ddone<<" "<<dtwo<<" "<<dfive<<" "<<dseven<<" "<<dten<<" "<<detc<<"**\n\n";    
    for(int k=0; k<10;k++){
        ddx = xx + orix[orientation][k];
        ddy = yy + oriy[orientation][k];

        if(isArea(ddx, ddy)){
            if(k<2)
                map[ddx][ddy]+=ddone;
            else if(k>1 && k<4)
                map[ddx][ddy]+=dtwo;
            else if(k==4)
                map[ddx][ddy]+=dfive;
            else if(k>4&&k<7)
                map[ddx][ddy]+=dseven;
            else if(k>6&&k<9)
                map[ddx][ddy]+=dten;
            else
                map[ddx][ddy]+=detc;
        }else{
            if(k<2)
                rst+=ddone;
            else if(k>1 && k<4)
                rst+=dtwo;
            else if(k==4)
                rst+=dfive;
            else if(k>4&&k<7)
                rst+=dseven;
            else if(k>6&&k<9)
                rst+=dten;
            else
                rst+=detc;
        }
    }

    map[xx][yy]= 0;

    x=xx;
    y=yy;
}

int finaltest(){
     while(1){
        for(int i=0; i<t;i++){
            tonado(x,y,ori);
            //printmap();
            //cout<<rst<<"================\n";
            if(x==0 && y==0) {
                return rst;
            }
        }

        ori++;
        ori%=4;
        
        for(int i=0; i<t;i++){
            tonado(x,y,ori);
            //printmap();
            //cout<<rst<<"================\n";
            if(x==0 && y==0){
                return rst;
            }
    
        }

        ori++;
        ori%=4;
        t++;
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    N2 = N/2;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    x=N2; y=N2;

    cout<< finaltest();

}