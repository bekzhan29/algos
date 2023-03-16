Корневая оптимизация умеет делать всё то, что умеет делать дерево отрезков и даже больше. Но время обработки запросов обычно $O(\sqrt{N})$, что хуже чем $O(logN)$.

<details>
<summary><code>sqrt_decomposition1.cpp</code></summary>

1. $a[x]$ += $y$ $O(1)$
2. $sum(l,r)$ $O(\sqrt{N})$
</details>
<details>
<summary><code>sqrt_decomposition2.cpp</code></summary>

1. $upd(l,r)$+=$k$ $O(\sqrt{N})$
2. $sum(l,r)$ $O(\sqrt{N})$
</details>