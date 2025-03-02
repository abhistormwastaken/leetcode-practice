class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> st;
            int n = asteroids.size();
            for(int i = 0; i < n; i++){
                // asteroid is +ve
                if(asteroids[i] > 0) st.push_back(asteroids[i]);
                // asteroid is -ve
                else{
                    // collision type 1
                    while(!st.empty() && st.back() > 0 && st.back() < -asteroids[i]){
                        st.pop_back();
                    }
                    // collision type 2
                    if(!st.empty() && st.back() == -asteroids[i]){
                        st.pop_back();
                    }
                    // nothing left to collide
                    else if(st.empty() || st.back() < 0){
                        st.push_back(asteroids[i]);
                    }
                }
            }
            return st;
        }
    };