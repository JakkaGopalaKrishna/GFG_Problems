class Solution:
    def searchInsertK(self, arr, k):
        # code here
        for i,val in enumerate(arr):
            if val>=k:
                return i
        return len(arr)
        