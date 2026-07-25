class Solution {
public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        vector<vector<int>> prefix(n, vector<int>(n, 0));

        // Build prefix sum matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] = mat[i][j];

                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }

        int ans = INT_MIN;

        // Find maximum k x k submatrix sum
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                int r = i + k - 1;
                int c = j + k - 1;

                int sum = prefix[r][c];

                if (i > 0)
                    sum -= prefix[i - 1][c];
                if (j > 0)
                    sum -= prefix[r][j - 1];
                if (i > 0 && j > 0)
                    sum += prefix[i - 1][j - 1];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};