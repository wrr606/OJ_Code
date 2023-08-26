#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000; // Maximum number of elements
int bit[MAXN + 1] = {0}; // Binary Indexed Tree

void update(int idx, int val, int n) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}

int find_by_order(int k, int n) {
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (query(mid) >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void erase(int val, int n) {
    int idx = find_by_order(val, n); // Find the index of val in BIT
    update(idx, -1, n); // Decrease the count of val in BIT
}

int main() {
    vector<int> nums = {10,20,30,40,50,60};
    int n = nums.size();

    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    for (int i = 0; i < n; ++i) {
        update(i + 1, 1, n);
    }

    int k = 2; // Find the 3rd smallest element
    int kth_smallest_index = find_by_order(k, n);
    cout << "The " << k << "rd smallest element is: " << sorted_nums[kth_smallest_index - 1] << endl;

    int val_to_erase = 2;
    erase(val_to_erase, n);

    kth_smallest_index = find_by_order(k, n - 1); // n - 1 after erasing
    cout << "The " << k << "rd smallest element after erasing is: " << sorted_nums[kth_smallest_index - 1] << endl;

    return 0;
}
