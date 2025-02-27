class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(), people.end());
            int boats = 0;
            // counting boats
            int left = 0;
            int right = people.size() - 1;
            while(left <= right){
                if(people[left] + people[right] <= limit){
                    left++; right--;
                    boats++;
                }
                else{
                    right--;
                    boats++;
                }
            }
            return boats;
        }
    };
    
    // sort then greedy
    // greedy is that send the largest weight paired with the largest small weight that leads to boat weight in limit
    // 2 people at max