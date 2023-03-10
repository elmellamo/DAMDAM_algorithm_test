#include <iostream>
using namespace std;

int box[17][17];
int map[17][17];
int copymap[17][17];
int col[17];


void initBox(){
    int initnum;
    int tmp;

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            tmp = map[i+1][j+1];
            if(tmp!=0){
                initnum = 3*(i/3)+(j/3);
                box[initnum][tmp]=1;
            }
        }
    }

}


void sdoqu(int depth){
    //depth>> col init
    for(int t=1;t<10; t++){
        if(map[depth+1][t]>0) col[t]=1;
    }

    //finish condition
    if(depth==10){
        for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
        }
    }


    //i==해당 depth의 col 
    for(int i=1; i<10; i++){

        //find blank >> blank's box num
        for(int x=1; x<10; x++){
            if(map[depth+1][x]==0){
                int boxnum = 3*(depth/3)+((i-1)/3);

                if(!col[])
            }
        }
        
        //save boxnum > 해당 칸에서 검사를 하는거지
        //depth+1 행에 숫자 i가 있는지 아닌지 확인하기 >> 있나?
        if(!col[i]){
            col[i]=1;





/*
            for(int n=1; n<10; n++){
                if(!box[boxnum][n]){


                    map[depth+1][i] = n;
                    col[i] = 1;
                    box[boxnum][n] = 1;
                    sdoqu(depth+1);
                    box[boxnum][n] = 0;
                    map[depth+1][i] = 0;
                    col[i] =0;
                }
            }*/
        }
    }
    

}



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            cin>>map[i][j];
        }
    }

    cout<<"\n\n";
    initBox();
    sdoqu(1);

    

}