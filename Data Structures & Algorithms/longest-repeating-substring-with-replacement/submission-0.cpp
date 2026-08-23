class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mymap;
        int left = 0;
        int right = 0;
        int maxlength = 0;
        for (; right < s.size(); right++) {
            int length = (right - left) + 1;
            mymap[s[right]]++;

            int maxfreq = 0;
            for (const auto& val : mymap) {
                maxfreq = max(maxfreq, val.second);
            }
            while (length - maxfreq > k) {
                mymap[s[left]]--;
                left++;
                length = (right - left) + 1;
            }

            maxlength = max(maxlength, length);
        }

        return maxlength;
    }
};
