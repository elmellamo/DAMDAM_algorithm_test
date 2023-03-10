#include <iostream>
#include <memory.h>
using namespace std;

int N,M,R, N2,M2;
int map[107][107];
int copymap[107][107];

void initMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map[i][j] = copymap[i][j];
        }
    }
}
void firstFunction(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copymap[N-1-i][j]=map[i][j];
        }
    }
}

void secondFunction(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copymap[i][M-1-j]=map[i][j];
        }
    }
}

void thirdFunction(){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            copymap[i][j] = map[N-1-j][i];
        }
    }
    int tmp; 
    tmp = N;
    N=M;
    M=tmp;    
    N2 = N/2;
    M2 = M/2;
    memset(map, 0, sizeof(map));
}

void forthFunction(){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            copymap[i][j] = map[j][M-1-i];
        }
    }
    int tmp; 
    tmp = N;
    N=M;
    M=tmp;
    N2 = N/2;
    M2 = M/2;
    memset(map, 0, sizeof(map));
}


void fiveFunction(){
    int r,c;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            r = i/N2;
            c = j/M2;

            if(r==0&&c==0) copymap[i][j] = map[i+N2][j];
            else if(r==0 && c==1) copymap[i][j] = map[i][j-M2];
            else if(r==1 && c==1) copymap[i][j] = map[i-N2][j];
            else
                copymap[i][j] = map[i][j+M2];           
        }
    }

}

void sixFunction(){
    int r,c;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            r = i/N2;
            c = j/M2;

            if(r==0&&c==0) copymap[i][j] = map[i][j+M2];
            else if(r==0 && c==1) copymap[i][j] = map[i+N2][j];
            else if(r==1 && c==1) copymap[i][j] = map[i][j-M2];
            else
                copymap[i][j] = map[i-N2][j];           
        }
    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>R;
    N2 = N/2;
    M2 = M/2;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }

    int how;

    for(int r=0;r<R;r++){
        cin>>how;
        if(how==1) firstFunction();
        else if(how==2) secondFunction();
        else if(how==3) thirdFunction();
        else if(how==4) forthFunction();
        else if(how==5) fiveFunction();
        else
            sixFunction();
        
        
        initMap();
        memset(copymap, 0, sizeof(copymap));
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}