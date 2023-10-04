class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        int i=0;
        int j=0;
        int index;
        while(i<n && j<m)
        {
            index=i;
            while(haystack[i]==needle[j] && j<m && i<n)
            {
                j++;
                i++;
            }
            if(j==m)
            {
                return index;
            }
             else if(j<m && haystack[i]!=needle[j])
            {
                j=0;
                i=index+1;
            }
        }
        return -1;
    }
};