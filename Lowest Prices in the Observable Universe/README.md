\# Task "Lowest Prices in the Observable Universe"



\## Problem Statement



Thanks to Grażyna's meticulous planning, the Paradox Safe used half as much energy as last month, when Janusz was handling the deposition of items. This allowed them to avoid high energy bills from PGE (Panagalactic Energy Group).



However, our crew couldn't enjoy the saved funds for long. Janusz, while replacing a seal under the engine head in the time vehicle, damaged the radiator filled with liquid nitrogen (according to Murphy's law "If something can go wrong, it will go wrong"). Instead of spending time pleasantly watching his favorite sport - extreme ironing, he had to go to one of the nearby "Reptilianka" chain stores. In this store you can get practically everything: from desert worm steaks to replacement parts for diesel engine vehicles. The only drawback of this discount store is the queues, whose length is measured in light-years. This is all because the store owner hired gray aliens to work at the checkout last month, who having only three fingers are unable to scan as many products as the insectoids with dozens of pairs of legs from competing chains. Seeing the scale of the problem, Janusz went to the store manager and proposed that for a sufficiently large discount on purchases, he would help him shorten customer waiting times by developing a system for automatic queue management.



The program's task will be to direct customers to the least crowded checkouts. The program should simulate the store's operation for a specified time counted in seconds and display the state of each checkout (number of people in queue and estimated waiting time in queue) after this time has elapsed.



The same checkouts can be opened and closed multiple times during the simulation. When a checkout is opened, the waiting time and number of people in queue is 0. Checkouts where the waiting time in queue (not the number of people - because it's possible that one person shopped for the entire year and the service time for such a person is higher than 10 standard customers) is shortest should be detected by the system, and new people should be directed to such checkouts. We don't consider situations known from supermarkets, where information about a checkout that will be opened soon is announced over the megaphone and customers can form queues at a not-yet-open checkout. Additionally, we assume that sequential closing and opening of the same checkout in the store does not occur. In our program, when a checkout is to be closed, the cashier serves only the first person from the queue (for simplicity, we assume that such a person is served immediately, since aliens have the ability to bend spacetime). The remaining people, starting from the second person, should be directed to other checkouts in the same way as described for new customers.



We assume that at least one checkout must exist in the store at any moment. In case two checkouts have the same waiting time - the system chooses the checkout with the smaller number (id).



\## Input



The first line of input contains four natural numbers: t - store operation time subject to simulation counted in seconds; l - number of checkouts in the store; s - checkout efficiency, i.e., the number of seconds needed to scan a product by the cashier; z - time a customer needs to make payment. In subsequent lines there will be numbers/symbols describing events, of which we distinguish 3 types: o - opening a checkout, z - closing a checkout, k - appearance of a new customer waiting for service. Each line starts with a single-character flag: f - indicating the type of event (o,z,k - as described earlier). When f == 'k', the next two parameters are: p - relative time in seconds counted from the start of simulation for the first customer, and for remaining customers - time from the appearance of the previous customer (there is a guarantee that the sum of all relative times in input data pi will be greater than or equal to t); r - number of products in the customer's basket. When f == 'o' or f == 'z', the next parameter after the flag is a - checkout number.



1 ≤ t ≤ 30,000  

1 ≤ l ≤ 30  

1 ≤ s ≤ 60  

1 ≤ z ≤ 360  

0 ≤ p ≤ 10,000  

f ∈ ('o','z','k')  

0 ≤ a ≤ l - 1  

1 ≤ r ≤ 100  



\## Output



The output should contain the state of each checkout after time t has elapsed, written in the form:

K\[checkout\_number]: \[number\_of\_people\_in\_queue]o, \[queue\_length\_in\_seconds]s - if the checkout is open or

K\[checkout\_number]: z - when the checkout is closed.



Information about checkouts should be displayed in one line and should be separated by commas.



\*\*NOTE! You cannot use STL libraries in this task. You must use a self-written queue implementation.\*\*



\## Example:

\### Input:

```

30 5 5 5

o 2

o 1

k 0 8

k 1 7

k 1 10

k 0 5

k 0 4

o 4

k 10 8

k 0 5

k 10 6

z 1

k 7 7

k 0 5

k 8 4

```



\### Output:

```

K0: z, K1: z, K2: 4o 136s, K3: z, K4: 5o 147s

```



\### Program Operation Schema:

```

Event       | Checkout States (waiting times in seconds)

&nbsp;           | K0    | K1        | K2        | K3  | K4

------------|-------|-----------|-----------|-----|-------------

30 5 5 5    | x     | x         | x         | x   | x

o 2         | x     | x         | 0         | x   | x

o 1         | x     | 0         | 0         | x   | x

k 0 8       | x     | 45        | 0         | x   | x

k 1 7       | x     | 44        | 40        | x   | x

k 1 10      | x     | 43        | 39,55     | x   | x

k 0 5       | x     | 43,30     | 39,55     | x   | x

k 0 4       | x     | 43,30,25  | 39,55     | x   | x

o 4         | x     | 43,30,25  | 39,55     | x   | 0

k 10 8      | x     | 33,30,25  | 29,55     | x   | 45

k 0 5       | x     | 33,30,25  | 29,55     | x   | 45,30

k 10 6      | x     | 23,30,25  | 19,55     | x   | 35,30,35

z 1         | x     | CLOSED    | 19,55,30  | x   | 35,30,35,25

k 7 7       | x     | CLOSED    | 12,55,30,40| x   | 28,30,35,25

k 0 5       | x     | CLOSED    | 12,55,30,40| x   | 28,30,35,25,30

k 8 4       | x     | CLOSED    | 11,55,30,40| x   | 27,30,35,25,30

------------|-------|-----------|-----------|-----|-------------

Final State | z     | z         | 4o 136s   | z   | 5o 147s

```





