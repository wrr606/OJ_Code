#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
  string s;
  while(cin >> s && s != "."){
    vector<int> failure(s.length(), 0);

    for(int i = 1, j = failure[0] = -1 ; i < s.length() ; ++i){
      while(j >= 0 && s[j+1] != s[i]) j = failure[j];
      if(s[j+1] == s[i]) ++j;
      failure[i] = j;
    }

    int repeatLength = s.length() - failure[s.length() - 1] - 1;
    if(s.length() % repeatLength == 0){
      printf("%d\n", s.length() / repeatLength);
    }
    else{
      printf("1\n");
    }
  }
  return 0;
}