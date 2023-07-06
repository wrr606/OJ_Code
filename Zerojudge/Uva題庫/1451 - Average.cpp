//1451 - Average
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int sum[100005];

int cmp(int x1,int x2,int x3,int x4){
    return (sum[x1]-sum[x2])*(x3-x4)-(sum[x3]-sum[x4])*(x1-x2);
}

int main(){//math
    ios::sync_with_stdio(0),cin.tie(0);
    int t,n,l;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>l>>s;
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+int(s[i-1])-48;
        int ans_left=0,ans_right=l;
        deque<int> que;
        for(int i=l;i<=n;i++){
            int j=i-l;
            while(que.size()>1){
                int last1=que.back(),last2=que[que.size()-2];
                if(cmp(last2,last1,last2,j)>0)
                    que.pop_back();
                else
                    break;
            }
            que.push_back(j);
            while(que.size()>1){
                if(cmp(que[0],i,que[1],i)<=0)
                    que.pop_front();
                else
                    break;
            }
            int cur=cmp(que[0],i,ans_left,ans_right);
            if(cur>0||cur==0&&ans_right-ans_left>i-que[0]){
                ans_right=i;
                ans_left=que[0];
            }
        }
        cout<<1+ans_left<<" "<<ans_right<<endl;
    }
}