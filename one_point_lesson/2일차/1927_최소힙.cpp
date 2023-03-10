#include <iostream>
using namespace std;

int map[100007];
int N, how;
int howmany;

void putMap(int how, int howmany){
    map[howmany] = how;
 
    int parents, ttmp, nownode;
    //compare parents
    //tmp == now node
    nownode = howmany;
    parents = nownode/2;

    while(map[parents]>map[nownode]){
        ttmp = map[parents];
        map[parents] = map[nownode];
        map[nownode] = ttmp;
        nownode = parents;
        parents = nownode/2 ;
    } 
}

void popMap(int howmany){
    map[1] = map[howmany];
    map[howmany] = 0;

    int child1, child2, ttmp, nownode;
    nownode = 1;
    child1 = 2; 
    child2 = 3;

    while(1){
        //두 개 다 차 있을 때
        if(map[child1]>0 && map[child2]>0){
        if(map[child1]<=map[child2]){
            if(map[child1]<map[nownode]){
                ttmp = map[nownode];
                map[nownode] = map[child1];
                map[child1] = ttmp;

                nownode = child1;
                child1 = 2*nownode;
                child2 = (2*nownode)+1;
            }
            else{
                break;
            }
        }else{
            if(map[child2]<map[nownode]){
                ttmp = map[nownode];
                map[nownode] = map[child2];
                map[child2] = ttmp;

                nownode = child2;
                child1 = 2*nownode;
                child2 = (2*nownode)+1;
            }
            else{
                break;
            }
        }}
        //한 개
        else if(map[child1]>0 && map[child2]==0){
            if(map[child1]<map[nownode]){
                ttmp = map[nownode];
                map[nownode] = map[child1];
                map[child1] = ttmp;

                break;
            }
            else{
                break;
            }
        }
        //0 개
        else {
            break;
        }

    }
}

void printMap(){
    int v=1;
    cout<<"\n";
    while(map[v]!=0){
        cout<<v<<">>  "<<map[v]<<"\n";
        v++;
    }
    cout<<"\n";
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>how;
        if(how==0){
            if(howmany!=0){
                cout<<map[1]<<"\n";
                popMap(howmany);
                howmany--;
            }else{
                cout<<"0\n";
            }

        }
        else{
            howmany++;
            putMap(how, howmany);
        }
    }


}