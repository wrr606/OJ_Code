//d437. 10326 - The Polynomial Equation
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

ll x[51]={};

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n=2,y,last;
    while(cin>>n){
        memset(x,0,sizeof(x)),last=1;
        cin>>y;
        x[0]=-y,x[1]=1;
        while(--n){
            cin>>y;
            y*=-1;
            for(int i=50;i>0;i--){
                swap(x[i],x[i-1]);
            }
            for(int i=0;i<=50;i++){
                x[i]+=x[i+1]*y;
            }
            last++;
        }
        bool first=0;
        for(int i=last;i>=2;i--){
            if(x[i]){
                if(first){
                    if(x[i]<0){
                        cout<<"- ";
                        x[i]*=-1;
                        if(x[i]==1){
                            cout<<"x^"<<i<<" ";
                        }
                        else{
                            cout<<x[i]<<"x^"<<i<<" ";
                        }
                    }
                    else{
                        cout<<"+ ";
                        if(x[i]==1){
                            cout<<"x^"<<i<<" ";
                        }
                        else{
                            cout<<x[i]<<"x^"<<i<<" ";
                        }
                    }
                }
                else{
                    if(x[i]<0){
                        cout<<"- ";
                        x[i]*=-1;
                        if(x[i]==1){
                            cout<<"x^"<<i<<" ";
                        }
                        else{
                            cout<<x[i]<<"x^"<<i<<" ";
                        }
                    }
                    else{
                        if(x[i]==1){
                            cout<<"x^"<<i<<" ";
                        }
                        else{
                            cout<<x[i]<<"x^"<<i<<" ";
                        }
                    }
                    first=1;
                }
            }
        }
        if(x[1]){
            if(first){
                if(x[1]<0){
                    cout<<"- ";
                    x[1]*=-1;
                    if(x[1]==1){
                        cout<<"x"<<" ";
                    }
                    else{
                        cout<<x[1]<<"x"<<" ";
                    }
                }
                else{
                    cout<<"+ ";
                    if(x[1]==1){
                        cout<<"x"<<" ";
                    }
                    else{
                        cout<<x[1]<<"x"<<" ";
                    }
                }
            }
            else{
                if(x[1]<0){
                    cout<<"- ";
                    x[1]*=-1;
                    if(x[1]==1){
                        cout<<"x"<<" ";
                    }
                    else{
                        cout<<x[1]<<"x"<<" ";
                    }
                }
                else{
                    if(x[1]==1){
                        cout<<"x"<<" ";
                    }
                    else{
                        cout<<x[1]<<"x"<<" ";
                    }
                }
            }
        }
        if(x[0]<0){
            cout<<"- ";
            x[0]*=-1;
            cout<<x[0]<<" ";
        }
        else{
            cout<<"+ "<<x[0]<<" ";
        }
        cout<<"= 0\n";
    }
}