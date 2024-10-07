#include <iostream>
#include <vector> 

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - (1 + i)];
            s[s.size() - (1 + i)] = temp;
        }
    }
};

int main() {
    Solution solution;
    
    std::vector<char> s = {5, 'h', 'e', 'l', 'l', 'o'};
    
    std::cout << "s prior to reversal: [";

    for (char c : s) {
        std::cout << c << " ";
    }

    std::cout << "]" << std::endl;
    
    solution.reverseString(s);

    std::cout << "s after reversal: [ ";

    for (char c : s) {
        std::cout << c << " ";
    }

    std::cout << "]" << std::endl;
}