class Solution {
public:
    // We know that the order will be AEIOUaeiou
    // Therefore simply do counting sort
    vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    int index(char c) {
        for (int i = 0; i < 10; ++i)
            if (c == vowels[i])
                return i;
        return -1;
    }
    
    string sortVowels(string s) {
        vector<int> count(10, 0);
        vector<int> pos;
        for (int i = 0; i < s.size(); i++) {
            int idx = index(s[i]);
            if (idx == -1) continue;
            count[idx]++;
            pos.push_back(i);
        }
        
        int j;
        for (int i = 0; i < pos.size(); i++) {
            for (j = 0; j < 10; j++) {
                if (count[j] > 0) {
                    count[j]--;
                    break;
                }
            }
            s[pos[i]] = vowels[j];
        }
        return s;
    }
};