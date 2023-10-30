class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b)
        {
            int aa = 0, bb = 0;
            int n = a;
            while(n) {
                aa += n % 2;
                n = n >> 1;
            }
            n = b;
            while(n) {
                bb += n % 2;
                n = n >> 1;
            }
            return aa < bb || (aa == bb && a < b);
        });
        return arr;
    }
};