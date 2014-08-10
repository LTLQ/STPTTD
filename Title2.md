This method of construction reveals that $F_N$ can be obtained in a simple way from $F_{N-1}$; We simply insert the fraction $(m+m')/N$ between consecutive fractions $m/n$, $m'/n'$ of $F_{N-1}$ whose denominators sum to N. For example, it's easy to obtain $F_7$ from the elements of $F_6$, by inserting $\frac{1}{7},\frac{2}{7},\cdots , \frac{6}{7}$ to the state rule:
<small>
$$
F_7=\frac{0}{1},\frac{1}{7},\frac{1}{6},\frac{1}{5},\frac{1}{4},\frac{2}{7},\frac{1}{3},\frac{2}{5},\frac{3}{7},\frac{1}{2},\frac{4}{7},\frac{3}{5},\frac{2}{3},\frac{5}{7},\frac{3}{4},\frac{4}{5}\frac{5}{6},\frac{6}{7},\frac{1}{1}.
$$
</small>

When N is prime, N-1 new fractions will appear; but otherwise we'll have fewer than N - 1, because this process generates only numerators that are relatively primes to N.
We can, in fact, regard the Stern-Brocot tree as a <em>number system</em> for representing rational numbers, because each positive, reduced fraction occurs exactly once. Let's use the letters L and R to stand for going down to the fraction; then a string of L's and R's uniquely identifies a place in the tree. For example, LRRL means that we fo left from $\frac{1}{1}$ down to $\frac{1}{2}$, then right to $\frac{2}{3}$, then right to $\frac{3}{4}$, then left to $\frac{5}{7}$. We can consider LRRL to be a representation of $\frac{5}{7}$. Every positive fraction gets represented in this way as a unique string of L's and R's.

Well, actually there's a slught problem: The fraction $\frac{1}{1}$ corresponds to the empty string, and we need a notation for that. Let's agree to call it I, because that looks something like 1 and it stands for "identity".
