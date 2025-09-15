class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int start = pat.size() - 1;
        int end = tar.size() - 1;
        while ( start >= 0 && end >= 0 ) {
            if ( pat[start] == tar[end] ) {
                start--;
                end--;
            } else start -= 2;
        }
        if ( end >= 0 ) return false;
        return true;
    }
};
//GFG POTD solution for 15 September