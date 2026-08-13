class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int left = 0;
        int right = 0;

        unordered_map<char, int> seen;
        while (right < s.size()) {
            if (seen.contains(s[right])) {
                left = max(left, seen[s[right]] + 1);
            }
            seen[s[right]] = right;
            longest = max(longest, (right - left) + 1);
            right++;
        }
        
        return longest;
    }
};
