class Solution {
  public:
    int minMoves(vector<int>& arr) {
        int n=arr.size(), ans=0;
        vector<int>vec(n+1, 0);
        for(int i=0;i<n;i++){
            int val=arr[i];
            if(vec[val-1]!=0)vec[val]=vec[val-1]+1;
            else vec[val]=1;
            ans=max(ans, vec[val]);
        }
        return n-ans;}
};
//GFG POTD solution for 25 August