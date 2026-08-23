class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        for (const auto& val : nums) {
            mymap[val]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> q;
        for (const auto& val : mymap) {
            q.push(val);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        
        return res;
    }

    struct ComparePair {
        bool operator()(const auto& left, const auto& right) {
            return left.second > right.second;
        }
    };
};
