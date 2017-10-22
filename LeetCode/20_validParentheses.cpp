// 检测括号匹配，用stack解决
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(':
                case '{':
                case '[': paren.push(s[i]); break;
				//检测到右括号')','}',']'时，必须要能够从栈中抛出匹配的左括号
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; 
            }
        }
        return paren.empty() ;
    }
};