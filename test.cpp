#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  list<int> l;
  for(int i=0;i<N;i++){
    l.push_back(i);  //放入編號0~N-1
  }
  list<int>::iterator it=l.begin();
  while(N>1){  //直到剩下1人
    N--;
    int cnt=1;
    while(cnt<M){  //找到加一個要刪除的點
      cnt++;
      it++;
      if(it==l.end()) it=l.begin();
    }
    auto erase=it;
    it++;
    if(it==l.end()) it=l.begin();
    l.erase(erase);  //刪除
  } 
  cout << *it << endl;
  return 0;
}