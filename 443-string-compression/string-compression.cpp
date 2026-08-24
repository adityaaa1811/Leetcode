class Solution {
public:
    int compress(vector<char>& chars) {

        int read = 0;
        int write = 0;

        while(read < chars.size()) {

            int start = read;

            // Find the end of this group
            while(read < chars.size() &&
                  chars[read] == chars[start]) {
                read++;
            }

            int count = read - start;

            // Write the character
            chars[write++] = chars[start];

            // Write the count if needed
            if(count > 1) {

                string countStr = to_string(count);

                for(char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};