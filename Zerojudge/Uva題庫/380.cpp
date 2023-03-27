//380 Call Forwarding
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,start,duration;
    bool b=1;
    string x,y;
    cin>>t;
    vector<pii > time;
    vector<pair<string,string> > person;
    
    cout<<"CALL FORWARDING OUTPUT\n";
    for(int c=1;c<=t;c++){
        while(cin>>x&&x!="0000"){
            cin>>start>>duration>>y;
            person.push_back({x,y});
            time.push_back({start,start+duration});
        }
        cout<<"SYSTEM "<<c<<endl;
        while(cin>>y&&y!="9000"){
            cin>>x;
            cout<<"AT "<<y<<" CALL TO "<<x;
            start=stoi(y);
            b=1;
            string a=x;
            while(b){
                b=0;
                for(int i=0;i<person.size();i++){
                    if(person[i].first==x){
                        if(time[i].first<=start&&time[i].second>=start){
                            if(person[i].second==a){
                                x="9999";
                            }
                            else{
                                x=person[i].second;
                                b=1;
                            }
                            break;
                        }
                    }
                }
            }
            cout<<" RINGS "<<x<<endl;
        }
    }
    cout<<"END OF OUTPUT\n";
}
/*
1111 0100 0200 2222
1111 0301 0500 4444
2222 0200 0200 3333
3333 0250 1000 1111
7777 1000 2000 7777
0000
0050 1111
0150 1111
0200 1111
0225 2222
0270 1111
0320 1111
0320 3333
0900 3000
1250 3333
1250 7777
*/