class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;	// 负数直接返回false
		
        int sum = 0;
        int temp = x;
        while(temp>0)			// 采用了第7题反转整数的操作，先翻转x,再判断相等
        {
            sum = sum*10+temp%10;
            temp = temp/10;
        }
        return (x==sum);
    }
};