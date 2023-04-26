//d649. 數字三角形
#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int r = 1; r <= n; r++)
        {
            for (int i = 1; i <= n - r; i++)
            {
                cout << "_";
            }
            for (int j = 1; j <= r; j++)
            {
                cout << "+";
            }
            cout << endl;
        }
    }
}