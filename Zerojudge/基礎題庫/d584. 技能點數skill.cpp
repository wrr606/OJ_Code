#include <bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    int a, b, t;
    while (cin >> a >> b)
    {
        if (!a)
        {
            cout << 0 << endl;
            continue;
        }
        t = 1;
        if (b >= 30)
            t++;
        if (b >= 70)
            t++;
        if (b >= 120)
            t += 3;
        if (a == 2)
            t += (b - 8) * 3;
        else
            t += (b - 10) * 3;
        cout << t << endl;
    }
}