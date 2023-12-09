class Solution {
public:
    vector<string> fullJustify(vector<string>& w, int maxWidth) {
        vector<string> result;
        vector<string> line;
        line.push_back(w[0]);
        int len = w[0].size();
        for (int i = 1; i < w.size(); i++) {
            if (len + w[i].size() + line.size() > maxWidth) {
                string final = line[0];
                int space_count = line.size() - 1;
                if (space_count) {
                    int min_space_sz = (maxWidth - len) / space_count;
                    int num_space_extra = (maxWidth - len) % space_count;
                    for (int j = 1; j < line.size(); j++){
                        if (num_space_extra-- > 0) final += ' ';
                        final += string(min_space_sz, ' ');
                        final += line[j];
                    }
                }
                else {
                    final += string(maxWidth - final.size(), ' ');
                }
                result.push_back(final);
                line = {w[i]};
                len = w[i].size();
            } else {
                line.push_back(w[i]);
                len += w[i].size();
            }
        }
        string final = line[0];
        for (int j = 1; j < line.size(); j++) {
            final += ' ' + line[j];
        }
        // Add final spaces to end
        if (final.size() < maxWidth) final += string(maxWidth - final.size(), ' ');
        result.push_back(final);
        return result;
    }
};