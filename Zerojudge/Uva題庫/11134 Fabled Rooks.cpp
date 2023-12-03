//11134 Fabled Rooks
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

struct coordinate{
    int l,r,index;
};

bool cmp(coordinate a,coordinate b){
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,xl,yl,xr,yr;
    while(cin>>n&&n){
        bool impossible=0;
        vector<coordinate> x,y;
        vector<pii > ans(n);
        unordered_set<int> numbers;
        //因為要掃描每個線段的全部，所以要用set來確認該數字是否掃過
        for(int i=0;i<n;i++){
            cin>>xl>>yl>>xr>>yr;
            x.push_back({xl,xr,i}),y.push_back({yl,yr,i});
        }
        sort(all(x),cmp),sort(all(y),cmp);
        for(int i=0;i<n;i++){
            bool flag=0;
            for(int j=x[i].l;j<=x[i].r;j++){
                if(numbers.find(j)==numbers.end()){
                    ans[x[i].index].first=j;
                    numbers.insert(j);
                    flag=1;
                    break;
                }
            }
            if(!flag){
                impossible=1;
                break;
            }
        }
        if(!impossible){
            numbers.clear();
            for(int i=0;i<n;i++){
                bool flag=0;
                for(int j=y[i].l;j<=y[i].r;j++){
                    if(numbers.find(j)==numbers.end()){
                        ans[y[i].index].second=j;
                        numbers.insert(j);
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    impossible=1;
                    break;
                }
            }
        }
        if(impossible)
            cout<<"IMPOSSIBLE\n";
        else
            for(const auto &i:ans)
                cout<<i.first<<" "<<i.second<<endl;
    }
}