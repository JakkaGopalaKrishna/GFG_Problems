class Solution:
	def pushZerosToEnd(self, arr):
    	# code here
    	lis=[]
    	c=0
    	for i in arr:
    	   if i ==0:
    	        c+=1
    	   else:
    	        lis.append(i)
    	arr[:]=lis+[0]*c