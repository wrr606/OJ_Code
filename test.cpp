#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> s = {5 ,3, 7, 8, 5};
  int val = 5;

  auto lower = s.lower_bound(val);
  auto upper = s.upper_bound(val);

  cout << "The lower bound of " << val << " is " << *--lower << endl;
  cout << "The upper bound of " << val << " is " << *--upper << endl;

  return 0;
}
