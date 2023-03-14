#include <iostream>
#include <stack>
using namespace std;


int K, tmp;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    stack<int>  st1; 
    cin>>K;
    for(int k=0; k<K; k++){
        cin>>tmp;
        if(tmp!=0){
            st1.push(tmp);
        }else{
            st1.pop();
        }
    }

    tmp = st1.size();
    int ans=0;
    for(int i=0;i<tmp; i++){
        ans += st1.top();
        st1.pop();
    }

    cout<<ans;

}