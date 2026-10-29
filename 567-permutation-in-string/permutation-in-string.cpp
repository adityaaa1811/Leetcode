class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        int s1Freq[26] = {0};
        int windowFreq[26] = {0};

        for (int i = 0; i < s1.length(); i++) {
            s1Freq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }
        bool matches = true;

        for (int i = 0; i < 26; i++) {
            if (s1Freq[i] != windowFreq[i]) {
                matches = false;
                break;
            }
        }
        if (matches)
            return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            // Add incoming character
            windowFreq[s2[i] - 'a']++;

            // Remove outgoing character
            windowFreq[s2[i - s1.length()] - 'a']--;

            // Compare all 26 frequencies
            bool matches = true;

            for (int j = 0; j < 26; j++) {
                if (s1Freq[j] != windowFreq[j]) {
                    matches = false;
                    break;
                }
            }

            if (matches)
                return true;
        }

        return false;
    }
};