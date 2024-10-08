#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> squareNums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            squareNums[i] = nums[i] * nums[i];
        }

        // for (int i = 0; i < squareNums.size(); i++) {
        for (int i = 0; i < 1; i++) {
            // std::cout << i << "th iteration of i: " << intvector2String() << std::endl; // delete l8r
            // for (int j = i + 1; j < squareNums.size(); j++) {
            // for (int j = 1; j < 2; j++) {
            for (int j = i + 1; j < 3; j++) {
                std::cout << j << "th iteration of j" << std::endl;
                if (squareNums[i] < squareNums[j]) {
                    break;
                }
                int temp = squareNums[i];
                squareNums[i] = squareNums[j];
                squareNums[j] = temp;
            }
        }
        return squareNums;
    }
};


int main() {
    Solution solution;
    
    std::vector<int> s = {16, 1, 0, 9, 100};
    
    std::cout << "s prior to reversal: [";

    for (int c : s) {
        std::cout << c << " ";
    }

    std::cout << "]" << std::endl;
    
    solution.sortedSquares(s);

    std::cout << "s after reversal: [ ";

    for (int c : s) {
        std::cout << c << " ";
    }

    std::cout << "]" << std::endl;
}