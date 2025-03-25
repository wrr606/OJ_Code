//e576. 10020 - Minimal Coverage
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

bool cmp(pii a,pii b){
    if(a.first!=b.first){
        return a.second<b.second;
    }
    else{
        return a.first<b.first;
    }
}

int main(){
    int n,m,li,ri;
    bool b=0;
    scanf("%d",&n);
    while(n--){
        if(b)
            printf("\n");
        else
            b=1;
        scanf("%d",&m);
        vector<pii > point;
        vector<pii > ans;
        while(scanf("%d%d",&li,&ri)!=EOF){
            if(!li&&!ri){
                break;
            }
            point.push_back({li,ri});
        }
        sort(all(point),cmp);
        if(point[0].first>=m){
            printf("0\n");
            continue;
        }
        int pointer=0;
        while(pointer<m){
            int max=pointer,max_pointer=-1;
            for(int i=0;i<point.size();i++){
                if(point[i].first<=pointer&&max<point[i].second){
                        max=point[i].second;
                        max_pointer=i;
                }
            }
            if(max_pointer==-1){
                pointer=0;
                break;
            }
            ans.push_back(point[max_pointer]);
            pointer=max;
        }
        if(pointer){
            printf("%d\n",ans.size());
            for(auto i:ans){
                printf("%d %d\n",i.first,i.second);
            }
        }
        else{
            printf("0\n");
        }
    }
}