//e446. 排列生成
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    int n;
    scanf("%d",&n);
    vector<int> sequence;
    for(int i=1;i<=n;i++)
        sequence.push_back(i);
    do{
        for(const auto &i:sequence)
            printf("%d ",i);
        printf("\n");
    }while(next_permutation(all(sequence)));
}