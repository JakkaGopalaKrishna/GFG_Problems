class Solution {
  public:
    int transform(string &s1, string &s2) {
   int n = s1.size();

   if (n != s2.size())
       return -1;

   // Check whether both strings contain the same characters
   vector<int> freq(256, 0);

   for (char c : s1)
       freq[c]++;

   for (char c : s2)
       freq[c]--;

   for (int x : freq) {
       if (x != 0)
           return -1;
   }

   // Find longest suffix of s2
   // which is a subsequence of s1
   int i = n - 1;
   int j = n - 1;

   while (i >= 0 && j >= 0) {
       if (s1[i] == s2[j]) {
           j--;
       }
       i--;
   }

   // s2[0 ... j] are the characters that need to be moved
   return j + 1;

    }
};

//GFG POTD solution for 21 August