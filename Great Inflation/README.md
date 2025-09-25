# Task "Great Inflation"

## Problem Statement

The next mission of Grażyna, Janusz, and Stach is to mitigate the effects of hyperinflation that hit Poland at the turn of the 1980s and 1990s.

During that period, the entire economy was shaking at its foundations. Entrepreneurs (then called "privateers") had it particularly hard. The Kronostat crew therefore had to temporarily step away from straightening the timeline and deal with accounting – in its creative version, of course.

Janusz and Stach have the task of finding entrepreneurs in trouble, which is not a particularly difficult challenge. Grażyna, as the brain of the operation and the team's chief accountant, must collect lists of sold goods from entrepreneurs and try to assign individual products to the most favorable tax categories. This way, entrepreneurs will pay lower taxes, which will help them save their businesses.

Example table from Mr. Jaś, a gadget dealer:
| Price | Tax Percentage |
|-------|----------------|
| 1000  | 23             |
| 5000  | 30             |
| 200   | 5              |
| 300   | 18             |
| 2000  | 25             |

Grażyna came to the conclusion that a bit of creativity in this case wouldn't hurt. She believes that the most expensive product, priced at 5000 zł, should not be taxed in its entirety, because its price results from the value of many component parts, and not all of them should be taxed. She decided that the amount of 4000 zł, which is subject to taxation, should be charged the lowest tax rate of 5%. In turn, "for balance," the cheapest product should be taxed at the highest rate – 30%. Grażyna is convinced that the Tax Office should have no objections. And if doubts do arise, she has an unusual solution: send the officials to the Middle Ages for a month, which in her opinion will effectively solve the problem.

Remember that if a given list contains **M** products, it also contains **M** tax rates. These rates do not have to be unique. In calculations, Grażyna must use all **M** values.

Write a program that will calculate the lowest tax value that entrepreneurs can pay.

## Input
The first line of input contains a natural number ***n*** - the number of entrepreneurs who need help. Then ***n*** times you need to take from standard input: ***o*** - the number of operations to perform for a given entrepreneur. Next, we take ***o*** lines in the format: ***a p t*** - add a product priced at ***p*** zł, taxed at ***t***% **or** ***p x*** - change the price of the most expensive product by x (if this operation is not possible - do nothing).

***1 ≤ n ≤ 30,000, 1 ≤ o ≤ 100,000, 1 ≤ p ≤ 100,000, 1 ≤ t ≤ 100, -99,999 ≤ x ≤ 99,999***

## Output
The output should contain n lines with the calculated lowest tax for each entrepreneur expressed in **groszy** (hundredths of zł).

## Example:
### Input:
```
2
10
a 1000 20
a 1200 10
a 900  5
a 1500 30
p 100
a 3000 40
p -200
p -100
a 20 20
a 30 4
8
a 970 20
a 1800 10
a 1900  5
a 150 30
a 2000 40
p -200
a 50 10
a 9000 4
```

### Output:
```
70500
107400
```

**NOTE! The task should be solved by implementing a heap yourself!**
