
/*
Write a program that performs base conversion. The input is a string, an integer b1, and another integer b2. The string represents be an integer in base b1. The output should be the string representing the integer in base b2. Assume 2 ≤b1,b2 ≤ 16. Use "A" to represent 10, "B" for 11, ,.and "F" for 15.
*/

#include <iostream>
#include <string>

std::string construct_from_base(int num_as_int, int base)
{
    return (num_as_int == 0) ? "" : construct_from_base(num_as_int / base, base) + (char)((num_as_int % base >= 10) ? 'A' + (num_as_int % base - 10) : '0' + (num_as_int % base));
}

std::string convert_base(const std::string &num_as_string, int b1, int b2)
{
    bool is_negative = num_as_string.front() == '-';
    int num_as_int = 0;

    for (int i = (is_negative ? 1 : 0); i < num_as_string.size(); i++)
    {
        num_as_int *= b1;
        num_as_int += isdigit(num_as_string[i]) ? (num_as_string[i] - '0') : (num_as_string[i] - 'A' + 10);
    }

    return (is_negative ? "-" : "") + (num_as_int == 0 ? "0" : construct_from_base(num_as_int, b2));
}

int main()
{
    std::cout << convert_base("615", 7, 13) << std::endl;
    return 0;
}