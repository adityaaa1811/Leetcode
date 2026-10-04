class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        // for(int i = 1 ; i <= 32 ; i++){
        //     if(n & 1){
        //         count++;
        //     }
        //     n >>= 1;
        // }

        //optimal approach
        while(n != 0){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};