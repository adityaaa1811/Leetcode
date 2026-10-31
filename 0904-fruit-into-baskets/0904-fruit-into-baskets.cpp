class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxLength = 0;
        int distinct = 0;

        vector<int> freq(fruits.size(), 0);

        for (int right = 0; right < fruits.size(); right++) {
            if (freq[fruits[right]] == 0) {
                distinct++;
            }
            freq[fruits[right]]++;

            while (distinct > 2) {
                freq[fruits[left]]--;

                if (freq[fruits[left]] == 0) {
                    distinct--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};