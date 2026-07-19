class Solution {
public:
    vector<int>nums;
    vector<int>ans;
    Solution(vector<int>& nums) {
        this->nums=nums;
        ans=nums;
    }
    
    vector<int> reset() {
        return ans;
    }
    
    vector<int> shuffle() {
        nums = ans;

        for (int i = nums.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(nums[i], nums[j]);
        }

        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */