#include <cstddef>
#include <iostream>
#include <vector>

class Solution 
{
    public:
    Solution() = default;
    ~Solution() = default;

    template<typename T>
    void printVector(const std::vector<T>& vec) const
    {
        for(const auto& it:vec)
            std::cout << it << "  ";
        std::cout << "\n";
    }

    bool validateStackSequences(const std::vector<int>& pushed, const std::vector<int>& popped) const
    {
        if(pushed.size() != popped.size())
            return false;

        size_t len = pushed.size();
        std::vector<int> aux;
        aux.reserve(len);
        
        std::vector<int>::const_iterator pushedIt, poppedIt;
        pushedIt = pushed.begin();
        poppedIt = popped.begin();

        aux.push_back(*(pushedIt++));
        while(poppedIt != popped.end())
        {
            if(!aux.empty() && aux.back() == *poppedIt)
            {
                aux.pop_back();
                poppedIt++;
            }

            else if(pushedIt != pushed.end())
            {
                aux.push_back(*pushedIt);
                pushedIt++;
            }

            else if(pushedIt == pushed.end())
                poppedIt++;

            printVector(aux);
        }
        
        return aux.empty();
    }
};

int main()
{
    std::vector<int> pushed = {1,2,3,4,5}, popped = {4,5,3,2,1};
    Solution sol;
    bool ans = sol.validateStackSequences(pushed, popped);
    std::cout << (ans ? "TRUE\n" : "FALSE\n");
    return 0;
}
