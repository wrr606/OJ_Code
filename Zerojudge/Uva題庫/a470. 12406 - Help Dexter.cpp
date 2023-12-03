#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<long long int> y;

void dp12(int n,long long int x,int i){
    x=x*10+i;
    n--;
    if(!n){
        y.push_back(x);
        //cout<<"x:"<<x<<endl;
    }
    else{
        dp12(n,x,1);
        dp12(n,x,2);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,p,counter=1;
    long long int q;
	cin>>n;
    while(n--){
        cin>>p>>q;
        cout<<"Case "<<counter<<": ";
        counter++;
        y.clear();
        dp12(p,0,1);
        dp12(p,0,2);
        q=pow(2,q);
        long long int temp=-1;
        bool n=1;/*
        for(auto i:y){
            cout<<"y:"<<i<<endl;
        }
        cout<<"q:"<<q<<endl;*/
        for(int i=0;i<y.size();i++){
            if(y[i]%q==0){
                n=0;
                temp=y[i];
                cout<<temp;
                y.erase(y.begin()+i);
                break;
            }
        }
        for(int i=y.size()-1;i>=0;i--){
            if(y[i]%q==0){
                n=0;
                cout<<" "<<y[i];
                break;
            }
            if(y[i]<=temp)
                break;
        }
        if(n)
            cout<<"impossible"<<endl;
        else
            cout<<endl;
    }
}