//用两个栈来模拟队列
//入队时直接压进栈push_stack 时间复杂度O(1)
//出队时如果栈pop_stack为空则将push_stack逐个抛出压入pop_stack,然后抛出pop_stack栈顶 时间复杂度O(n)
//访问队头和队尾也需要考虑push_stack或pop_stack栈可能为空的状态 时间复杂度O(n)

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
	std::stack<T> push_stack;
	std::stack<T> pop_stack;
};

template<typename T>
void stack2queue<T>::push(const T& value)
{
	push_stack.push(value);
}

template <typename T>
void stack2queue<T>::pop()
{
	if (pop_stack.empty())
	{
		while (!push_stack.empty())
		{
			pop_stack.push(push_stack.top());
			push_stack.pop();
		}
	}
	
	pop_stack.pop();
}

template <typename T>
T& stack2queue<T>::front()
{
	if (pop_stack.empty())
	{
		while (!push_stack.empty())
		{
			pop_stack.push(push_stack.top());
			push_stack.pop();
		}
	}
	return pop_stack.top();
}

template <typename T>
T& stack2queue<T>::back()
{
	if (push_stack.empty())
	{
		while (!pop_stack.empty())
		{
			push_stack.push(pop_stack.top());
			pop_stack.pop();
		}
	}
	return push_stack.top();
}

int main()
{	
	stack2queue<int> queue_entity;

	for (int i = 0; i < 10; ++i)
	{
		queue_entity.push(i);
	}

	printf("queue_entity front is: %d, queue_entity back is: %d \n", queue_entity.front(), queue_entity.back()); // 队头0, 队尾9

	queue_entity.push(10);

	printf("queue_entity front is: %d, queue_entity back is: %d \n", queue_entity.front(), queue_entity.back()); // 队头0, 队尾10

	queue_entity.pop();
	
	printf("queue_entity front is: %d, queue_entity back is: %d \n", queue_entity.front(), queue_entity.back()); // 队头1, 队尾10

	getchar();
    return 0;
}