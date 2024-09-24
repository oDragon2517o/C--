#include <iostream>
#include <vector>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

class Solution
{
public:
    // nums = [ 2, 7, 11, 15 ];
    // std::vector<int> nums{2, 7, 11, 15};
    // int target = 9;

    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        for (int i = 0; i + 1 < nums.size(); i++)
        {
            // std::cout << nums[i] << "\n";
            for (int j = i + 1; j < nums.size(); j++)
            {
                // std::cout << nums[i] << " ";
                // std::cout << nums[j] << "\n";
                if (nums[i] + nums[j] == target)
                {
                    // std::cout << i << " " << j << "\n ";
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    std::vector<int> nums{2, 7, 11, 15};
    Solution Solution;

    Solution.twoSum(nums, 9);
}