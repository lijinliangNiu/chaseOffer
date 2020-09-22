class Solution {
public:
    string reverseWords(string s){
        reverse(s.begin(), s.end());
        int index = 0;
        for(int start = 0; start < s.size(); start++){
            if(s[start] == ' '){ //头空格，不是第一个单词的时候因为start++也保证了有一个
                continue;
            }
            if(index != 0){
                s[index++] = ' ';
            }
            int end = start;//找词尾
            while(end < s.size() && s[end] != ' '){
                s[index++] = s[end++];
            }
            int word_len = end - start;
            reverse(s.begin() + index - word_len, s.begin() + index);
            start = end;
        }
        s.erase(s.begin() + index, s.end());
        return s;
    }
};