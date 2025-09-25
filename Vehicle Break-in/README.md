# Task "Vehicle Break-in"



## Problem Statement



After long hours spent at Reptilianka, Janusz managed to solve the problem of otherworldly queues. For his ingenuity, he got a solid discount, thanks to which he could buy all the necessary parts for the time vehicle. The cosmic penny was even enough to buy a "Mc. Woovitch" kebab, with sauce as sharp as the scent of Uranus' atmosphere, for Stach and Grażyna.



Delighted with the taste of the exquisite dish, the Kronostat members proceeded to repair the vehicle. The repair (contrary to Murphy's law) went without the slightest problems and in less time than a day on Jupiter, our crew could make their first time travel in a long time. Eager for adventure, the crew members decided to venture into the future to unwind from the tense atmosphere that had prevailed after recent events. Grażyna suggested the year 5129, when they could go wild, because the biggest star in the Universe "73N3K MARS TYTANIUK" was touring the Milky Way then. Stach entered the mentioned date in the terminal and clicked ENTER, then 3...2...1... our group found themselves in the year 1295... (Murphy's law works after all). The culprit of the whole incident was, as one can easily guess, the hot sauce, which carelessly dripped from Janusz's kebab straight onto the Control Panel. Janusz, being Janusz, told the other crew members not to panic - after all, he would figure something out soon. After a few hours spent in the mud behind a peasant's hut, where the vehicle stood, Janusz came up with an idea.



Janusz's idea was simple yet brilliant: the vehicle must "break in" that kebab - and there's no better method for breaking in hot sauce through a diesel engine than its proper break-in. Using the Spacetime Internet, Janusz finally found the appropriate method for measuring the engine's break-in level. On the automotive forum mirkowo.com, he read that one should examine the sounds produced by the engine, specifically their frequency and wavelength. These two quantities are related by the equation v = λf, where v is the speed of sound, λ is wavelength, and f is frequency. On this forum he also found valuable tips.



First: sounds should be measured by ear, because those crappy meters from Zeta Reticuli, which flooded the market throughout the Milky Way, measure frequency in the range from 500 to 5000 Hz, while the human ear picks up sounds in the range from 20 to 20,000 Hz!



Second: vehicle engines only work when the outside temperature is between -30 to 30 degrees Celsius, so sound measurements should be taken in both summer and winter, because the speed of sound depends on temperature:



| Temperature (°C) | Speed of Sound (m/s) |

|------------------|----------------------|

| -40              | 306                  |

| -30              | 313                  |

| -20              | 319                  |

| -10              | 326                  |

| 0                | 332                  |

| 10               | 338                  |

| 20               | 344                  |

| 30               | 350                  |

| 40               | 355                  |



Third: when all properly recorded frequencies, regardless of weather, oscillate within the range of (300 ± 25) Hz, the engine can be considered broken in (there must be at least one valid reading from this range). If even one properly recorded sound outside this scale is noted, then we consider the engine not broken in.



Fourth: if the engine is broken in, then you can set off to the star's concert without problems!!!



To break in the engine, the Kronostat crew ventured to random points on the timeline to take measurements in different temperature conditions. In the old years, winters were proper, while in the future, due to extreme global warming, heat prevails all year round. Parameters of engine operation measured by "Janusz's ear" method were recorded by Stach in the onboard notebook. Based on data about sound wave lengths and frequencies heard in different places in time, our jack-of-all-trades will assess whether the vehicle is already working properly.



Grażyna, looking with irritation at the notes that Stach was making, grabbed her head, because there was no order in them. To save the mission, she grabbed the notebook herself and brought order to the records. She organized the data from the "Januszometer" by recording the visited years in the form of a binary tree. For a given year, Grażyna recorded the heard frequencies and corresponding wavelengths in an analogous way.



Write a program that will make Grażyna's work easier.



## Input



The first line of input contains a natural number n - the number of time travels. Then n lines will be taken from standard input, consisting of three natural numbers: y - the year the crew arrived at, f - the heard frequency in Hz, and l - the measured wavelength in cm.



1 ≤ n ≤ 300,000  

1 ≤ y ≤ 10,000  

1 ≤ f ≤ 100,000  

1 ≤ l ≤ 5,000  



## Output



The output should contain as many lines as there are unique dates in the input data for which correct measurements were made. These dates should be sorted in ascending order. Each line should contain the frequencies and wavelengths heard in that year:

\[year]: (f1,l1), (f2,l2), (f3,l3)...



Sort pairs (fi,li) in ascending frequency order. If two pairs have the same frequency, display first the pair with the smaller wavelength.



In the last line of output, include additional information about whether the engine has been broken in YES/NO. Taking into account that Janusz's hearing after eating spicy pita can sometimes fail, and tired Grażyna occasionally makes errors in notes (e.g., writes one zero too many for frequency), reject all measurements that you consider erroneous. Consider what sounds Janusz could not have heard and what sounds could not have been recorded taking temperature into account.



\*\*NOTE! You cannot use STL libraries in this task. You must use a self-written binary tree implementation.\*\*



## Example:

### Input:

```

16

5029 10 2789

7819 45043 23

1993 30 1080

2789 29 1090

2222 302 107

834 299 108

67 34 100

123 390 12888

728 300 108

1073 302 107

2222 302 107

834 109 300

1993 300 108

234 3000 11

2222 150 214

834 299 109

```



### Output:

```

234: (3000,11)

728: (300,108)

834: (109,300) (299,108) (299,109)

1073: (302,107)

1993: (30,1080) (300,108)

2222: (150,214) (302,107) (302,107)

2789: (29,1090)

NIE

```





