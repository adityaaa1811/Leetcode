class Solution {
public:
    vector<vector<int>> ans;
    vector<int> candidates;
    

    void solve(int start, int remaining, vector<int>& current) {
        if (remaining == 0) {
            ans.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > remaining) {
                break;
            }
            current.push_back(candidates[i]);
            solve(i, remaining - candidates[i], current);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        
        vector<int> current;

        solve(0, target, current);
        return ans;
    }
};
