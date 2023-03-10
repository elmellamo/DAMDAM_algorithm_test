#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, M, d, s, shark, first, sec, thir;
int map[57][57];
int dex[4] = {-1,1,0,0};
int dey[4] = {0,0,-1,1};

int bombx[4] = {0, 1, 0, -1};
int bomby[4] = {-1, 0, 1, 0};

vector<int> v1;
vector<int> v2;

int isArea(int x, int y){
    return x>-1&&x<N&&y>-1&&y<N;
}

void destroyBall(int d, int s){
    int x, y;
    x = shark;
    y = shark;

    for (int i = 0; i < s; i++){
        x += dex[d];
        y += dey[d];
        if(isArea(x,y)){
            map[x][y] = 0;
        }
    }
}

void putVect(){
    int x, y;
    x = shark;
    y = shark;
    int t = 1;
    int ori = 0;
    int key=0;

    while(1){
        for (int i = 0; i < t; i++){
            x += bombx[ori];
            y += bomby[ori];
            if (isArea(x,y)) {
                if(map[x][y] != 0){
                    v1.push_back(map[x][y]);
                }
            }
            else{
                key=-1;
                break;
            }              
        }

        if(key==-1){
            break;
        }

        ori++;

        for (int i = 0; i < t; i++){
            x += bombx[ori];
            y += bomby[ori];
            if (isArea(x,y)) {
                if(map[x][y] != 0){
                    v1.push_back(map[x][y]);
                }
            }
            else{
                key=-1;
                break;
            }              
        }

        if(key==-1){
            break;
        }

        ori++;
        ori %= 4;
        t++;
    }
}

void putMap(){
    int x, y, v;
    x = shark;
    y = shark;
    int t = 1;
    int ori = 0;
    int key=0;
    int v2size;

    v2size=v2.size();
    v = 0;

    if(v2size>0){
        while(1){
        for (int i = 0; i < t; i++){
            x += bombx[ori];
            y += bomby[ori];
            if (isArea(x,y)&&v!=v2size) {
                map[x][y] = v2[v];
                v++;
            }else{
                key=1;
                break;
            }
        }

        ori++;
        if(key){
            break;
        }
        

        for (int i = 0; i < t; i++){
            x += bombx[ori];
            y += bomby[ori];
            if (isArea(x,y)&&v!=v2size) {
                map[x][y] = v2[v];
                v++;
            }else{
                key=1;
                break;
            }
        }

        ori++;
        ori %= 4;
        t++;

        if(key){
            break;
        }
    }

    while(!v2.empty()){
        v2.pop_back();
    }
    }
    
}

void printMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

void printV1(){
    for(int i:v1){
        cout<<i<<" ";
    }
}

void printV2(){
    for(int i:v2){
        cout<<i<<" ";
    }
}

void bombBall(){
    int v1size, v2size;
    int whatfront;
    int key, nobomb;

    while(1){
        v1size = v1.size();
        if(v1size>1){
            whatfront = v1[0];
            v2.push_back(whatfront);
            nobomb = 0;
            key=0;

            for (int i = 1; i < v1size; i++){
                if (v1[i] == whatfront){
                    key++;
                }   
                else{
                    if (key >= 3){
                        for (int t = 0; t <= key; t++){
                            v2.pop_back();
                        }
                        nobomb =1;
                        if(whatfront==1){
                            first = first + key + 1;
                        }   
                        else if(whatfront==2){
                            sec = sec + key + 1;
                        }
                        else{
                            thir = thir + key + 1;
                        }
                    }
                    key = 0;
                }
                v2.push_back(v1[i]);
                whatfront = v1[i];
            }

            if(key>=3){
                for (int t = 0; t <= key; t++){
                    v2.pop_back();
                }
                nobomb =1;
                if(whatfront==1){
                    first = first + key + 1;
                }   
                else if(whatfront==2){
                    sec = sec + key + 1;
                }
                else{
                    thir = thir + key + 1;
                }
            }

            while (!v1.empty()){
                v1.pop_back();
            }

            v2size = v2.size();

            if(v2size>0){
                for (int i = 0; i < v2size; i++){
                    v1.push_back(v2[i]);
                }

                while (!v2.empty()){
                    v2.pop_back();
                }
            }

            if(!nobomb){
                break;
            }
        }
        else{
            break;
        } 
    }
}

void changeBall(){
    int v1size;
    int whatfront;
    int key, tmp;

    v1size = v1.size();
    if(v1size>1){
        whatfront = v1[0];
        key=0; 

        for (int i = 1; i < v1size; i++){
            if (v1[i] == whatfront){
                key++;
            }
            else{
                v2.push_back(key+1);
                v2.push_back(whatfront);
                key = 0;
                whatfront = v1[i];
            }
        }

        if(v1[v1size-2]!=v1[v1size-1]){
            v2.push_back(1);
            v2.push_back(whatfront);
        }else if(key==1){
            v2.push_back(2);
            v2.push_back(whatfront);
        }else{
            v2.push_back(key+1);
            v2.push_back(whatfront);
        }

    }else if(v1size==1){
        v2.push_back(1);
        v2.push_back(v1[0]);
    }
    
    while (!v1.empty()){
        v1.pop_back();
    }    
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> M;

    shark = N / 2;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < M; i++){
        cin >> d >> s;
        destroyBall(d-1, s);
        putVect();
        bombBall();
        changeBall();
        memset(map, 0, sizeof(map));
        putMap();
    }

    int ans;
    ans = first + 2*(sec) + 3*(thir);
    cout<<ans;
}