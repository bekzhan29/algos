# Simple game
Let's create an array $ans[H]$ that will store the number of intersections for a horizontal line at height $H$. Then to answer the second type of query, we just need to print $ans[H]$.

Let's look at two adjacent elements $h[i]$ and $h[i+1]$. Without loss of generality, assume that $h[i] \le h[i+1]$. Which lines will intersect the segment between $(i, h[i])$ and $(i+1, h[i+1])$? All lines $H$ such that $h[i] \le H \le h[i+1]$. Then add $1$ at positions from $h[i]$ to $h[i+1]$ in the array $ans$. This can be done using a segment tree. Queries of the first type are processed in a similar way.

The running time is $O((N+M)logH+H)$ where $H$ is the maximum value of $h[i]$.