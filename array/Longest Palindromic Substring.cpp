class Solution {
    public:
        string longestPalindrome(string s) {
            int start = 0, end = 0;
            for(int i = 0; i < s.size(); i++){
                int odd = expandAroundCenter(s, i, i);
                int even = expandAroundCenter(s, i, i + 1);
                int len = max(odd, even);
                // update the start and end indices of the longest palindromic substring found so far
                if(len > end - start){ // updating even on equality i.e. end - start + 1
                    start = i - (len - 1) / 2; // since i leans towards the left
                    end = i + len / 2; // since i leans towards the left
                }
            }
            return s.substr(start, end - start + 1);
        }
    
        int expandAroundCenter(string s, int left, int right){
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                left--; right++;
            }
            return right - left - 1;
        }
    };