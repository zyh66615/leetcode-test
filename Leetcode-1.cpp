class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num = nums.size();
        for (int i =0;i<num;i++)
        {
            for (int j=i+1;j<num;i++)
            {
                if (nums[i] +nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};