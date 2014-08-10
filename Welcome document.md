### Stern-Brocot tree
There's a beautiful way to construct the set of all nonegative fractions $m/n$ with $m\bot n$(It means gcd(m,n)=1), called the Stern-Brocot tree because it was discovered independently by Moritz Stern, a German mathematician, and Achillle Brocot, a French clockmacker. The idea is to start with the two fractions $\left( \frac { 0 }{ 1 } ,\frac { 1 }{ 0 }  \right) $ and then to repeat the following operation as many times as desired:
$$
Insert\ \frac { m+m' }{ n+n' }  between\ two\ adjacent\ fractions\ \frac{m}{n} \ and \ \frac{m'}{n'}.
$$

The new fraction $\frac{m+m'}{n+n'}$ is called the mediant of $m/n$ and $m'/n'$. For example, the first step gives us one new entry between $\frac{0}{1}$ and $\frac{1}{0}$,
$$
\frac{0}{1}, \frac{1}{1}, \frac{1}{0};
$$
and The next gives two more:
$$
\frac{0}{1}, \frac{1}{2} , \frac{1}{1}, \frac{2}{1},\frac{1}{0};
$$
The next gices four more,
$$
\frac{0}{1}, \frac{1}{3}, \frac{1}{2}, \frac{2}{3}, \frac{1}{1}, \frac{3}{2}, \frac{2}{1}, \frac{3}{1},\frac{1}{0};
$$
and then we'll get 8, 16, and so on. The entire array can be regarded as an infinite binary tree structure whose top levels look like this:

![---](http://)

Each fraction is $\frac{m+m'}{n+n'}$, Where $\frac{m}{n}$ is the nearest ancestor above and to the left, and $\frac{m'}{n'}$ is the nearest ancestor aboce and to rhe right. Many patterns can be observed in this tree.

Why does this construction work?Why, for example does each mediant fraction $(m+m')/(n+n')$ turn out to be in lowest terms when it appears in this tree?(IF m,m',n,n'were all odd, we'd get even/even; somehow the construction guarantees that fractions with odd numerators and denomiators never appear next to each other.) And why do all possible fraction $m/n$ occur exactly once? Why can't a particular fraction occur twice,or not at all?

All of these questions have amazingly simple answers1, based on the following fundamental fact: If $m/n$ and $m'/n'$ are consecutive factions at any stage of the construction, we have
$$
m'n-mn'=1.
$$
This relations is true initially($1*1-0*0=1$); and when we insert a new mediant $(m+m')/(n+n')$, the new cases that need to be checked are
$$
(m+m')n-m(n+n')=1\\
m'(n+n')-(m+m')=1.
$$
Both of these equation are equivalent to the original condition $m'n-mn'=1$ that they replace. Therefore it is invariant at all stages of the construction.

Furthermore, if $m/n<m'/n'$ and if all values are nonegative, it's easy to verify that
$$
m/n<(m+m')/(n+n')<m'/n'.
$$
A mediant fraction isn't halfway between its progenitors, but it does lie somewhere in between. Therefore the construction preserves order, and we couldn't possibly get the same fraction in two different places.

One question stiil remains. Can any positive fraction $a/b$ with $a\bot b$ possibly be omitted? The answer is no, because we can confine the construction to the immediate neighberhood of $a/b$, and in this region the behavior is easy to analyseA: Initially we have
$$
\frac{m}{n}=\frac{0}{1}<(\frac{a}{b})<\frac{1}{0}=\frac{m'}{n'}
$$
where we put parentheses around $\frac{a}{b}$ to indicate that it's not really present yet. Then if at some stage we have
$$
\frac{m}{n} < (\frac{a}{b}) < \frac{m'}{n'},
$$
the construction forms $(m+m')/(n+n')$ and there are three cases. Either $(m+m')/(n+n')=a/b$ and we win; or $(m+m')/(n+n')<a/b$ and we can set $m\leftarrow m+m', n\leftarrow n+n'$; or $(m+m')/(n+n')>a/b$ and we can set $m'\leftarrow m+m', n'\leftarrow n+n'$. This process cannot go on indefinitely, because the conditions
$$
\frac{a}{b}-\frac{m}{n}>0\qquad and\qquad \frac{m'}{n'}-\frac{a}{b}>0 
$$
imply that 
$$
an-bm\ge 1\qquad and \qquad bm'-an'\ge 1;
$$
hence
$$
(m'+n')(an-bn)+(n+m)(bm'-an')\ge m'+n'+m+n;
$$
and this is the same as $a+b\ge m'+n'+m+n$ by $m'n-mn'=1$. Either m or n or m' or n' invreases at each step, so we must win after at most $a+b$ steps.

The <em>Farey series</em> of order N, denoted by $F_N$, is the set of all reduced fractions between 0 and 1 whose denominators are N or less, arranged in increasing order. For example, if $N=6$ we have
$$
F_6=\frac{0}{1},\frac{1}{6},\frac{1}{5},\frac{1}{4},\frac{1}{3},\frac{2}{5},\frac{1}{2},\frac{3}{5},\frac{2}{3},\frac{3}{4},\frac{4}{5}\frac{5}{6},\frac{1}{1}.
$$
We can obtain obtain $F_N$ in general by starting with $F_1=\frac{0}{1},\frac{1}{1}$ and then insertin mediants whenever it’s possible to do so without gettiing a denominator is > N.
