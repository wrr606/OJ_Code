#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

set<int> prime_number;
bool is_prime(int n){
    for(int i=2;i<=sqrt(n);i+=(i==2)?1:2){
        if(n%i==0)
            return 0;
    }
    if(n<2)
        return 0;
    return 1;
}

int q=0;
void recursion(string x,string temp=""){
    int number;
    if(x!=""){
        int lenght=x.size();
        string std0=x,std1=temp;
        for(int i=0;i<lenght;i++){
            temp=std1;
            x=std0;
            temp+=x[i];
            x.erase(i,1);
            //cout<<"x:"<<x<<"   temp:"<<temp<<endl;
            number=stoi(temp);
            if(is_prime(number))
                prime_number.insert(number);
            recursion(x,temp);
        }
    }
    else{
        number=stoi(temp);
        if(is_prime(number))
            prime_number.insert(number);
    }
}

int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,counter;
    string s;
    cin>>n;
    while(n--){
        counter=0;
        prime_number.clear();
        cin>>s;
        recursion(s);
        for(auto i:prime_number){
            //cout<<i<<endl;
            counter++;}
        cout<<counter<<endl;
    }
}
/*
4
17
1276543
9999999
011
*/