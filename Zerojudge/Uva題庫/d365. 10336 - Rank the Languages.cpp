//d365. 10336 - Rank the Languages
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

char matrix[1001][1001]={};
bool matrix_bool[1001][1001]={0};
unordered_map<char,int> dict;
vector<pair<char,int>> dict_r;
int n,h,w;

bool cmp(pair<char,int> a, pair<char,int> b){
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

void DFS(int x,int y){
    //cout<<x<<"\t"<<y<<endl;
    matrix_bool[x][y]=1;
    if(!matrix_bool[x][y+1]&&matrix[x][y+1]==matrix[x][y])  DFS(x,y+1);
    if(!matrix_bool[x+1][y]&&matrix[x+1][y]==matrix[x][y])  DFS(x+1,y);
    if(!matrix_bool[x][y-1]&&matrix[x][y-1]==matrix[x][y])  DFS(x,y-1);
    if(!matrix_bool[x-1][y]&&matrix[x-1][y]==matrix[x][y])  DFS(x-1,y);
}

int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>n;
    for(int t=1;t<=n;t++){
        dict.clear(),dict_r.clear();
        memset(matrix_bool,0,sizeof(matrix_bool));
        cin>>h>>w;
        for(int i=1;i<=h;i++){
            cin>>s;
            for(int j=1;j<=w;j++){
                matrix[i][j]=s[j-1];
            }
        }
        cout<<"World #"<<t<<endl;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(!matrix_bool[i][j]){
                    DFS(i,j);
                    dict[matrix[i][j]]++;
                }
                /*debug
                for(int i=1;i<=h;i++){
                    for(int j=1;j<=w;j++){
                        cout<<matrix_bool[i][j];
                    }
                    cout<<endl;
                }
                cout<<endl;*/
            }
        }
        for(auto i:dict)
            dict_r.push_back({i.first,i.second});
        sort(dict_r.begin(),dict_r.end(),cmp);
        for(auto i:dict_r)
            cout<<i.first<<": "<<i.second<<endl;
    }
}