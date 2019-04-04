class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0)
        {
            int size=nums2.size();
            if(nums2.size()%2==1)
            {
                return 1.0*nums2[size/2];
            }else
            {
                return 0.5*(nums2[size/2-1]+nums2[size/2]);
            }
        }
                if(nums2.size()==0)
        {
            int size=nums1.size();
            if(nums1.size()%2==1)
            {
                return 1.0*nums1[size/2];
            }else
            {
                return 0.5*(nums1[size/2-1]+nums1[size/2]);
            }
        }
  vector<int> nums(nums1.size()+nums2.size()); merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums.begin());
        if(nums.size()%2==1)
            return 1.0*nums[nums.size()/2];
        else
        {
            return 0.5*(nums[nums.size()/2-1]+nums[nums.size()/2]);
        }
    }
};