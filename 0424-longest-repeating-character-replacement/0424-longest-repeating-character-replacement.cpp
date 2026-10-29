class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int maxFreq = 0;
        int freq[26] = {0};

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(freq[s[right] - 'A'], maxFreq);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};