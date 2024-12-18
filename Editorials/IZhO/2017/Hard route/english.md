# Hardest Route

## Subtasks 1-2
First, let's learn how to calculate the maximum hardness of a route. Suppose we have found such $A$ and $B$ with the maximum hardness. Now assume that city $C$ is located at the maximum distance to the path between $A$ and $B$. Let us denote $P$ as the city located on the path $(A, B)$ that is closest to $C$. Define a function $dist(u, v)$ that returns the distance between cities $u$ and $v$. Now, if $da=dist(A,P)$, $db=dist(B,P)$, and $dc=dist(C,P)$, then the hardness of the path will equal $dc * (da + db)$. Moreover, the result will be maximized if and only if $dc \geq \max(da, db)$.

Now we can iterate over the vertex $P$ and perform a `dfs` from $P$. For each vertex, calculate $dp[v]$ - the maximum distance from $v$ to a leaf in its subtree. Find the subtree of $P$ with the maximum $dp[v]$ value and call it $p\_c$, while the second and third maximum subtrees are named $p\_b$ and $p\_a$. Compute the maximum hardness across all $P$.

To calculate the number of such paths, we need to define a counter $cnt[v]$ which equals the number of leaves in the subtree of $v$ at distance $dp[v]$. Suppose $da=dp[p\_a]$, $db=dp[p\_b]$, and $dc=dp[p\_c]$. The task then splits into four cases:
1. $dc > db > da$
2. $dc \geq db > da$
3. $dc > db \geq da$
4. $dc \geq db \geq da$

Consider the fourth case; the other cases are solved similarly. Define a variable $sum$ and traverse the subtrees of $P$. If $dp[v] == dc$ and $dc \cdot (da + db)$ is equal to the maximum answer, add $sum * cnt[v]$ to the answer, then update $sum += cnt[v]$.

The runtime is $O(N^2 \log N)$ or $O(N^2)$ if you don't sort the children of $P$.

## Full Solution
We need to optimize the solution above. Calculate the answer when $P=1$ and learn to quickly re-hang $P$. When $P$ transitions to a child of vertex $1$, the values of $dp[v]$ and $cnt[v]$ have already been correctly calculated for the children of $P$. It is necessary to determine the maximum distance from the ancestor of $P$ to a leaf and the number of such leaves. This value can be propagated via a `dfs` from the ancestor.

The runtime is $O(N \log N)$ or $O(N)$ if you don't sort the children of $P$.