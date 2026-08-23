class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        int num = 0;
        string current = "";

        for(char ch : s){
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            else if(ch == '['){
                nums.push(num);
                strs.push(current);

                num = 0;
                current = "";
            }
            else if(isalpha(ch)){
                current += ch;
            }
            else if(ch == ']'){
                int repeat = nums.top();
                nums.pop();

                string previous = strs.top();
                strs.pop();

                string temp = "";

                for(int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

        }
        return current;
    }
};

// digit
//   ↓
// build number

// [
//   ↓
// SAVE → reset

// letter
//   ↓
// add to current

// ]
//   ↓
// RESTORE → repeat → combine