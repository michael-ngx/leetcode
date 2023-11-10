class Node {
public:
    int val;
    Node* next;
    Node(int _val) : val(_val), next(nullptr) {}
};

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
        unordered_map<int,vector<int>> map;
        for (auto p : arr) {
            int one = p[0], two = p[1];
            map[one].push_back(two);
            map[two].push_back(one);
        }
        int head;
        for (auto p : map) {
            if (p.second.size() == 1) {
                head = p.first;
                break;
            }
        }
        vector<int> result;
        result.push_back(head);
        int prev = head;
        head = map[head][0];
        while (result.size() != arr.size()) {
            result.push_back(head);
            if (map[head][0] == prev) {
                prev = head;
                head = map[head][1];
            } else {
                prev = head;
                head = map[head][0];
            }
        }
        result.push_back(head);
        return result;
    }
};