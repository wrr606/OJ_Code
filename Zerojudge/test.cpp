#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x,y,i;
};
struct node
{
    int x,i;
};
int n;
vector<point> vpx,vpy;
vector<node> ansx,ansy;
int cmp(const point &lhs,const point &rhs)
{
    if(lhs.y!=rhs.y)
        return lhs.y<rhs.y;
    else
        return lhs.x<rhs.x;
}
int ncmp(const node &lhs,const node &rhs)
{
    return lhs.i<rhs.i;
}
unordered_set<int> usi;
int main()
{
    ios::sync_with_stdio(false);
    int flag;
    while(cin>>n)
    {
        if(n==0)
            break;
        flag=1;
        vpx.clear();
        vpy.clear();
        ansx.clear();
        ansy.clear();
        for(int i=0;i<n;i++)
        {
            int xl,yl,xr,yr;
            cin>>xl>>yl>>xr>>yr;
            vpx.push_back(point{xl,xr,i});
            vpy.push_back(point{yl,yr,i});
        }
        sort(vpx.begin(),vpx.end(),cmp);
        sort(vpy.begin(),vpy.end(),cmp);
        usi.clear();
        for(int i=0;i<vpx.size();i++)
        {
            int mark=0;
            for(int j=vpx[i].x;j<=vpx[i].y;j++)
            {
                if(usi.find(j)==usi.end())
                {
                    ansx.push_back(node{j,vpx[i].i});
                    usi.insert(j);
                    mark=1;
                    break;
                }
            }
            if(!mark)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            usi.clear();
            for(int i=0;i<vpy.size();i++)
            {
                int mark=0;
                for(int j=vpy[i].x;j<=vpy[i].y;j++)
                {
                    if(usi.find(j)==usi.end())
                    {
                        ansy.push_back(node{j,vpy[i].i});
                        usi.insert(j);
                        mark=1;
                        break;
                    }
                }
                if(!mark)
                {
                    flag=0;
                    break;
                }
            }
        }

        if(flag==0)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            sort(ansx.begin(),ansx.end(),ncmp);
            sort(ansy.begin(),ansy.end(),ncmp);
            for(int i=0;i<ansx.size();i++)
            {
                cout<<ansx[i].x<<" "<<ansy[i].x<<endl;
            }
        }

    }

    return 0;
}
