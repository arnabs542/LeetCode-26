// Tags: Array Google
// Time: O(n), if only 1 subtracted on each iteration
// Space: O(1)
class RLEIterator {
    vector<int> A;
    // current index
    int i;
public:
    RLEIterator(vector<int>& A): A(A), i(0) {
        
    }
    
    int next(int n) {
        // exhaust as many terms as possible with number < n
        while (i < A.size() && A[i] < n) {
            n -= A[i];
            i += 2;
        }
        // for the last iteration.
        if (i < A.size()) {
            A[i] -= n;
            return A[i + 1]; 
        }
        // exhausted all terms but still not enough.
        return -1;
    }
};
