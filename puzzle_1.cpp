#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int res = 0;
    while (cin >> line)
    {
        int left = 0;
        int right = 0;
        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
            {
                left = line[i] - '0';
                break;
            }
        }
        for (int i = line.size() - 1; i >= 0; i--)
        {
            if (isdigit(line[i]))
            {
                right = line[i] - '0';
                break;
            }
        }
        res += (left * 10 + right);
    }
    cout << res;

    return 0;
}