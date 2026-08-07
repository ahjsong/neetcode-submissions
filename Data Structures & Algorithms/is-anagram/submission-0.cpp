class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int arr[27] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                arr[26]++;
                continue;
            }
            if (t[i] == ' ') {
                arr[26]--;
                continue;
            }
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (auto x : arr) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }   
};
