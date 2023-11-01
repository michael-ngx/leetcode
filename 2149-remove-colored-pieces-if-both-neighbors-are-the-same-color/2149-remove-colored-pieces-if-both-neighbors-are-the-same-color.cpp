class Solution {
public:
    bool winnerOfGame(string colors) {
        if (colors.size() < 3) return false;
        int A = 0, B = 0;
        for (int i = 1; i <= colors.size() - 2; i++) {
            if (colors[i-1] == colors[i] && colors[i] == colors[i+1]) {
                if (colors[i] == 'A') A++;
                else B++;
            }
        }
        return A > B;
    }
};