Дерево отрезков позволяет выполнять следующие запросы  
1. Изменить $a[i]$ += $x$. $O(logN)$
2. Изменить $a[i]$ += $x$ для всех $i$ на отрезке от $l$ до $r$. $O(logN)$
3. Найти сумму на отрезке от $l$ до $r$. $O(logN)$

Построение дерева отрезков занимает $O(N)$ времени

<details>
<summary>Пример использования <code>segment_tree1.cpp</code></summary>

```
segment_tree<int> t;
// Построить дерево отрезков по массиву a длины n
t.build(n, a);
// Добавить k к элементу на позиции x
t.upd(x, k);
// Вывести сумму на отрезке от l до r
cout << t.sum(l, r);
```
</details>

<details>
<summary>Пример использования <code>segment_tree2.cpp</code></summary>

```
segment_tree<int> t;
// Построить дерево отрезков по массиву a длины n
t.build(n, a);
// Добавить k ко всем элементам от l до r
t.upd(l, r, k);
// Вывести сумму на отрезке от l до r
cout << t.sum(l, r);
```
</details>

<details>
<summary>Пример использования <code>segment_tree1.cpp</code></summary>

```
segment_tree<int> t;
// Построить дерево отрезков по массиву a длины n
t.build(n, a);
// Добавить k к элементу на позиции x
t.upd(x, k);
// Вывести сумму на отрезке от l до r
cout << t.sum(l, r);
```
</details>