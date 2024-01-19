#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int res = 0;

    vector<string> input;

    while (getline(cin, line))
        input.push_back(line);

    for (int i = 0; i < input.size(); i++)
    {
        int j = 0;

        while (j < input.size())
        {
            int num = 0;
            bool is_val = false;
            while (isdigit(input[i][j]))
            {
                num = num * 10 + input[i][j] - '0';

                for (int l = max(0, i - 1); l <= i + 1 and l < input.size(); l++)
                {
                    for (int m = max(0, j - 1); m <= j + 1 and m < input[i].size(); m++)
                    {
                        if (!isdigit(input[l][m]) and input[l][m] != '.')
                        {
                            is_val = true;
                            break;
                        }
                    }
                }

                j++;
                if (j >= input[i].size())
                    break;
            }

            num = is_val ? num : 0;
            res += num;
            j++;
        }
    }
    std::cout << res;

    return 0;
}