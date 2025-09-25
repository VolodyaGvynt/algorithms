# Task "Spice Garden"

## Problem Statement

Janusz, Stach, and Grażyna were sent to the year 1574, when the great welcoming feast for Henry of Valois was taking place. According to Kronostat data, during the feast there was a culinary catastrophe - the royal palace spice garden was poorly planned, which caused some spices to grow in hard-to-reach places, making harvesting extremely costly. However, according to historical records, such a catastrophe never took place. Kronostat identified a serious temporal anomaly that disrupted the original garden design, changing its layout into a complicated, chaotic spice labyrinth. The travelers were therefore tasked with redesigning the garden so that the cost of harvesting spices for royal dishes would be as low as possible.

The spice garden is divided into plots arranged in a square grid with marked paths between them. The plots are numbered along horizontal (rows) and vertical (columns) paths from 0 to n-1.

In each horizontal path (row) and vertical path (column), a spice can only be assigned to one plot. This means that exactly one plot can be selected in a given row and exactly one plot in a given column. This is because, according to the calculations of the royal astrologer, master Horacjusz Ziółkowski, spices from one path cannot grow on more than one plot. Otherwise, this threatens acidification of the atmosphere, excess basil power, and spontaneous combustion of oregano. Each plot has an assigned cost for harvesting spices. When assigning plots, one must only remember that the planting plan had to comply with the royal decree, which orders to start planting from the lowest numbered paths where possible.

## Input
The program will receive a positive number **1 ≤ n ≤ 35**, indicating the number of paths and plots in the garden. In the next **n** rows there will be a sequence of **n** natural numbers, indicating the cost of harvesting spice from a given plot. The cost on individual plots does not exceed 1000.

## Output
The program must output **n** numbers, where each indicates the number of the path along which a spice should be planted on a given plot. Paths and plots are numbered from 0.

**NOTE!** You cannot use STL libraries in this task. The task should be implemented using the backtracking search method.

## Example
### Input:
```
4
5 3 2 2
1 2 3 3
2 1 8 7
3 5 3 2
```

### Output:
```
1 2 0 3
```
