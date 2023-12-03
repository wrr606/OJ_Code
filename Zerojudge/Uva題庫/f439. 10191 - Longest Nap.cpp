#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,counter=1;
    string s,time1,time2,time11,time22;
    while(cin>>n){
        string ans_hr,ans_min,temp1,temp2,maxkey;
        map<string,int> sleep_time;
        bool b=1;
        getline(cin,s);
        time2="1000";
        while(n--){
            //cout<<n<<endl;
            getline(cin,s);
            time11="",time22="";
            time11+=s[0],time11+=s[1],time11+=s[3],time11+=s[4];//1530
            time22+=s[6],time22+=s[7],time22+=s[9],time22+=s[10];
            if(time11!=time2){
                if(b)
                    maxkey=time2;
                b=0;
                temp1="",temp2="";
                temp1+=time11[0],temp1=time11[1];
                temp2+=time11[2],temp2+=time11[3];
                sleep_time[time2]=stoi(temp1)*60+stoi(temp2);
                temp1="",temp2="";
                temp1+=time2[0],temp1=time2[1];
                temp2+=time2[2],temp2+=time2[3];
                sleep_time[time2]-=stoi(temp1)*60+stoi(temp2);
                if(sleep_time[maxkey]<sleep_time[time2])
                    maxkey=time2;
            }
            time1=time11;
            time2=time22;
        }
        time11="1800";
        if(time11!=time2){
            if(b)
                maxkey=time2;
            b=0;
            temp1="",temp2="";
            temp1+=time11[0],temp1=time11[1];
            temp2+=time11[2],temp2+=time11[3];
            sleep_time[time2]=stoi(temp1)*60+stoi(temp2);
            temp1="",temp2="";
            temp1+=time2[0],temp1=time2[1];
            temp2+=time2[2],temp2+=time2[3];
            sleep_time[time2]-=stoi(temp1)*60+stoi(temp2);
            if(sleep_time[maxkey]<sleep_time[time2])
                maxkey=time2;
        }
        cout<<"Day #"<<counter<<": "<<"the longest nap starts at "<<maxkey[0]<<maxkey[1]<<":"<<maxkey[2]<<maxkey[3]<<" and will last for ";
        if(sleep_time[maxkey]/60!=0)
            cout<<sleep_time[maxkey]/60<<" hours and ";
        cout<<sleep_time[maxkey]%60<<" minutes.\n";
        counter++;
    }
}