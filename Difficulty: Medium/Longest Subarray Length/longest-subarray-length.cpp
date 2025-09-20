class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        stack<int>st;
        st.push(arr.size());
        vector<int>right(arr.size());
        for(int i=arr.size()-1; i>=0; i--){
            while(st.top()!=arr.size() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            right[i] = st.top();
            st.push(i);
        }
        vector<int>left(arr.size());
        stack<int>st2;
        st2.push(-1);
        for(int i=0; i<arr.size(); i++){
            while(st2.top()!=-1 && arr[st2.top()]<=arr[i]){
                st2.pop();
            }
            left[i] = st2.top();
            st2.push(i);
        }
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            int temp = arr[i];
            int temp2 = right[i] - left[i];
            if(temp2>temp){
                ans = max(ans,temp2-1);
            }
        }
        return ans;
    }
};
//GFG POTD solution for 20 September