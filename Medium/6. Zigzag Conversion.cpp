#include "common.h"

// Beats 87.57% Time, 92.5% Memory
class Solution {
public:
    string convert(string s, int numRows){
        if (numRows == 1) return s;
        string result = "";
        for (int row = 0; row < numRows; row++)
        {
            string str = "";
            bool down = true;
            int space = 0;
            for (int i = row; i < s.size(); i += space)
            {
                str += s[i];
                if (row == 0 || row == numRows - 1)
                {
                    space = (numRows - 1) * 2;
                }
                else if (down)
                {
                    space = (numRows - 1 - row) * 2;
                    down = !down;
                }
                else
                {
                    space = row * 2;
                    down = !down;
                }
            }
            result += str;
        }
        return result;
    }
};