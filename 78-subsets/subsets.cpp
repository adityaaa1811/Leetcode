class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void solve(vector<int>& nums, int i) {

        // Base case
        if (i == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Include nums[i]
        current.push_back(nums[i]);
        solve(nums, i + 1);

        // Backtrack
        current.pop_back();

        // Choice 2: Exclude nums[i]
        solve(nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};