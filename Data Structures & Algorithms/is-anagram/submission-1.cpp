class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> chara(26,0);
        for(int i=0;i<s.length();i++){
            chara[s[i]-'a']++;
            chara[t[i]-'a']--;
        }
        for(int val: chara){
            if(val!=0) return false;
        }
        return true;
    }
};
