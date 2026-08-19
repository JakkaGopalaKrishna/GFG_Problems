class Solution {
  public:
  int solve(vector<int>&arr,int k){
           int n = arr.size();
        int ans=0;
    for(int i=0;i<n;i++){
        int x=i+1;
        int y=n-1;
        while(x<y && x<n && y>=0){
            int sum = arr[i]+arr[x]+arr[y];
            if(sum<=k){
                ans+=(y-x);
                x++;
            }
            else{
                y--;
            }
        }
    }
    return ans;
  }
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        sort(arr.begin(),arr.end());
         return solve(arr,r)-solve(arr,l-1);
    }
};
//GFG POTD solution for 19 August