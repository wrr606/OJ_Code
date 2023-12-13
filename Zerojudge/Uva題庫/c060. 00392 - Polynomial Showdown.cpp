//c060. 00392 - Polynomial Showdown
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n[9];
    while(cin>>n[0]){
        bool zero=1;
        for(int i=1;i<9;i++){
            cin>>n[i];
            if(n[i])
                zero=0;
        }
        if(zero){
            cout<<0<<endl;
            continue;
        }
        bool fir=1;
        for(int i=0;i<9;i++){
            if(n[i]&&fir){
                if(i==7){
                    if(n[i]==1)
                        cout<<"x";
                    else if(n[i]==-1)
                        cout<<"-x";
                    else
                        cout<<n[i]<<"x";
                }
                else if(i==8){
                    if(n[i]==1)
                        cout<<1;
                    else if(n[i]==-1)
                        cout<<-1;
                    else
                        cout<<n[i];
                }
                else{
                    if(n[i]==1)
                        cout<<"x^"<<8-i;
                    else if(n[i]==-1)
                        cout<<"-x^"<<8-i;
                    else
                        cout<<n[i]<<"x^"<<8-i;
                }
                fir=0;
            }
            else if(n[i]&&!fir){
                if(i==7){
                    if(n[i]==1)
                        cout<<" + x";
                    else if(n[i]==-1)
                        cout<<" - x";
                    else if(n[i]<0)
                        cout<<" - "<<abs(n[i])<<"x";
                    else
                        cout<<" + "<<n[i]<<"x";
                }
                else if(i==8){
                    if(n[i]==1)
                        cout<<" + 1";
                    else if(n[i]==-1)
                        cout<<" - 1";
                    else if(n[i]<0)
                        cout<<" - "<<abs(n[i]);
                    else
                        cout<<" + "<<n[i];
                }
                else{
                    if(n[i]==1)
                        cout<<" + x^"<<8-i;
                    else if(n[i]==-1)
                        cout<<" - x^"<<8-i;
                    else if(n[i]<0)
                        cout<<" - "<<abs(n[i])<<"x^"<<8-i;
                    else
                        cout<<" + "<<n[i]<<"x^"<<8-i;
                }
                fir=0;
            }
        }
        cout<<endl;
    }
}