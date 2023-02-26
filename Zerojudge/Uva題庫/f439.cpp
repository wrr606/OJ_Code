#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    string s,time1,time2,time11,time22;
    while(cin>>n){
        int counter=1;
        string ans_hr,ans_min,temp1,temp2;
        getline(cin,s);
        getline(cin,s);
        time1="",time2="";
        time1+=s[0],time1+=s[1],time1+=s[3],time1+=s[4];
        time2+=s[6],time2+=s[7],time2+=s[9],time2+=s[10];
        while(n--){
            //cout<<n<<endl;
            getline(cin,s);
            time11="",time22="";
            time11+=s[0],time11+=s[1],time11+=s[3],time11+=s[4];
            time22+=s[6],time22+=s[7],time22+=s[9],time22+=s[10];
            if(time11!=time2){
                ans_hr+=time2[0],ans_hr+=time2[1];
                ans_min+=time2[2],ans_min+=time2[3];
                temp1=time11[0],temp1+=time11[1];
                temp2=time11[2],temp2+=time11[3];
                break;
            }
            time1=time11;
            time2=time22;
        }
        for(n;n<=0;n--)
            getline(cin,s);
        cout<<"Day #"<<counter<<": "<<"the longest nap starts at "<<ans_hr<<":"<<ans_min<<" and will last for ";
        int d_hr,d_min;
        d_hr=stoi(temp1)-stoi(ans_hr),d_min=stoi(temp2)-stoi(ans_min);
        if(d_hr)
            cout<<d_hr<<" hours and ";
        cout<<d_min<<" minutes.\n";
        counter++;
    }
}