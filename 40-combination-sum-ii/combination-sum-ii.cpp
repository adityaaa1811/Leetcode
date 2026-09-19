class Solution {
public:

    vector<vector<int>> ans;
    vector<int> current;

    void solve(int start, int target, vector<int>& candidates) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted
            if (candidates[i] > target) {
                break;
            }

            // Choose
            current.push_back(candidates[i]);

            // Move to i + 1 because each element can be used only once
            solve(i + 1, target - candidates[i], candidates);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates);
        return ans;
    }
};