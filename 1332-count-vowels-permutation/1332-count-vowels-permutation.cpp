class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> count(5,1);
        while (--n) {
            int a = (((count[1] % 1000000007) + (count[2] % 1000000007)) % 1000000007 + (count[4] % 1000000007)) % 1000000007;
            int e = ((count[0] % 1000000007) + (count[2] % 1000000007)) % 1000000007;
            int i = ((count[1] % 1000000007) + (count[3] % 1000000007)) % 1000000007;
            int o = (count[2]) % 1000000007;
            int u = ((count[2] % 1000000007) + (count[3] % 1000000007)) % 1000000007;
            count = {a,e,i,o,u};
        }
        return ((((count[0]%1000000007 + count[1]%1000000007)%1000000007 + count[2]%1000000007)%1000000007 + count[3]%1000000007)%1000000007 + count[4]%1000000007)%1000000007;
    }
};