class Solution {
    public:
        int minMovesToMakePalindrome(string s) {
            int start = 0, end = s.size() - 1;
            int steps = 0;
            while(start < end){
                if(s[start] == s[end]){
                    start++; end--; continue;
                }
                // find the char ahead
                int i = end - 1;
                while (i > start && s[i] != s[start]) i--;
                if (i == start) {  
                    // Single occurrence case, move it to the center
                    swap(s[start], s[start + 1]);
                    steps++;
                } else {  
                    // Swap until it reaches the end position
                    for (int j = i; j < end; j++) {
                        swap(s[j], s[j + 1]);
                        steps++;
                    }
                    start++;
                    end--;
                }
            }
            return steps;
        }
    };