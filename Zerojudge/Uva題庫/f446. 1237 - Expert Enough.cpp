#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

bitset<10001> bol;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,d,q,qa;
    cin>>t;
    while(t--){
        cin>>d;
        vector<string> x(d);
        vector<int> min(d),max(d);
        for(int i=0;i<d;i++)
            cin>>x[i]>>min[i]>>max[i];
        cin>>q;
        while(q--){
            bol.reset();
            string temp;
            bool n=0;
            cin>>qa;
            for(int i=0;i<d;i++){
                if(bol.count()>1)
                    break;
                if(qa>=min[i]&&qa<=max[i]){
                    bol[i]=1;
                    temp=x[i];
                }
            }
            if(bol.count()>1||bol.none())
                cout<<"UNDETERMINED\n";
            else
                cout<<temp<<endl;
        }
    }
}