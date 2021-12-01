#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <aoc.h>

int solve_part1(std::ifstream& input)
{
    unsigned int inc_count = 0;
    int prev_depth = 0;

    std::string line;
    while (std::getline(input, line))
    {
        int depth = std::stoi(line);

        if (prev_depth == 0)
        {
            prev_depth = depth;
        }

        if (depth > prev_depth)
        {
            inc_count++;
        }

        prev_depth = depth;
    }

    return inc_count;
}

int solve_part2(std::ifstream& input)
{
    aoc::linked_list<int>* depths = new aoc::linked_list<int>;

    unsigned int inc_count = 0;
    int prev_sum = 0;

    std::string line;
    while (std::getline(input, line))
    {
        int depth = std::stoi(line);
        aoc::push_back(depths, depth);
    }

    for (int i = 0; i < depths->size - 2; i++)
    {
        int sum = 
            aoc::value_at(depths, i) + 
            aoc::value_at(depths, i + 1) + 
            aoc::value_at(depths, i + 2);

        if (prev_sum == 0)
        {
            prev_sum = sum;
        }

        if (sum > prev_sum)
        {
            inc_count++;
        }

        prev_sum = sum;
    }

    return inc_count;
}

int main()
{
    aoc::print_logo();

    std::ifstream input("input.txt");
    std::ifstream test_input("test.txt");

    std::cout << solve_part1(input) << std::endl;
    input.clear();
    input.seekg(0, std::ios::beg);

    std::cout << solve_part2(input) << std::endl;

    input.close();
    test_input.close();

    return 0;
}
