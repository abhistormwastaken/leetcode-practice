// O(n), O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxSupport(n, 0);
        int leftMaxSupport = 0;
        int rightMaxSupport = 0;
        int ans = 0;
        // traverse from from the left
        for(int i = 0; i < n; i++){
            if(leftMaxSupport < height[i]){
                leftMaxSupport = height[i];
            }
            maxSupport[i] = leftMaxSupport;
        }

        // traverse from the right
        for(int i = n - 1; i >= 0; i--){
            if(rightMaxSupport < height[i]){
                rightMaxSupport = height[i];
            }
            maxSupport[i] = min(maxSupport[i], rightMaxSupport);
        }
        for(int i = 0; i < n; i++){
            ans += maxSupport[i] - height[i];
        }
        return ans;
    }
};

// O(n), O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] >= leftMax) leftMax = height[l];
                else ans += leftMax - height[l];
                l++;
            }
            else{
                if(height[r] >= rightMax) rightMax = height[r];
                else ans += rightMax - height[r];
                r--;
            }
        }
        
        return ans;
    }
};