#include <algorithm>
#include <vector>

const static std::vector<std::vector<int>> KB_ADJ {
    {0, 8},  {1, 2, 4},  {2, 1, 3, 5},  {3, 2, 6},  {4, 1, 5, 7},               // 0..4
    {5, 2, 4, 6, 8},  {6, 3, 5, 7},  {7, 4, 8},  {8, 5, 7, 9, 0},  {9, 6, 8}    // 5..9
};

struct Solution 
{
    int getCount(int n)
    {
        const auto &adj = KB_ADJ;
        std::vector<int> counts(10, 1);
        for (int i=1; i<n; ++i)
        {
            std::vector<int> old_counts {counts};
            for (int j=0; j < 10; ++j) {
                counts[j] = 0;
                for (int k : adj[j]) counts[j] += old_counts[k];
            }
        }
        return std::accumulate(counts.begin(), counts.end(), 0);
    }
};
//GFG POTD solution for 27 June