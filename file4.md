How about Question 1? That's easy, now that we understand the fundamental connection between tree nodes and $2\times 2$ matrices. Given a pair of positive integers m and n with $m\bot n$, we can find the position of $m/n$ in the Stern-Brocot tree by "binary search" as follows:
```
S := 1
while m / n != f(S) do
    if m/n < f(S) then (output(L); S := SL)
                  else (output(R); S := SR).
```
This outputs the desired strng of L's and R's.

There's also another way to do the same job, by changing m and n instead of maintaining the state S. If S is any $2\times 2$ matrix, we have
$$
f(RS)=f(S)+1
$$
because RS is like S but with the top row added to the bottom row.
$$
S=\begin{pmatrix} n & n' \\ m & m' \end{pmatrix}; \qquad RS=\begin{pmatrix} n & n' \\ m+n & n'+m' \end{pmatrix};
$$
If we carry out the binary search algorithm on a fraction $m/n$ with $m>n$, the first output will be R; hence the subsequent behavior of the algorithm will have f(S) exactly 1 greater than if we had begun with $(m-n)/n$ instead of $m/n$. A similar property holds for L, and we have
$$
\frac{m}{n}=f(RS) \qquad \Leftrightarrow \qquad \frac{m-n}{n}=f(S), when m > n;\\
\frac{m}{n}=f(RS) \qquad \Leftrightarrow \qquad \frac{m}{n-m}=f(S), when m < n.
$$
This means that we can transform the binary search algorithm to the following matrix-free procedure:
```
while m != n do
    if m < n then (output(L); n := n - m)
             else (output(R); m := m - n)
```
For example, given $m/n=5/7$, we have successively 
$$
m=5\quad 5\quad 3\quad 1\quad 1\\
n=7\quad 2\quad 2\quad 2\quad 1\\
output\quad L\quad R\quad R \quad L
$$
in the simplified algorithm.

$$
e=RL^0RLR^2LRL^4RLR^6LRL^8RLR^{10}LRL^{12}RL\cdots;
$$
