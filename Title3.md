This representation raises two natural questions: (1) Given positive integers m and n with $m\bot n$, what is the string of L's and R's that corresponds to $m/n$? (2) Given a string of L's ans R's, what  fraction corresponds to it? Question 2 seems easier, so let's work on it first. We define
$$
f(S)=fraction corresponding to S
$$
When S is a string of L's ans R's. For example, $f(LRRL)=\frac{5}{7}$.

According to the construction, $f(S)=(m+m')/(n+n')$ if $m/n$ and $m'/n'$ are the closest fractions preceding and following S in the upper levels of the tree. Initially $m/n=0/1$ and $m'/n'=1/0$; then we successively replace either $m/n$ or $m'/n'$ by the mediant $(m'+m)/{n'+n}$ as we move right or left in the tree, respectively.

How can we capture this behavior in mathematical formulas that are easy to deal with? A bit of experimentation suggests that the best way is to maintain a 2X2 matrix
$$
M(S)=\begin{pmatrix} n & n' \\ m & m' \end{pmatrix}
$$
that holds the four quantities involved in the ancestral fractions $m/n$ and $m'/n'$ enclosing f(S). We could put the m's on top and the n's on the bottom, fractionwise; but upside-down arrangedment works out more nicely because we have $M(1)=\begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}$ when the process starts, and $\begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}$ is traditionally called the identity matrix I.

A step to the left replace n' by n+n' and m' by m+m'; hence
$$
M(SL)=\begin{pmatrix} n & n+n' \\ m & m+m' \end{pmatrix}=\begin{pmatrix} n & n' \\ m & m' \end{pmatrix}\begin{pmatrix} 1 & 1 \\ 0 & 1 \end{pmatrix}=M(S)\begin{pmatrix} 1 & 1 \\ 0 & 1 \end{pmatrix}.
$$
Simularly it turns out that
$$
M(SR)=\begin{pmatrix} n+n' & n' \\ m+m' & m' \end{pmatrix}=M(S)\begin{pmatrix} 1 & 0 \\ 1 & 1 \end{pmatrix}
$$
Therefore if we define L and R as $2\times 2$ matrices,
$$
L=\begin{pmatrix} 1 & 1 \\ 0 & 1 \end{pmatrix},\qquad R=\begin{pmatrix} 1 & 0 \\ 1 & 1 \end{pmatrix}.
$$
we get the simple formula $M(S)=S$, by induction on the length of S. Isn't that nice? For example,
$$
M(LRRL)=LRRL=\begin{pmatrix} 1 & 1 \\ 0 & 1 \end{pmatrix}\begin{pmatrix} 1 & 0 \\ 1 & 1 \end{pmatrix}\begin{pmatrix} 1 & 0 \\ 1 & 1 \end{pmatrix}\begin{pmatrix} 1 & 1 \\ 0 & 1 \end{pmatrix}=\begin{pmatrix} 3 & 4 \\ 2 & 3 \end{pmatrix};
$$
the ancestral fractions that enclose LRRL = $\frac{5}{7}$ are $\frac{2}{3}$ and $\frac{3}{4}$. And this construction gives  us the answer to Question 2:
$$
f(S)=f\left(\begin{pmatrix} n & n' \\ m & m' \end{pmatrix}\right) = \frac{m+m'}{n+n'}.
$$