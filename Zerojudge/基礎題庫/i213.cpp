#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    stack<int> x;
    int n,k,temp;
    cin>>n;
    while(n--){
        cin>>k;
        switch(k){
            case 1:
                cin>>temp;
                x.push(temp);
                break;
            case 2:
                if(x.empty())
                    cout<<-1<<endl;
                else
                    cout<<x.top()<<endl;
                break;
            case 3:
                if(!x.empty())
                    x.pop();
        }
    }
}