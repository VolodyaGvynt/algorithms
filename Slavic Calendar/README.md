# Task "Slavic Calendar"

## Problem Statement

Grażyna, Janusz, and Stach were sent back in time to help the early Slavs solve a mysterious problem related to their agricultural calendar. They believed that to predict the best days for sowing and harvesting, appropriate calculations should be made based on a set of numbers related to observations of the moon and stars.

According to local elders, numbers that have an even number of unique prime divisors are considered stable and favorable for crops. Among these, however, exactly the k-th largest must be chosen to announce the day for beginning field work according to tradition. If a number meeting the conditions is not found in time, the year may be considered lost, and harvests threatened.

Your task is to help the travelers analyze numerical data and find the appropriate number to save the Slavic harvests.

## Input:
The input contains the number t, indicating the number of data sets. Then for each data set:
* number n, indicating the number of observed numerical values,
* n natural numbers a₁, a₂, ..., aₙ, the values of these numbers,
* number k, indicating the position of the sought value.

***1 ≤ t ≤ 10, 1 ≤ n ≤ 1,000,000, 1 ≤ aᵢ ≤ 1,000,000, 0 ≤ k < n***

## Output:
For each data set, output the k-th value among the favorable ones. If there are fewer than k such numbers, output **BRAK DANYCH** (NO DATA).

## Example:
### Input:
```
2
5
12 15 9 10 6
2
4
8 14 7 18
2
```

### Output:
```
12
BRAK DANYCH
```

**NOTE!** The task should be solved using a selection algorithm.
