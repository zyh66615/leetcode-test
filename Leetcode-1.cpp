static int x = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            if(map.find(target-nums[i])!=map.end())
                return vector<int>{map[target-nums[i]],i};
            else
                map[nums[i]]=i;
        }
        return vector<int>{-1,-1};
    }
};