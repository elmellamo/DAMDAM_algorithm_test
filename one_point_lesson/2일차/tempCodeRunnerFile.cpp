#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

typedef struct{
    string pgans;
    int num;
}info;

vector<info> pgV;
vector<int> ansV;
string first;
int hownum, N;
int endKey;
int inf;

int testAbs(int a, int b){
    if(a*b>0) return 1;
    else
        return 0;
}

void modGo(){
    int anssize;
    long long tmp, first, sec;
    anssize = ansV.size();
    
    if(anssize>1){
        anssize = anssize-1;
        if(ansV[anssize]!=0){
            if(ansV[anssize-1]>0){
                first = abs(ansV[anssize-1]);
                sec = abs(ansV[anssize]);
                tmp = first%sec;

                if(abs(tmp)>inf){
                    endKey=1;
                }
                else{
                    ansV.pop_back();
                    ansV.pop_back();
                    ansV.push_back(tmp);
                }
            }
            else{
                first = abs(ansV[anssize-1]);
                sec = abs(ansV[anssize]);
                tmp = first%sec;
                tmp = tmp*(-1);

                if(abs(tmp)>inf){
                    endKey=1;
                }
                else{
                    ansV.pop_back();
                    ansV.pop_back();
                    ansV.push_back(tmp);
                }
            }
        }
        else{
            endKey=1;
        }
    }else{
        endKey = 1;
    }
}

void divGo(){
    int anssize;
    long long tmp, first, sec;
    anssize = ansV.size();
    
    if(anssize>1){
        anssize = anssize-1;
        first = abs(ansV[anssize-1]);
        sec = abs(ansV[anssize]);
        tmp = first/sec;

        if(ansV[anssize]!=0){
            if(testAbs(ansV[anssize-1], ansV[anssize])){
                if(abs(tmp)>inf){
                    endKey=1;
                }
                else{
                    ansV.pop_back();
                    ansV.pop_back();
                    ansV.push_back(tmp);
                }
            }
            else{
                tmp = tmp*(-1);
                if(abs(tmp)>inf){
                    endKey=1;
                }
                else{
                    ansV.pop_back();
                    ansV.pop_back();
                    ansV.push_back(tmp);
                }
            }
        }
        else{
            endKey=1;
        }
    }else{
        endKey = 1;
    }
}

void mulGo(){
    int anssize;
    long long tmp, first, sec;
    anssize = ansV.size();
    
    if(anssize>1){
        anssize = anssize-1;
        first = ansV[anssize-1];
        sec = ansV[anssize];
        tmp = first*sec;
        if(abs(tmp)>inf){
            endKey=1;
        }
        else{
        ansV.pop_back();
        ansV.pop_back();
        ansV.push_back(tmp);
        }
    }else{
        endKey = 1;
    }
}

void subGo(){
    int anssize;
    long long tmp, first, sec;
    anssize = ansV.size();
    
    if(anssize>1){
        anssize = ansV.size()-1;
        first = ansV[anssize-1];
        sec = ansV[anssize];

        tmp = first - sec;
        if(abs(tmp)>inf){
            endKey=1;
        }
        else{
            ansV.pop_back();
            ansV.pop_back();
            ansV.push_back(tmp);
        }
    }else{
        endKey = 1;
    }
}

void addGo(){
    int anssize;
    long long tmp, first, sec;
    anssize = ansV.size();
    if(anssize>1){
        anssize = ansV.size()-1;
        first = ansV[anssize-1];
        sec = ansV[anssize];
        tmp = first+sec;
        if(abs(tmp)>inf){
            endKey=1;
        }
        else{
            ansV.pop_back();
            ansV.pop_back();
            ansV.push_back(tmp);
        }
    }else{
        endKey = 1;
    }
}

void invGo(){
    int tmp;
    int anssize;
    anssize = ansV.size();

    if(anssize>0){
        tmp = (-1)*(ansV.back());
        ansV.pop_back();
        ansV.push_back(tmp);
    }
    else{
        endKey = 1;
    }
    }

void dupGo(){
    int backans;
    int anssize;
    anssize = ansV.size();

    if(anssize>0){
        backans = ansV.back();
        ansV.push_back(backans);
    }else{
        endKey = 1;
    }
}

void swpGo(){
    int anssize, tmp;
    anssize = ansV.size();
    
    if(anssize>1){
        anssize = anssize-1;
        tmp = ansV[anssize-1];
        ansV[anssize-1] = ansV[anssize];
        ansV[anssize] = tmp;
    }else{
        endKey = 1;
    }
}

void popGo(){
    int anssize;
    anssize = ansV.size();

    if(anssize>0){
        ansV.pop_back();
    }else{
        endKey = 1;
    }
}

void goStack(){
    int pgsize;
    pgsize = pgV.size();
    endKey=0;

    for(int v=0; v<pgsize; v++){
        if(pgV[v].pgans=="DUP"){
            dupGo();
        }
        else if(pgV[v].pgans=="SWP"){
            swpGo();
        }
        else if(pgV[v].pgans=="POP"){
            popGo();
        }
        else if(pgV[v].pgans=="INV"){
            invGo();
        }
        else if(pgV[v].pgans=="ADD"){
            addGo();
        }
        else if(pgV[v].pgans=="SUB"){
            subGo();
        }
        else if(pgV[v].pgans=="MUL"){
            mulGo();
        }
        else if(pgV[v].pgans=="DIV"){
            divGo();
        }
        else if(pgV[v].pgans=="MOD"){
            modGo();
        }
        else if(pgV[v].pgans=="NUM"){
            //Num 차례
            ansV.push_back(pgV[v].num);
        }

        if(endKey==1){
            break;
        }
    }
}

void printAns(){
    int anssize;
    anssize = ansV.size();
    for(int i=0; i<anssize; i++){
        cout<<i<<">> "<<ansV[i]<<"\n";
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    inf = pow(10,9);
    while(1){
        cin>>first;
        if(first=="QUIT") break;
        hownum=0;

        while(1){
            if(first=="NUM"){
                cin>>hownum;
                pgV.push_back({first, hownum});
            }
            else if(first == "END"){
                break;
            }
            else{
                pgV.push_back({first, hownum});
            }
   
            cin>>first;            
        }


        cin>>N;

        for(int i=0; i<N; i++){
            cin>>hownum;
            ansV.push_back(hownum);
            goStack();
            if(ansV.size()!=1||endKey==1){
                cout<<"ERROR\n";
            }
            else{
                cout<<ansV[0]<<"\n";
            }

            while(!ansV.empty()){
                ansV.pop_back();
            }
        }

        cout<<"\n";

        while(!pgV.empty()){
            pgV.pop_back();
        }

    }
}