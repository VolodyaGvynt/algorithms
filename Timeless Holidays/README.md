# Task "Timeless Holidays"

## Problem Statement

The holidays are approaching, and this means that Santa Claus has his hands full. While many people explain his ability to deliver presents to millions of homes in one night through magic, the truth is much simpler and more logical. Santa Claus is simply a time traveler!

This year, things didn't go without problems. At Santa's Factory, there were delays due to chaos in documentation. It turned out that the colorful Christmas chains, which were supposed to be used to decorate the fence around the factory, are too short, which caused disruptions in the elves' work. (In Santa's timeline, elves are not just legend). The ends of the chain must be hooked to the appropriate left and right posts of the fence section. The chain can be shortened, but it cannot be lengthened. To minimize costs, the factory plans to order all chains in one size – long enough to fit every fence section, but not excessively long, which could increase the elves' burden.

The factory fence consists of n posts placed at irregular distances (these posts are, however, relatively evenly distributed within a certain range). This means that fence sections can have different lengths. The documentation recorded the positions of all posts, but they are given in random order. The elves cannot afford mistakes, so they asked Kronostat for help. The task of Grażyna, Janusz, and Stach is to review the documentation and determine the length of the longest fence section. Thanks to this, Santa's Factory will be able to order chains of appropriate length.

## Input
The first line of input contains a natural number n (2 ≤ n ≤ 2,000,000) indicating the number of fence posts. The next line contains n real numbers -10⁹ ≤ pᵢ ≤ 10⁹ — positions of fence posts in random order.

## Output
The output should contain one real number — the length of the longest fence section with precision to 4 decimal places.

## Example
### Input:
```
8
7.6 -2.0 12.0 0.3 9.3 2.0 4.5 5.1
```

### Output:
```
2.7000
```

**Note!** The solution should be based on a linear time sorting algorithm. You cannot use STL.