#include<bits/stdc++.h>
using namespace std;

bitset<INT16_MAX> st;
int MAXN=5;

void f(int c=MAXN, bool b=0){
    if(c<=0)
        return;
    if(!b){
        if(st[c-1])
            f(c-2, 0);
        if(!st[c-1])
            f(c-1, 1);
        cout<<"Move ring "<<c<<" out\n";
        st[c]=0;
        if(st[c-1])
            f(c-1, 0);
    }
    else{
        if(st[c-1])
            f(c-2, 0);
        if(!st[c-1])
            f(c-1, 1);
        cout<<"Move ring "<<c<<" in\n";
        st[c]=1;
        if(st[c-1])
            f(c-1, 0);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    st.set();
    cin>>MAXN;
    f();
}
/*
1 2 3
1 1 0

1 2 3 4 5
1 1 1 1 0
*/