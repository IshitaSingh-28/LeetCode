class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (charIndexMap.find(s[right]) != charIndexMap.end()) {
                // Move the left pointer to the right of the previous index of s[right]
                left = max(charIndexMap[s[right]] + 1, left);
            }
            // Update the last index of s[right]
            charIndexMap[s[right]] = right;
            // Update the max length of the substring
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
