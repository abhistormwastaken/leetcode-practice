class Solution{
public:
    bool validWordAbbreviation(string word, string abbr){
        int n = word.size(), m = abbr.size();
        int word_ptr = 0, abbr_ptr = 0;
        while(word_ptr < n && abbr_ptr < m){
            if(isdigit(abbr[abbr_ptr])){
                if(abbr[abbr_ptr] == 0) return false;

                int steps = 0;
                while(abbr_ptr < m && isdigit(abbr[abbr_ptr])){
                    steps = steps * 10 + (abbr[abbr_ptr] - '0');
                    abbr_ptr++;
                }
                word_ptr += steps;
            }
            else{
                if(word[word_ptr] != abbr[abbr_ptr]){
                    return false;
                }
                word_ptr++; abbr_ptr++;
            }
        }
        return word_ptr == n && abbr_ptr == m;
    }
}

// abbreviations in abbr cannot start with 0