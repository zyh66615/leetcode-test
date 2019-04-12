static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        int ret = 0;
        int min = INT_MAX;
        for(int i = 0;i < nums.size() - 2; i++){
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(abs(sum - target) < min) {
                    min = abs(sum - target);
                    ret = sum;
                }
                if(sum < target)
                    l++;
                else if(sum > target)
                    r--;
                else 
                    return target;
            }
        }
        return ret;
    }
};