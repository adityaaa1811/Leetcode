class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& it : freq) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        // Traverse from highest frequency
        for (int i = bucket.size() - 1; i >= 0; i--) {

            // Visit elements in that frequency bucket
            for (int num : bucket[i]) {

                // Add to answer
                ans.push_back(num);

                // Stop when we have k elements
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};