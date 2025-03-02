// ----------- Without Stack
class Solution {
    public:
        int longestValidParentheses(string s) {
            // without extra space
    
            int left = 0;
            int right = 0;
            int maxCount = 0;
    
            // first left to right scanning
            for(int i=0; i<s.length(); i++){
                if(s[i] == '(') left++;
                else right ++;
    
                if(left == right) maxCount = max(maxCount, 2*left);
                else if(right > left) left = right =  0;
            }
    
            // for right to left scanning
            left = right = 0;
            for(int i=s.length()-1; i>=0; i--){
                if(s[i] == ')') right++;
                else left++;
    
                if(left == right) maxCount = max(maxCount, 2*left);
                else if(left > right) left = right = 0;
            }
            return maxCount;
        }
    };

// -------------- With Stack