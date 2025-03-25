//d550. 物件排序
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    vector<vector<int> > matrix(x,vector<int>(y));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    sort(all(matrix));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}