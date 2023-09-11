#include "common.h"

// Beats 100% time, 94% memory
class Solution {
public:
    int reverse(int x) {
        int result = 0, a = abs(x), lim = INT_MAX / 10;
        while (a > 0)
        {
            if (result > lim || result == lim && a%10 > 7) return 0;
            result = result * 10 + a % 10;
            a /= 10;
        }
        return x > 0 ? result : -result;
    }
};