#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int res = 0;
    vector<string> words{"one", "two", "three",
                         "four", "five", "six",
                         "seven", "eight", "nine"};

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
            else
            {
                for (int j = 0; j < words.size(); j++)
                {
                    for (int k = 0; k < words[j].size(); k++)
                    {
                        if (i + k >= line.size() or
                            words[j][k] != line[i + k])
                            break;

                        if ((k + 1) == words[j].size())
                        {
                            left = j + 1;
                            goto first_loop_end;
                        }
                    }
                }
            }
        }

    first_loop_end:

        for (int i = line.size() - 1; i >= 0; i--)
        {
            if (isdigit(line[i]))
            {
                right = line[i] - '0';
                break;
            }
            else
            {
                for (int j = 0; j < words.size(); j++)
                {
                    for (int k = words[j].size() - 1; k >= 0; k--)
                    {
                        if (i - (words[j].size() - 1 - k) < 0 or
                            words[j][k] != line[i - (words[j].size() - 1 - k)])
                            break;

                        if (k == 0)
                        {
                            right = j + 1;
                            goto last_loop_end;
                        }
                    }
                }
            }
        }

    last_loop_end:

        res += (left * 10 + right);
    }
    std::cout << res;

    return 0;
}