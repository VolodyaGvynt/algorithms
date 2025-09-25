# Task "Janusz's Mission"



## Problem Statement



Janusz messed up again. After returning from an intervention during Bolesław the Brave's coronation, the timeline became unstable – instead of subtly fixing a minor disturbance, Janusz accidentally inspired the Brave to invent electricity centuries before Edison! The effect? In 1025, knights fight with lightsabers, and Mieszko II claims he saw a UFO.



Stach, the eternal temporal theorist, immediately proposed a brilliant solution: "Janusz, maybe try going back to that moment and instead of coming up with such ideas, just wave Bolesław's flag! Who knows, maybe that'll be enough?" Grażyna, the mission leader, nodded, squinting her eyes. "Janusz, the decision is yours, but remember – if you mess up again, you're going back to the Ice Age for a month, on a diet consisting solely of thawed mammoth water. Supposedly not very refreshing."



Janusz must wade through a series of decisions to restabilize the timeline. In this difficult mission, he'll be helped by a somewhat outdated but still functional MOWKiCz system (Monitor of Ultimate Time Edge Alignment), which drops Janusz into a selected stable time point and indicates decisions leading to other points. Janusz must move between points in the timeline and at each one make a decision that leads to the next point. Each transition between points changes the status of the destination point to the opposite of the status of the point Janusz came from – stable becomes unstable and vice versa. The goal is to achieve a situation where the last point in time – the one from which there is no further passage – maintains stability.



MOWKiCz isn't perfect and sometimes stabilization isn't possible. In such cases, Janusz can try to choose the lesser evil: get stuck in a time loop, meaning he'll circle between points endlessly, changing their status. Grażyna calls this a loop. The worse option is a situation where the system no longer gives any chance for stabilization, which means inevitable temporal catastrophe.



Can Janusz achieve system stabilization? Sometimes success seems impossible, but the system allows balancing on the edge of chaos. However, if there's no chance for stability, all that remains for Janusz is to wait for the worst - Grażyna's tirade.



## Input:

The program receives a natural number \*\*t\*\* on input, indicating the number of tests. Then \*\*t\*\* data sets are given. Each set consists of three natural numbers \*\*n\*\*, \*\*m\*\*, and \*\*s\*\* indicating the number of points, the number of connections between them, and the number of the point from which timeline repair begins. In the next \*\*m\*\* lines there are pairs of natural numbers \*\*x\*\* and \*\*y\*\* – which inform that the decision at time point number \*\*x\*\* leads to point number \*\*y\*\*. It should be assumed that the same connections will not appear multiple times nor loops (i.e., connections that start and end at the same point). Points are numbered from 0.



\*\*\*1 ≤ t ≤ 10, 1 ≤ n ≤ 100,000, 0 ≤ m ≤ 2×n, 0 ≤ x,y < n\*\*\*



## Output:



For each test, the program should output \*\*NO\*\* if there's no possibility for Janusz to achieve stabilization, \*\*LOOP\*\* if stabilization cannot be achieved but a loop can be created, or \*\*YES\*\* if Janusz can achieve stabilization. In case of success, the second line of output for the given test should list the numbers of points that should be visited in sequence. The shortest solution should be provided. In case of paths of equal length, the lexicographically first one should be chosen.



## Example:

### Input:

```

3

6 7 3

0 1

1 5

2 0

2 1

3 2

3 4

4 0

4 3 0

0 1

1 2

2 3

2 2 0

0 1

1 0

```



### Output:

```

YES

3 2 0 1 5

NO

LOOP

```





