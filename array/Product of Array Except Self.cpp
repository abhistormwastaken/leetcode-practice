class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> arr(nums.size());
        int prefix=1;
        for(int i=0;i<nums.size();i++){
            arr[i]=prefix;
            prefix*=nums[i];
        }
        prefix=1;
        for(int i=nums.size()-1;i>=0;i--){
            arr[i]*=prefix;
            prefix*=nums[i];
        }
        return arr;
    }
};