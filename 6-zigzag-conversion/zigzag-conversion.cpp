class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;

        for(char ch : s) {

            // Put character in current row
            rows[row] += ch;

            // Move in current direction
            row += direction;

            // Change direction at boundaries
            if(row == 0) {
                direction = 1;
            }
            else if(row == numRows - 1) {
                direction = -1;
            }
        }

        string result;

        for(string r : rows) {
            result += r;
        }

        return result;
    }
};