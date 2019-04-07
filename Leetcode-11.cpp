static int x = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
static int x = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return -1;
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            if(height[i] < height[j]) ++i;
            else --j;
        }
        return res;
    }
};