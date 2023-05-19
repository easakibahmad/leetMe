#include <iostream>
#include <string>
#include <algorithm>

class NumChecker
{
public:
    bool can_be_sum_of_num_and_reverse(int num)
    {
        int reverse_num = reverse_int(num);
        int sum_num_reverse = num + reverse_num;
        int reverse_sum = reverse_int(sum_num_reverse);
        return sum_num_reverse == reverse_sum;
    }

private:
    int reverse_int(int num)
    {
        std::string num_str = std::to_string(num);
        std::reverse(num_str.begin(), num_str.end());
        return std::stoi(num_str);
    }
};

int main()
{
    NumChecker num_checker;

    // Example 1: num = 121
    int num1 = 121;
    bool result1 = num_checker.can_be_sum_of_num_and_reverse(num1);
    std::cout << num1 << " can be expressed as the sum of any non-negative integer and its reverse: " << result1 << std::endl;

    // Example 2: num = 123
    int num2 = 443;
    bool result2 = num_checker.can_be_sum_of_num_and_reverse(num2);
    std::cout << num2 << " can be expressed as the sum of any non-negative integer and its reverse: " << result2 << std::endl;

    return 0;
}
