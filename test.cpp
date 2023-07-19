#include<bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v = {1, 3, 5, 7, 9, 11, 13};
  int val = 6;

  auto lower = lower_bound(v.begin(), v.end(), val);
  auto upper = upper_bound(v.begin(), v.end(), val);

  cout << "The lower bound of " << val << " is " << *lower << endl;
  cout << "The upper bound of " << val << " is " << *upper << endl;

  return 0;
}
