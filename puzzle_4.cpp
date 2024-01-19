#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> input;
    string line;
    int res = 0;

    while (getline(cin, line))
    {
        int j = 0;
        int local_score = 0;
        while (line[j] != ':')
            j++;

        unordered_set<int> win_nums;
        while (true)
        {
            while (!isdigit(line[j]))
            {
                if (line[j] == '|')
                    goto score_count;
                j++;
            }

            int parse_num = 0;
            while (isdigit(line[j]))
            {
                parse_num = parse_num * 10 + line[j] - '0';
                j++;
            }
            win_nums.insert(parse_num);
        }

    score_count:

        while (true)
        {
            while (!isdigit(line[j]))
            {
                if (j >= line.size())
                    goto result;
                j++;
            }

            int parse_num = 0;
            while (isdigit(line[j]))
            {
                parse_num = parse_num * 10 + line[j] - '0';
                j++;
            }

            if (win_nums.find(parse_num) != win_nums.end())
            {
                local_score = (local_score == 0)
                                  ? 1
                                  : local_score * 2;
            }
        }

    result:
        res += local_score;
    }

    std::cout << "result: " << res << "\n";

    return 0;
}