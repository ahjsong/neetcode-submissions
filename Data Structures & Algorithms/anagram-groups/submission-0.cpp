class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> final;
        for (auto word : strs) {
            string modify = word;
            sort(modify.begin(), modify.end());
            final[modify].push_back(word);
        }
        vector<vector<string>> send;
        for (auto vec : final) {
            send.push_back(vec.second);
        }
        return send;
    }
};
