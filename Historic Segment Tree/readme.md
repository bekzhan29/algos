Historic segment tree $O(NlogN)$
1. $a[i]$+=$x$ на отрезке $l,r$
2. $a[i]=max(a[i]-x,0)$ на отрезке $l,r$
3. $a[i]=x$ на отрезке $l,r$
4. Вывести $a[i]$
5. Вывести $b[i]$
<br>
$b[i]$ = максимальное значение $a[i]$ за все время  
[Задача](https://uoj.ac/problem/164)  
[Пост](https://codeforces.com/blog/entry/57319)