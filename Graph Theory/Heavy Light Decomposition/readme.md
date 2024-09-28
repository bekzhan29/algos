Heavy-Light Decomposition
1. $a[x]$ = $y$ $O(logN)$.
2. $max(u,v)$ $O(log^2(N))$.

<details>
<summary>Пример использования <code>node_hld.cpp</code></summary>

```cpp
hld<int> h;
// Инициализировать для h все нужные массивы длины n
h.init(n);
// Добавить ребро между вершиной 1 и 2
h.add_edge(1, 2);
// Построить структуру по массиву a
h.build(a);
// Обновить вес вершины 1 на 5
h.upd(1, 5);
// Вывести максимальный вес вершины на пути от 1 до n
cout << h.get(1, n);
```
</details>

[Задача](https://atcoder.jp/contests/abc294/tasks/abc294_g)
