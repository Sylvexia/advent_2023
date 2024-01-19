#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int res = 0;
    int color_max[] = {12, 13, 14};
    unordered_map<char,int> first_char{{'r', 0}, {'g', 1}, {'b', 2}};
    int game_index = 0;

    while (getline(cin, line))
    {
        game_index++;

        int char_index = 0;
        // parse game until ":""
        while (line[char_index] != ':')
            char_index++;

        char_index += 2;

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

            if (number > color_max[color])
            {
                goto failed_line;
            }

            while (!isdigit(line[char_index]))
            {
                char_index++;
                if (char_index >= line.size())
                    break;
            }
        }

        res += game_index;

    failed_line:;
    }
    std::cout << res;

    return 0;
}