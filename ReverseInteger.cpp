#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

class Solution 
{
    public:
    int reverse(int x) const
    {
        int sign = (x > 0) ? 1 : -1;
        int64_t y = ::llabs(x);
        int64_t op = static_cast<int64_t>(y), rev;
        std::string aux = std::to_string(op);

        std::ranges::reverse(aux);
        rev = std::stoll(aux);
        if(rev > INT32_MAX)
            return 0;

        return static_cast<int>(sign * rev);
    }
};

int main()
{
    Solution obj;
    int x = -1250;
    std::cout << "INIT: " << x << "\nREVERSED: " << obj.reverse(x) << "\n";
    return 0;
}
