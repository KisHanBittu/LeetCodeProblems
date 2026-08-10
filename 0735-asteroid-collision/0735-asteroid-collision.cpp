class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (auto& a : asteroids) {
            while (!st.empty() && st.back() > 0 && a < 0) {
                int sum = st.back() + a;
                if (sum > 0) {
                    a = 0;
                } else if (sum == 0) {
                    st.pop_back();
                    a = 0;
                } else {
                    st.pop_back();
                }
            }
            if (a != 0) {
                st.push_back(a);
            }
        }

        return st;
    }
};