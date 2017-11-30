//用两个栈来模拟队列
//入队时直接压进栈s1 时间复杂度O(1)
//出队时如果栈s2为空则将s1逐个抛出压入s2,然后抛出s2栈顶 时间复杂度O(n)
//访问队头和队尾也需要考虑s1或s2栈可能为空的状态 时间复杂度O(n)

#include <cstdio>
#include <queue>
#include <stack>

template<typename  T>
class stack2queue
{
public:
	void push(const T& value);
	void pop();
	T& front();
	T& back();

private:
	std::stack<T> s1;
	std::stack<T> s2;
};

template<typename T>
void stack2queue<T>::push(const T& value)
{
	s1.push(value);
}

template <typename T>
void stack2queue<T>::pop()
{
	if (s2.empty())
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	
	s2.pop();
}

template <typename T>
T& stack2queue<T>::front()
{
	if (s2.empty())
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	return s2.top();
}

template <typename T>
T& stack2queue<T>::back()
{
	if (s1.empty())
	{
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	return s1.top();
}




int main()
{	
	stack2queue<int> s2q;

	for (int i = 0; i < 10; ++i)
	{
		s2q.push(i);
	}

	printf("s2q front is: %d, s2q back is: %d \n", s2q.front(), s2q.back()); // 队头0, 队尾9

	s2q.push(10);

	printf("s2q front is: %d, s2q back is: %d \n", s2q.front(), s2q.back()); // 队头0, 队尾10

	s2q.pop();
	
	printf("s2q front is: %d, s2q back is: %d \n", s2q.front(), s2q.back()); // 队头1, 队尾10

	getchar();
    return 0;
}