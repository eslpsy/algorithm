#include <assert.h>
#include <cstdio>
#include <list>

int main()
{
	int n;
	int m;
	scanf_s("%d %d", &n, &m);
	assert(m < n);

	std::list<int> l;
	for (int i = 1; i <= n; ++i)
	{
		l.push_back(i);
	}

	auto it = l.begin();
	for (int i = 1; i <= n;)
	{
		if (i == m)
		{
			i = 1;
			it = l.erase(it);
		}
		else
		{
			++i;
			++it;
		}

		// 模拟循环链表
		if (it == l.end())
		{
			it = l.begin();
		}

		// 只剩最后一个节点输出结果
		if (1 == (int)l.size())
		{
			printf("%d", *it);
			break;
		}
	}

	getchar();
	getchar();

	return 0;
}