class Solution {
    public:
        int twoCitySchedCost(vector<vector<int>>& costs) {
            sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
                return (a[1] - a[0]) < (b[1] - b[0]);
            });
    
            int n = costs.size() / 2;
            int res = 0;
    
            // First half goes to city B, second half goes to city A
            for (int i = 0; i < costs.size(); i++) {
                if (i < n) {
                    res += costs[i][1];  // Assign to city B
                } else {
                    res += costs[i][0];  // Assign to city A
                }
            }
            return res;
        }
    };