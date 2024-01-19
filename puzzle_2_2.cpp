#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int res = 0;
    unordered_map<char, int> first_char{{'r', 0}, {'g', 1}, {'b', 2}};

    while (getline(cin, line))
    {
        int char_index = 0;
        // parse game until ":""
        while (line[char_index] != ':')
            char_index++;

        char_index += 2;

        int color_count[3] = {0, 0, 0};

        while (char_index < line.size())
        {
            int color = -1;
            int number = 0;

            while (isdigit(line[char_index]))
            {
                number = number * 10 + (line[char_index] - '0');
                char_index++;
            }

            char_index++;

            color = first_char[line[char_index]];

            color_count[color] = max(color_count[color], number);

            while (!isdigit(line[char_index]))
            {
                char_index++;
                if (char_index >= line.size())
                    break;
            }
        }
        int power = 1;

        for (int i = 0; i < 3; i++)
            power *= color_count[i];

        res += power;
    }
    std::cout << res;

    return 0;
}