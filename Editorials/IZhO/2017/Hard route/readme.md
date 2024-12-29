# Крутой маршрут

## Подзадачи 1-2
Для начала научимся считать максимальную крутость маршрута. Предположим что мы нашли такие $A$ и $B$ с максимальной крутостью. Теперь допустим что город $C$ находится на максимальномм расстоянии до пути между $A$ и $B$. Скажем что $P$ это город который находится на пути $(A, B)$ и он ближе всего находится к $C$. Заведем функцию $dist(u, v)$ которая возвращает расстояние между городами $u$ и $v$. Теперь если $da=dist(A,P)$, $db=dist(B,P)$ и $dc=dist(C,P)$ тогда сложность пути будет равна $dc*(da+db)$. Также ответ будет максимальным тогда и только тогда когда $dc>=max(da,db)$.

Теперь мы можем перебрать вершину $P$ и запустить `dfs` из $P$ и для каждой вершины посчитать $dp[v]$ - максимальное расстояние от $v$ до листа в его поддереве. Найдем поддерево $P$ с максимальным значением $dp[v]$ и назовем его $p\_c$, а второй и третий максимальные поддеревья назовем $p\_b$ и $p\_a$. Посчитаем максимальную крутость по всем $P$.

Чтобы посчитать количество нам необходимо завести счетчик $cnt[v]$ который равен количеству листов в поддереве v на расстоянии $dp[v]$. Скажем что $da=dp[p\_a]$, $db=dp[p\_b]$ и $dc=dp[p\_c]$. Теперь задача разбивается на 4 случая:
1. $dc > db > da$
2. $dc \ge db > da$
3. $dc > db \ge da$
4. $dc \ge db \ge da$

Рассмотрим 4й случай, остальные случаи решаются идентично. Заведем переменную $sum$ и будем идти по поддеревьям $P$, если $dp[v]==dc$ и $dc*(da+db)$ является максимальным ответом, то добавим к ответу $sum*cnt[v]$ и затем сделаем $sum+=cnt[v]$.

Время работы $O(N^2logN)$ или $O(N^2)$ если не сортировать сыновей $P$.

## Полное решение
Нужно ускорить решение сверху. Посчитаем ответ когда $P=1$ и научимся быстро переподвешивать $P$. Когда $P$ переходит в сына вершины $1$, то $dp[v]$ и $cnt[v]$ уже были правильно посчитаны для сыновей $P$, надо узнать максимальное расстояние от предка $P$ до листа и количество таких листов. Это значение можно передать через `dfs` из предка.

Время работы $O(NlogN)$ или $O(N)$ если не сортировать сыновей $P$.