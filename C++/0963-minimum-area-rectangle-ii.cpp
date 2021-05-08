// Tags: Math Geometry Google
// Time: O(n^3)
// Space: O(n^2)
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double res = numeric_limits<double>::max();
        // key: diagonal represented by center point and length
        // value: vector of (pairs of indices to vertices) for each diagonal
        unordered_map<string, vector<pair<size_t, size_t>>> diag_to_vert;
        if (n < 4)
            return 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double len_sq = (double)(points[i][0] - points[j][0])*(points[i][0] - points[j][0]) +
                    (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
                double centerX = (double)(points[i][0] + points[j][0]) / 2;
                double centerY = (double)(points[i][1] + points[j][1]) / 2;
                string diag = to_string(len_sq) + "+" + to_string(centerX) + "+" + to_string(centerY);
                diag_to_vert[diag].push_back({i, j});
            }
        }
        for (auto kvp : diag_to_vert) {
            // need atleast two pairs to form atleast one rectangle
            if (kvp.second.size() < 2)
                continue;
            const vector<pair<size_t, size_t>>& vert_pairs = kvp.second;
            for (int p1 = 0; p1 < vert_pairs.size(); ++p1) { // index to pair 1
                for (int p2 = p1 + 1; p2 < vert_pairs.size(); ++p2) { // index to pair 2
                    size_t i = vert_pairs[p1].first;
                    size_t j = vert_pairs[p2].first;
                    size_t k = vert_pairs[p2].second;
                    double len1 = sqrt((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
                                       (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])); 
                    double len2 = sqrt((points[i][0] - points[k][0]) * (points[i][0] - points[k][0]) +
                                       (points[i][1] - points[k][1]) * (points[i][1] - points[k][1]));
                    double area = len1 * len2; 
                    res = min(res, area);
                }
            }
        }
        return res == numeric_limits<double>::max() ? 0.0 : res;
    }
};
/*
We know that two diagonals of a rectangle bisect each other, and are of equal length.

So the pairs of points that form diagonals of same length and same center point
can form a rectangle among themselves.

i -------> j
|
|
|
^
k

*/
