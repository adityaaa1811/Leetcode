class Solution {
public:
    vector<string> ans;
    string current;

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        solve(0, digits, mapping);

        return ans;
    }

    void solve(int index, string& digits, vector<string>& mapping) {
        // Base case: we've processed every digit
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // Convert character digit to integer
        int digit = digits[index] - '0';

        // Try every letter mapped to this digit
        for (char ch : mapping[digit]) {
            current.push_back(ch);

            // Move to the next digit
            solve(index + 1, digits, mapping);

            // Undo the choice
            current.pop_back();
        }
    }
};