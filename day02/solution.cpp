#include <fstream>
#include <iostream>

#include <aoc.h>

int solve_part1(std::ifstream& input)
{
    int depth = 0;
    int x_pos = 0;

    std::string line;
    while (std::getline(input, line))
    {
        std::string command;
        std::string str_value;
        int value = 0;

        aoc::split(line, command, str_value);
        value = std::stoi(str_value);

        if (command == "forward")
            x_pos += value;
        else if (command == "up")
            depth -= value;
        else if (command == "down")
            depth += value;
    }

    return x_pos * depth;
}

int solve_part2(std::ifstream& input)
{
    int depth = 0;
    int x_pos = 0;
    int aim = 0;

    std::string line;
    while (std::getline(input, line))
    {
        std::string command;
        std::string str_value;
        int value = 0;

        aoc::split(line, command, str_value);
        value = std::stoi(str_value);

        if (command == "forward")
        {
            x_pos += value; 
            depth += aim * value;
        }
        else if (command == "up")
        {
            aim -= value;
        }
        else if (command == "down")
        {
            aim += value;
        }
            
    }

    return x_pos * depth;
}

int main()
{
    aoc::print_logo();

    std::ifstream input("input.txt");
    std::ifstream test_input("test.txt");

    aoc::printm("============== Test Input ==============\n");
    aoc::printm("Part 1: " + std::to_string(solve_part1(test_input)) + "\n");
    test_input.clear();
    test_input.seekg(0, std::ios::beg);

    aoc::printm("Part 2: " + std::to_string(solve_part2(test_input)) + "\n\n");

    aoc::printm("================= Input ================\n");
    aoc::printm("Part 1: " + std::to_string(solve_part1(input)) + "\n");
    input.clear();
    input.seekg(0, std::ios::beg);

    aoc::printm("Part 2: " + std::to_string(solve_part2(input)) + "\n");

    input.close();
    test_input.close();
    
    return 0;
}
