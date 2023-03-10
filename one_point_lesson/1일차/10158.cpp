#include <iostream>
using namespace std;

int w, h, howlong, startx, starty;
int x, y; //현재 위치
int dx[4]={-1,1,-1,1};
int dy[4]={1,1,-1,-1};
int ori=1;

int isend(int a, int b){
    if(a==0 || a==w || b==0 || b==h) return 1;
    else
        return 0;
}

void move(int ori, int x, int y, int howlong){
    for(int i=0; i<howlong; i++){
    x = x+ dx[ori];
    y = y+ dy[ori];

    if(isend(x,y)){
        if(ori==0){
            if(x==0 &&y!=h) ori=1;
            else if(x!=0 && y==h) ori=2;
            else
                ori=3;
        }
        else if(ori==1) {
            if(x==w && y!=h) ori=0;
            else if (x!=w && y==h)  ori=3;
            else
                ori = 2;
        }
        else if(ori=2){
            if(x!=0 && y==0) ori=0;
            else if(x==0 && y!=0) ori = 3;
            else
                ori = 1;
        }
        else{
            if(x!=w && y==0) ori=1;
            else if(x==w && y!=0) ori = 2;
            else
                ori = 0;
        }
    }

    //cout<<ori<<" "<<x<<" "<<y<<" "<<"\n";
    }

    cout<<x<<" "<<y;
}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>w>>h>>startx>>starty>>howlong;
    x = startx;
    y = starty;

    move(ori, x,y,howlong);
}