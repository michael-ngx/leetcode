class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int row = abs(fy-sy);
        int col = abs(fx-sx);
        if (row == 0 && col == 0) return t != 1;
        return t >= (min(row,col) + abs(row-col));
    }
};