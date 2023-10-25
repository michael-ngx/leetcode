class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        vector<int> count(60, 0);
        for (int t : time) {
            count[t % 60]++;
        }
        
        for (int i = 1; i < 30; i++) {
            result += count[i] * count[60 - i];
        }
        if (count[0] % 2 == 0) result += (count[0] / 2) * (count[0] - 1);
        else result += (count[0]) * ((count[0] - 1) / 2);
        
        result += (count[30]) * (count[30] - 1) / 2;
        return result;
    }
};