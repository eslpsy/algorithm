class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;	// ����ֱ�ӷ���false
		
        int sum = 0;
        int temp = x;
        while(temp>0)			// �����˵�7�ⷴת�����Ĳ������ȷ�תx,���ж����
        {
            sum = sum*10+temp%10;
            temp = temp/10;
        }
        return (x==sum);
    }
};