class Solution {
public:
    int modular_multiply(int a, int b, int m) {
        int result = 0;
        a = a % m;

        while (b > 0) {
            if (b % 2 == 1) result = (result + a) % m;

            a = (a * 2) % m;
            b /= 2;
        }
        return result;
    }
    
    int countHomogenous(string s) {
        int i = 0, j = 0;
        int res = 0;
        do {
            j++;
            if (j == s.size() || s[i] != s[j]) {
                int len = j - i;
                res += modular_multiply(len, len+1, 1000000007) / 2;
                i = j;
            }
        } while (j != s.size());
        return res % 1000000007;
    }
};