class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1)
            return s;
        auto expand_from_center = [&](int left,int right){
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            return s.substr(left+1,right-left-1);
        };
        string max_str = s.substr(0,1);
        for(int i=0;i<n-1;i++){
            string odd_str = expand_from_center(i,i);
            string even_str = expand_from_center(i,i+1);
            if(odd_str.length()>max_str.length())
                max_str = odd_str;
            if(even_str.length()>max_str.length())
                max_str = even_str;
        }
        return max_str;
    }
};
