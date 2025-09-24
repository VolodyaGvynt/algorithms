# Task "Uranium Ore Blending"

## Problem Statement

In the 25th century, the time travelers' organization Kronostat ensures that humanity's future doesn't turn into a complete catastrophe. This time, the threat is serious - without the discovery of radium by Marie Curie and her husband Pierre, future medicine will end up in the dustbin of history. But the problem is simpler than it seems - Marie and Pierre simply won't have time to process tons of uranium ore from which they need to extract radium. It's a classic problem of "too much ore, too little time."

To the rescue comes a trio from Kronostat - Grażyna, Janusz, and Stach, the best agents you can find in the 25th century (or at least the best ones who happened to have time). Their mission? Help Marie and Pierre process tons of this cursed ore before radium disappears forever into the abyss of undiscovered history. Equipped with indispensable organizational, improvisational, and diplomatic skills, our trio of travelers throws themselves into work - though with certain limitations, because they can't change the course of history too much. And they can't use future technology. So yes, they can forget about lasers and robots - they're left with shovels and buckets.

Janusz, being Janusz, first tried to cobble something together with duct tape and a few sticks, but Grażyna quickly brought him down to earth: "No miracles, Janusz, we'll have to dig." Stach, on the other hand, managed to convince some 19th-century peasants to help, but a new problem appeared: people are getting tired. Each day their efficiency drops - on the first day they process C tons of ore, but each subsequent day K tons less. A worker who has lost all their efficiency goes home tired. And time is running out!

The travelers from Kronostat are now asking themselves only one question: will they manage to process the ore before history falls apart? If they fail, they'll have to use the Janusz Effect (the ultimate, desperate solution based on the principle "Janusz will figure something out," even if it means complete improvisation that barely holds together).

## Input:
The input contains the number of test cases t. Each test case consists of three natural numbers: n, d, and m, representing respectively the number of peasants to help, the number of day queries, and the required number of tons of ore. Then you receive n lines, where each line contains two integers: efficiency C and efficiency reduction K for consecutive peasants. The last line of the test case contains d positive numbers representing the number of days.

***1 ≤ t ≤ 10, 1 ≤ n ≤ 1000, 1 ≤ d ≤ 1000000, 1 ≤ m ≤ 10000000, 1 ≤ K ≤ C ≤ 10000***

## Output:
For each test case, for each of the d numbers, display information about the number of tons of ore processed by day d_i, and in the second line the number of queries for which the required number of tons of ore was successfully processed.

## Example:
### Input:
```
2
2 3 100
20 10
30 5 
5 1 100
1 2 15
5 2
1 3
```

### Output:
```
130 50 135 
2
5 9 
0
```

---

## Algorithmic Concepts This Task Exercises:

**Primary Concepts:**
- **Simulation and Mathematical Modeling**: Simulating the work efficiency decline over multiple days
- **Greedy Algorithms**: Optimizing which workers to use and for how long to maximize output
- **Dynamic Programming/Memoization**: Computing cumulative work output efficiently for different time periods
- **Array Processing**: Managing multiple workers with different efficiency parameters

**Secondary Concepts:**
- **Arithmetic Sequences**: Each worker's daily output forms an arithmetic sequence (C, C-K, C-2K, ...)
- **Summation Formulas**: Computing total work done using arithmetic series formulas
- **Query Processing**: Efficiently answering multiple queries about different time periods
- **Optimization**: Determining the optimal strategy for work allocation

**Mathematical Skills:**
- **Series Summation**: Sum of arithmetic sequences
- **Floor Division**: Determining how many full days a worker can contribute
- **Cumulative Calculations**: Building running totals efficiently

This problem combines simulation, optimization, and mathematical computation to test understanding of how to model real-world constraints (decreasing efficiency) in algorithmic solutions.