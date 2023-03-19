template <typename Type>
struct heap
{
	// https://github.com/bekzhan29/algos
private:
	int n;
	vector<Type> a;

public:
	heap()
	{
		n = 0;
		a.resize(1);
	}
	void push(Type x)
	{
		int pos = ++n;
		a.push_back(x);
		while (pos > 1)
		{
			if (a[pos] >= a[pos / 2])
				return;
			swap(a[pos], a[pos / 2]);
			pos /= 2;
		}
	}
	int size()
	{
		return n;
	}
	bool empty()
	{
		return n==0;
	}
	Type top()
	{
		return a[1];
	}
	Type pop()
	{
		assert(n > 0);
		Type ans = top();
		swap(a[1], a[n]);
		n--;
		a.pop_back();
		int pos = 1;
		while (true)
		{
			int to = pos;
			if (pos * 2 <= n && a[pos] > a[pos * 2])
				to = pos * 2;
			if (pos * 2 + 1 <= n && a[to] > a[pos * 2 + 1])
				to = pos * 2 + 1;
			if (pos == to)
				break;
			swap(a[pos], a[to]);
			pos = to;
		}
		return ans;
	}
};