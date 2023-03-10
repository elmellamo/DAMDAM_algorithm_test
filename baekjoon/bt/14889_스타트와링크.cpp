#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, N2;
int map[27][27];
int visited[27];
int visited2[27];
int ans2[27]; // 스타트팀에서 2명씩 뽑은 오름차순 순열 저장

int ans[27]; //스타트팀 멤버
int bns[27]; // 링크팀 멤버 
int rsttmp, atmp, btmp; // 점수차 임시변수, 스타트팀 점수, 링크팀 점수


//뽑은 집합은 ans[0] ~ ans[N2-1] 에 저장되어 있음
//이미 n/2 집합을 뽑았고 거기서 순열 내고 점수합 내기
void computer1(int depth, int arr[]){
    if(depth==2){
        atmp += map[ans2[0]][ans2[1]];
        //cout<<ans2[0]<<" "<<ans2[1]<<'\n';
        return;
    }

    for(int next=0; next<N2; next++){
        if(!visited2[next]){
            visited2[next] = 1;
            ans2[depth] = arr[next];
            computer1(depth+1, arr);
            visited2[next]= 0;
        }
    }
}


void computer2(int depth, int arr[]){
    if(depth==2){
        btmp += map[ans2[0]][ans2[1]];
        //cout<<ans2[0]<<" "<<ans2[1]<<'\n';
        return;
    }

    for(int next=0; next<N2; next++){
        if(!visited2[next]){
            visited2[next] = 1;
            ans2[depth] = arr[next];
            computer2(depth+1, arr);
            visited2[next]= 0;
        }
    }
}
//스타트팀, 링크팀 멤버 뽑는 함수
void BT(int pos, int depth){
    if(depth == N2){
        int t=0;
        int key=0; 
        for(int i=1; i<=N ; i++){
            key=0; 
            for(int j=0; j<N2 ; j++){
                if(ans[j]==i) key=1;
            }
            if(key!=1){
                bns[t] = i;
                t++;
            }
        }


        computer1(0, ans);
        computer2(0, bns);
        rsttmp = atmp - btmp;
        if(rsttmp<0) rsttmp = -1*rsttmp;

       
        
        // cout<<"**"<<'\n';
        // for(int i=0; i<depth;i++){
        //     cout<< ans[i]<<" ";
        // }
        // cout<<atmp<<'\n'<<"============"<<'\n';
        // for(int i=0; i<depth;i++){
        //     cout<< bns[i]<<" ";
        // }
        // cout<<btmp<<'\n'<<"===================="<<'\n';

        atmp=0;
        btmp=0;

        v.push_back(rsttmp);
        return;
    }

    for(int next= pos+1; next<=N; next++){
        if(!visited[next]){
            visited[next]=1;
            ans[depth] = next;
            BT(next, depth+1);
            visited[next] = 0;
        }
    }

}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            cin>> map[i][j];
        }
    }

    N2 = N/2;

    BT(0, 0);
    sort(v.begin(), v.end());
    cout<<v.front();

}