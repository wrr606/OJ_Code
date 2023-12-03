//Sum_of_Two_Values
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(),x.end() 
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;

int binary_search(vector<pii > &num,int val){
    int res=-1,mid,l=0,r=num.size()-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(val>num[mid].first)
            l=mid+1;
        else if(val<num[mid].first)
            r=mid-1;
        else{
            res=mid;
            break;
        }
    }
    return res;
}

int main(){//greedy 二分搜
    ios::sync_with_stdio(0),cin.tie(0);
    int n,x,temp;
    cin>>n>>x;
    vector<pii > num(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        num[i]={temp,i};
    }
    sort(all(num));
    bool findit=0;
    for(int i=0;i<n;i++){
        findit=0;
        if(num[i].first>=x)
            continue;
        int index=binary_search(num,x-num[i].first);
        if(index!=-1&&index!=i){
            cout<<num[i].second+1<<" "<<num[index].second+1<<endl;
            findit=1;
            break;
        }
    }
    if(!findit)
        cout<<"IMPOSSIBLE\n";
}