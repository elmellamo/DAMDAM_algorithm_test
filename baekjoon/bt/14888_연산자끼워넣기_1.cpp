#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int numberArr[17];
int howArr[17];
int ansArr[17];
int visited[17];
vector<int> collectAns;

int smallAns(int x, int y, int how){
    if(how==1){
        return x+y;   
    }else if(how ==2){
        return x-y;
    }else if(how ==3){
        return x*y;
    }else{
        return x/y;
    }
}

int makeAns(){
    int tmp;
    tmp = numberArr[0];

   for(int t=0; t<N-1; t++){
        tmp = smallAns(tmp, numberArr[t+1], ansArr[t]);
    }
    return tmp;
}

void makeHow(int a, int b, int c, int d){
    for(int h=0; h<a; h++){
        howArr[h] = 1;
    }
    for(int h=a; h<a+b; h++){
        howArr[h] = 2;
    }
    for(int h=a+b; h<a+b+c; h++){
        howArr[h] = 3;
    }
    for(int h=a+b+c; h<a+b+c+d; h++){
        howArr[h] = 4;
    }
}

void BT(int depth){
    if(depth==N-1){
        int ttmp;

        ttmp = makeAns();
        collectAns.push_back(ttmp);
    }

    for(int i=0; i<N-1; i++){
        if(!visited[i]){
            visited[i] = 1;
            ansArr[depth] = howArr[i];
            BT(depth+1);
            visited[i]=0;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    int tmp;
    for(int n=0; n<N; n++){
        cin>>numberArr[n];
    }
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    makeHow(a,b,c,d);

    BT(0);
    sort(collectAns.begin(), collectAns.end());
    cout<<collectAns.back()<<"\n"<<collectAns.front();
}