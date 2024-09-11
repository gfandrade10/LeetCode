#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class Solution 
{
    #ifndef COORD_2D_
    #define COORD_2D_(i,j,col) i*col + j
    
    public:
    static std::string ZigzagConversion(const std::string& s, int numRows) 
    {
        if (numRows == 1) 
            return s;

        int numColumns;
        int coord;
        int difference = (numRows - 2 > 0 ? numRows - 2 : 0);
        int blockSize = 1 + difference;
        int len = static_cast<int>(s.length());
        int firstPart = len/blockSize;
        int secondPart = len%blockSize;

        if(secondPart == 0) 
        {
            numColumns = (difference + 1) * firstPart;
        }
        else if(secondPart < numRows)
        {
            numColumns = (difference + 1) * firstPart + 1;
        }
        else 
        {
            numColumns = (difference + 1) * firstPart + 1 + difference - (secondPart - numRows);
        }

        std::vector<char> strManip(numRows * numColumns);
        std::fill(strManip.begin(), strManip.end(), ' ');

        int strPtr = 0, i = 0, j = 0, block = 1;
        while(strPtr < len)
        {
            while(i < numRows && strPtr < len)
            {
                coord = COORD_2D_(i,j,numColumns);
                strManip[coord] = s[strPtr];
                strPtr++;
                i++;
            }
            i -= 2;
            j++;
            while(i > 0 && strPtr < len)
            {
                coord = COORD_2D_(i,j,numColumns);
                strManip[coord] = s[strPtr];
                strPtr++;
                i--;
                j++;
            }
        }

        std::string res;
        std::copy_if(strManip.begin(), strManip.end(), std::back_inserter(res),
            [](const char& c) ->bool { return c != ' '; });

        for(i = 0; i < numRows; ++i)
        {
            for(j = 0; j < numColumns; ++j)
                std::cout << strManip[COORD_2D_(i,j,numColumns)] << " ";
            std::cout << "\n";
        }
        
        return res;
    }

    #undef COORD_2D_
    #endif // !COORD_2D_(lin,col)
};

int main()
{
    std::pair<std::string, int> input {"PAYPALISHIRING", 9};
    auto ans = Solution::ZigzagConversion(input.first, input.second);
    std::cout << "Answer: " << ans << "\n\n";
}
