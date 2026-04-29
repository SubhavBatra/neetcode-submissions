class Solution {
private:
    bool isalNum(char c){
        return (c>='A' and c<='Z' ||
                c>='a' and c<='z' ||
                c>='0' and c<='9' );
    }

public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while(l<r){
            while(l<r and !isalNum(s[l])) l++;
            while(r>l and !isalNum(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++; r--;
        }
        return true;
    }
};
