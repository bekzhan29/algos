# Bootfall
First, Tima's strength will be an integer from $1$ to $S$, where $S=\sum a[i]$. If his strength is greater than the sum of the strengths of all other players, then the rounds in which he participates will not be draws, since the team in which Tima will be will win.

Let's check whether the round in which Tima is filming will be a draw. First, $S$ must be even, second, the strength of each team must be $S/2$. Let's write a backpack and check that it is possible to collect the sum $S/2$. If this round is not a draw, then it does not matter what strength Tima chooses, so we can output $0$ and stop the program. Otherwise, we need to understand what strength Tima can choose.

## Subtasks 1-3
Let's create an array $ans[x]$, which stores `true` or `false` depending on whether Tima can choose strength $x$, so that all games are draws. Initially $ans[i]=true$ for all $i$ from $1$ to $S$.

Let's find what strength Tim can choose if player $i$ is filming. Let's use the backpack to calculate what amounts can be collected without player $i$. Let's create a new array $can[x]$, which will store `true` if the game is a draw when Tim's strength is $x$ and player $i$ is filming, and `false` otherwise. Then if the strength of the first team is $x$ and the strength of the second team is $y$. Then Tim should join the weaker team and choose the strength $|y-x|$. Then the round will be a draw. Let's iterate over all possible $x$ that can be collected, then $y=S-x-a[i]$ and set $can[|y-x|]=true$. Now let's update the $ans$ array, if $can[x]=false$, then we need to set $ans[x]=false$. At the end, we will output all the values ​​of $x$ for which $ans[x]=true$.

The running time is $O(N^2S)$, since we need to calculate the knapsack for each round.

## Subtasks 4-5
The solution above can be implemented as a bitset.

The running time is $O(N^2S/64)$.

## Full solution
The knapsack $dp[x]$ will store the number of ways to assemble a team with the strength of $x$ according to some random prime modulo. Let's calculate this knapsack for the round when Tima is filming. Now let's calculate $dp2[x]$ which stores the number of ways to assemble a team with the strength of $x$ when player $i$ is filming. Let's assume that we have already calculated $dp2$ for all numbers from $0$ to $x-1$ and want to calculate for $x$. Then $dp2[x]=dp[x]-dp2[x-a[i]]$. Why is this so? $dp[x]$ stores the ways in which player $i$ is present and in which he is not. How many ways are there to assemble $x$ that contain player $i$? There are exactly $dp2[x-a[i]]$. Now we can assemble a team with strength $x$ if $dp2[x]>0$. Identically to the previous solution, we calculate the $can$ array and update the $ans$ array. There may be cases when $dp2[x]=0$, but we can assemble a team with strength $x$, then we calculate the backpack using 2 different modules.

The running time is $O(NS)$.