// Time:  O(n)
// Space: O(n)
// Elegant solution
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (auto a: asteroids) {
            // Every eligible incoming a either ultimately gets destroyed
            // or remains only element in the stack (destroying others).
            // Non-eligible a's are just pushed into the stack (never destroyed).
            bool destroyed = false;
            while (!st.empty() && st.back() > 0 && a < 0 && !destroyed) {
                // don't put a into stack
                if (st.back() >= -a)
                    destroyed = true;
                
                // pop previous elements
                if (st.back() <= -a)
                    st.pop_back();
            }
            
            if (!destroyed)
                st.push_back(a);
        }
        return st;
    }
};



// First attempt
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st {asteroids[0]};
        for (size_t i = 1; i < asteroids.size(); ++i) {
            st.push_back(asteroids[i]);
            while (st.size() > 1 && st.end()[-1] < 0 && st.end()[-2] > 0) {
                int a = st.back(); st.pop_back();
                int b = st.back();
                if (abs(a) == abs(b))
                    st.pop_back();
                else
                    st.back() = abs(a) > abs(b) ? a : b;
            }
        }
        return st;
    }
};
