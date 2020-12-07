// Tags: Amazon Pattern
// Time: O(2 ^ n), where n is the number of cells (not days).
// for 8 cells, we can have 64 different states.
// (each cell can have two states, therefore 2^n)
// Space: O(n). We need to remember a single state of all cells for the loop detection.
// for 8 cells, the complexity is O(1).
// Preferred solution
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> first_c, next_c(cells.size());

        // predecrement (start of loop) for N because it denotes how many iterations are left
        // postincrement (end of loop) for cycle as it denotes how many iterations are done 
        // (including current)
        for (int cycle = 0; N-- > 0; ++cycle, cells = next_c) {
            for (int i = 1; i < cells.size() - 1; ++i)
                next_c[i] = cells[i - 1] == cells[i + 1];
            if (cycle == 0)
                first_c = next_c;
            else if (next_c == first_c)
                N %= cycle;
        }
        return cells;
    }
};



class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> first_c, next_c(cells.size());

        for (int cycle = 0; N > 0; ++cycle, --N, cells = next_c) {
            for (int i = 1; i < cells.size() - 1; ++i)
                next_c[i] = cells[i - 1] == cells[i + 1];
            if (cycle == 0)
                first_c = next_c;
            else if (next_c == first_c)
                N = ((--N) % cycle) + 1;
        }
        return cells;
    }
};
