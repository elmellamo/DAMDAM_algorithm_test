#include <iostream>
using namespace std;

int map[57][57];
int visited[57][57];
int N,M,r,c,ori, key, tmp;
int x,y;
int ans=1;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void robot(int r, int c, int ori){
    x = r + dx[ori];
    y = c + dy[ori]; 

    ori = ori-1;
    if(ori==-1) ori=3;

    if((key%4==0) && key>0){
         x = r+ dx[ori];
         y = c+ dy[ori];
         //cout<<"***"<<r<<" "<<c<<" "<<x<<" "<<y<<" "<<key<<"\n";

         if(!map[x][y]){
            key=0;
            ori = ori+1;
            if(ori==4) ori=0;
            //cout<<"****"<<x<<" "<<y<<" "<<key<<"\n";
            robot(x,y,ori);
         }
    }
    else{
    if(!map[x][y] && !visited[x][y]){
        visited[x][y] = 1;
        ans++;
        //cout<<ans<<"**"<<x<<" "<<y<<" "<<key<<"\n";
        key=0;
        robot(x, y, ori);
    }else{ 
        key++;
        //cout<<"*"<<r<<" "<<c<<" "<<x<<" "<<y<<" "<<key<<"\n";
        robot(r,c,ori);
    }
    }

    

}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    cin>>r>>c>>ori;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    
    visited[r][c]=1;
    robot(r, c, ori);
    cout<<ans;

}