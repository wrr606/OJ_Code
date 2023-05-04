//i426. 12657 Boxes in a Line
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

//link list
int n,m,r[100010],l[100010];

//reverse link list可以得知前一項的key
void link(int i,int j){
    r[i]=j;
    l[j]=i;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int operate,c=1;
    while(cin>>n){
        bool reverse=0;
        cin>>m;
        for(int i=1;i<=n;i++){
            r[i]=i+1;
            l[i]=i-1;
        }
        r[0]=1,l[0]=n,r[n]=0;
        while(m--){
            cin>>operate;
            if(reverse){
                if(operate==2)
                    operate=1;
                else if(operate==1)
                    operate=2;
            }
            if(operate==1){
                int x,y;
                cin>>x>>y;//4 2
                if(l[y]==x)
                    continue;
                int rx=r[x],ry=r[y],lx=l[x],ly=l[y];
                link(ly,x),link(x,y),link(lx,rx);
            }
            else if(operate==2){
                int x,y;
                cin>>x>>y;//4 2
                if(r[y]==x)
                    continue;
                int rx=r[x],ry=r[y],lx=l[x],ly=l[y];
                link(y,x),link(x,ry),link(lx,rx);
            }
            else if(operate==3){
                int x,y;
                cin>>x>>y;
                if(r[y]==x){
                    int rx=r[x],ly=l[y];
                    link(ly,x),link(x,y),link(y,rx);
                    continue;
                }
                if(r[x]==y){
                    int ry=r[y],lx=l[x];
                    link(lx,y),link(y,x),link(x,ry);
                    continue;
                }
                int rx=r[x],ry=r[y],lx=l[x],ly=l[y];
                link(lx,y),link(y,rx),link(ly,x),link(x,ry);
            }
            else{
                reverse=!reverse;
            }
        }
        ll now=0,ans=0;
        bool b=1;
        if(reverse)
            for(int i=0;i<n;i++){
                //cout<<l[now]<<" ";
                if(b)
                    ans+=l[now];
                b=!b;
                now=l[now];
            }
        else
            for(int i=0;i<n;i++){
                //cout<<r[now]<<" ";
                if(b)
                    ans+=r[now];
                b=!b;
                now=r[now];
            }
        cout<<"Case "<<c<<": "<<ans<<endl;
        c++;
    }
}