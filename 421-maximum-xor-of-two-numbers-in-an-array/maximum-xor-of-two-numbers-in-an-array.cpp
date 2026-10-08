class Solution {
public:
    struct Node {
        Node* child[2] = {nullptr, nullptr};
    };

    Node* root = new Node();

    void insert(int num) {
        Node* curr = root;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!curr->child[bit])
                curr->child[bit] = new Node();

            curr = curr->child[bit];
        }
    }

    int getMaxXOR(int num) {
        Node* curr = root;
        int ans = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if (curr->child[opposite]) {
                ans |= (1 << i);
                curr = curr->child[opposite];
            } 
            else {
                curr = curr->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums)
            insert(num);

        int ans = 0;

        for (int num : nums)
            ans = max(ans, getMaxXOR(num));

        return ans;
    }
};

