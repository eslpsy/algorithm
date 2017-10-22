// �������ƥ�䣬��stack���
class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(':
                case '{':
                case '[': paren.push(s[i]); break;
				//��⵽������')','}',']'ʱ������Ҫ�ܹ���ջ���׳�ƥ���������
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; 
            }
        }
        return paren.empty() ;
    }
};