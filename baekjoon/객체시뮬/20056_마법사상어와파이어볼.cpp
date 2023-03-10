#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef struct{
    int m, s, d;
}info;

queue<info> map[57][57];
queue<info> copymap[57][57];

int N,M,K;
int dx[8]= {-1,-1,0,1, 1, 1, 0,-1};
int dy[8]= {0,1, 1, 1, 0, -1, -1,-1};


//�ű��, �ٸ� ���� �ϳ� �� ���� �̿�, �� �ϳ��� ���� �������
//������ ���� �� �������� �´�
//�ű� �� ���� �Ѿ �� %���� �����

int rangecheck(int x){
    x = (1000*N + x)%N;
    return x;
}

void copyMap(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!copymap[i][j].empty()){
                while(!copymap[i][j].empty()) {
                    map[i][j].push({copymap[i][j].front().m, copymap[i][j].front().s, copymap[i][j].front().d});
                    copymap[i][j].pop();
                }
            }
        }
    }

}

void movefire(){
    int x, y, M , S, D, checksize;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            checksize = map[i][j].size();
        
            for(int t=0; t<checksize; t++){
                M = map[i][j].front().m;
                S = map[i][j].front().s;
                D = map[i][j].front().d;

                x = rangecheck(i+(dx[D]*S));
                y = rangecheck(j +(dy[D]*S));
                //cout<<x<<"��"<<y<<"��"<<" "<<M<<" "<<S<<" "<<D<<"��\n";
                copymap[x][y].push({M,S,D});
                map[i][j].pop();
            }
        }
    }
}


void destroyfires(){
    int M,S,D, key, size, ans; 

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            size = map[i][j].size();
            if(size>1){
                M=0; S=0; D=0;
                key = map[i][j].front().d;
                key= key%2;
                while(!map[i][j].empty()){
                    M+=map[i][j].front().m;
                    S+=map[i][j].front().s;
                    D=map[i][j].front().d;
                    D = D%2;
                    if(D!= key)  ans=-1;
                    key = D;
                    map[i][j].pop();
                }

                M = M/5;
                S = S/size;

                if(M!=0){
                    if(ans==0){
                        map[i][j].push({M, S, 0});
                        map[i][j].push({M, S, 2});
                        map[i][j].push({M, S, 4});
                        map[i][j].push({M, S, 6});
                    }
                    else{
                        map[i][j].push({M, S, 1});
                        map[i][j].push({M, S, 3});
                        map[i][j].push({M, S, 5});
                        map[i][j].push({M, S, 7});
                    }
                }
                }

            ans=0;

        }
    }
}


void printMap(){
    int sizemap=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N;j++){
            sizemap=map[i][j].size();
            if(sizemap>0){
                for(int z=0; z<sizemap;z++){
                    cout<<i<<"��"<<j<<"��"<<" "<<map[i][j].front().m<<" "<<map[i][j].front().s<<" "<<map[i][j].front().d<<"\n";
                    map[i][j].pop();
                }
            }
            
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>K;

    int r,c,m,s,d;
    for(int i=0; i<M; i++){
        cin>>r>>c>>m>>s>>d;
        map[r-1][c-1].push({m,s,d});
    }

    for(int k=0; k<K; k++){
        movefire();
        copyMap();
        //cout<<"�浹�� �ε�����\n";
        destroyfires();
    }

    int rst=0;
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            if(map[i][j].size()>0){
                while(!map[i][j].empty()){
                    //cout<<i<<"��"<<j<<"��"<<" "<<map[i][j].front().m<<" "<<map[i][j].front().s<<" "<<map[i][j].front().d<<"\n";
                    rst+= map[i][j].front().m;
                    map[i][j].pop();
                }
            }
        }
    }

    //cout<<"=---\n";
    cout<<rst;


}