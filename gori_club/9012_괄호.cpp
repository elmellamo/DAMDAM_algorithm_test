#include <iostream>
#include <stack>
#include <string>
using namespace std;

int T,key;
stack<int> st;
string tmp;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T;

    for(int t=0; t<T; t++){
        key=0;
        cin>>tmp;

        int tmpsize;
        tmpsize = tmp.size();
        for(int s=0; s<tmpsize; s++){
            if(tmp[s]=='('){
                st.push(1);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    key=1;
                    break;
                }
            }
        }

        if(key||!st.empty()){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }

        while(!st.empty()){ //initialize!!
            st.pop();
        }
    }

}