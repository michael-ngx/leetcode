#include "common.h"

class Solution {
public:
    int myAtoi(string s)
    {
        int i = 0; bool plus = true;
        while (s[i] == ' ') i++;
        if (s[i] == '-' || s[i] == '+')
        {
            plus = (s[i] == '+');
            i++;
        }
        while (s[i] == '0') i++;
        int result = 0, count = 0, lim = INT_MAX / 10;
        while (i < s.size() && isdigit(s[i]))
        {
            int next = s[i] - '0';
            if (count == 10 ||
               (count == 9 && (result > lim ||
                              (result == lim && (plus && next > 7 ||
                                                !plus && next >= 8)
                              ))
                ))
            {
                if (result == lim && !plus && next == 8) return INT_MIN;
                return plus ? INT_MAX : INT_MIN;
            }
            result = result * 10 + next;
            count++;
            i++;
        }
        return plus ? result : -result;
    }
};