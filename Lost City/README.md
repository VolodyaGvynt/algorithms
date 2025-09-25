# Task "Lost City"

## Problem Statement

Janusz, Grażyna, and Stach landed in the ruins of an ancient city lost in time. This city is divided into sectors of dimensions n×n, and in each sector there may be a valuable artifact or nothing of value.

The travelers don't have time to visit all sectors, but they would like to collect as many artifacts as possible. They begin exploration in the northwest corner of the city. Moving one sector to the right or south, they reach the southeast corner. Then they return, moving north or west, to reach the starting point. The return route may overlap partially or completely with the one-way route, however no artifact can be taken twice.

## Input:
The input contains a natural number n – the size of the city. Then in the next n rows, n values (0 or 1) are given, indicating the absence or presence of an artifact in a given sector.

**1 ≤ n ≤ 500**

## Output:
The output should give the maximum number of artifacts that can be collected by exploring the city according to the described rules.

**NOTE!** The task should use dynamic programming.

## Example:
### Input:
```
4
1 0 1 0
1 1 0 0
0 0 0 1
1 0 0 1
```

### Output:
```
6
```
