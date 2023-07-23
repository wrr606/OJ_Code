#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 100010;

int a[N], s[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    unordered_set<int> hash;
    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ )
    {
        while (j < n && !hash.count(a[j])) hash.insert(a[j ++ ]);
        res = max(res, j - i);
        hash.erase(a[i]);
    }

    printf("%d\n", res);

    return 0;
}