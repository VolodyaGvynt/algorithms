# Task "Paradox Safe"

## Problem Statement

One of Kronostat's missions is to ensure that time travel doesn't affect the main timeline. To this end, the organization's agents must often fix mistakes made by other travelers who leave illegal artifacts behind in various eras.

Grażyna — known for being able to organize a time mission down to the second, accounting for every possible variable — recently completed a long mission collecting items that shouldn't exist in the past. The final step of her operation is depositing these artifacts in the **Paradox Safe**, a powerful space-manipulating device created in the 25th century. The Paradox Safe is a device with amazing properties: regardless of how many items are already inside it, you can always add more. However, it's not that simple — each addition requires energy. The more items are already in the safe, the more energy is needed to "compress" the contents and store a new artifact.

Our agent, known for her obsessive precision, wants to plan the insertion of items into the Paradox Safe in such a way as to use as little energy as possible. Every time she arranges the order, she quickly finds a better solution. This constant pursuit of perfection causes her to waste too much time thinking.

Grażyna has collected a list of artifact identifiers and their masses. The **Paradox Safe** works in such a way that the energy cost of adding an item with mass ***x*** kg to a safe that already contains ***y*** kg of items is exactly ***x + y*** kJ. Janusz tried to figure something out, but although his ingenuity knows no bounds, as usual it was only a makeshift solution. This means that some items may already be properly ordered.

Your task is to plan the order of inserting items into the Paradox Safe so as to use as little energy as possible. If there are several items with the same mass, they should be inserted in the order in which they appear on the list.

## Input
The first line of input contains a natural number ***t***, which is the number of test sets. Each set begins with a natural number ***n***, which specifies the number of artifacts in the given set. Then in the next ***n*** lines there are descriptions of artifacts. Each description consists of an artifact identifier (a single-word string) and a natural number ***m***, indicating the mass of the item in kilograms.

***1 ≤ t ≤ 10, 1 ≤ n ≤ 50,000, 1 ≤ m ≤ 100,000***

## Output
For each test set, output two pieces of information: the minimum total amount of energy needed to put all artifacts into the Paradox Safe, and on the next line — a list of artifact identifiers in the order they should be inserted to use the least energy.

**NOTE! You cannot use STL libraries in this task. You must use a self-written sorting algorithm.**

## Example:
### Input:
```
2
5
rower_elektryczny-1453 12
smartfon-1890 1
dron_z_kamera-2000pne 4
przenosna_lodowka-753 8
teleporter_do_kawy-2024 4
3
skaner_mysli-1984 7
teletransporter-3210pne 133
noktowizor-1410 1
```

### Output:
```
61
smartfon-1890 dron_z_kamera-2000pne teleporter_do_kawy-2024 przenosna_lodowka-753 rower_elektryczny-1453
150
noktowizor-1410 skaner_mysli-1984 teletransporter-3210pne 
```

