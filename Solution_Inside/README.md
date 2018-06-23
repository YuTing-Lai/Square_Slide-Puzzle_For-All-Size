# Puzzle Solution


## Solution Program

### What can I do with it?

* Follow the steps inside the program, you'll solve it.
* Whatever how disordered the puzzle is, you can still solve it.
* Even if the puzzle has no exact solution, it will help you find out.
* Almost **every sizes are avialable**. (For human-solving puzzles)


### How to use it?

* Run the **Puzzle-Solution.cpp** first.
* You have to **Input Your Puzzle's Size**. (for example: 4 )

```
What it your puzzle's size (N x N)? Input N. (1<N<100)
4
```

* Then **Input Your Puzzle's Numbers**, if it is the blank, Input the last number of your puzzle. (Like the example is 16)

```
Input the puzzle, from left to right, from up to down.
If it is the blank, input 16.
1   2   7   4 
6   16  3  14 
10  5   8  13 
11  12  9  15 
Your puzzle:
  1   2   7   4 
  6       3  14 
 10   5   8  13 
 11  12   9  15 
```

* The program will take you step by step, follow it until the puzzle is solved.

```
Move the blank:     <-This is the target
down   right        <-This is the direction step
    1   7   4       <-|
6   2   3   14      <-|This is what your puzzle will
10  5   8   13      <-|look like after you finish
11  12  9   15      <-|the steps.

Move 1:
left   
1       7   4   
6   2   3   14  
10  5   8   13  
11  12  9   15 
```

* If there are no problems of the puzzle.

```
Move 11 and the blank:
left   up     
1   2   3   4   
5   6   7   8   
9   10  11  12  
13  14  15      

Done!
```

* If it does have problems, it will look like this.

```
Move 11 and the blank:
left   up     
1   2   3   4   
5   6   7   8   
9   10  11  15  
13  14  12      

The puzzle has error. Please fix it.
```

<br><br>
## Solution Method

### Method Imformation

* For any sizes of an puzzle, we can know every number of any positions by using variables. 


<img width="350" alt="2018-06-23 6 25 40" src="https://user-images.githubusercontent.com/40336920/41808621-e1b3d4e0-7712-11e8-8447-07e5c4f532b7.png">

* Except the 2x2-Square, seperate the puzzle into sections.

<img width="350" alt="2018-06-23 9 24 38" src="https://user-images.githubusercontent.com/40336920/41810272-8638e2ec-772e-11e8-8a2d-fa1cc8a94ffe.png">

* Begin at the biggest section (**「** ) , solve each section one by one.

<img width="350" alt="2018-06-23 9 24 06" src="https://user-images.githubusercontent.com/40336920/41810271-80e5ca58-772e-11e8-9fa1-0bc5d6d898cb.png">


### In the Sections

Every Section (**「** ) seperate to **4 parts**.

<img width="300" alt="2018-06-23 9 33 44" src="https://user-images.githubusercontent.com/40336920/41810274-88e97470-772e-11e8-8c0e-a6db996ea16c.png">

***The First Part:***

* Numbers of the 1st part will always be at **the right and down side**.

<img width="300" alt="2018-06-23 10 08 54" src="https://user-images.githubusercontent.com/40336920/41810492-10c2fea4-7732-11e8-9909-bdbbdd679563.png">

</p>
<p align="center">
**↑ No difficulty at this part !**
</p>

<br>
***The Second Part:***

* The 2nd part is the **right most number**, the number will always be at **the down and left side**.

<img width="300" alt="2018-06-23 10 12 53" src="https://user-images.githubusercontent.com/40336920/41810530-9be7151a-7732-11e8-8c7a-95e2c7f4fc24.png">

****NOTE: How to move the number inside ?***

* Move the number and the blank to here first.  (B:  blank, n: number)

<img width="300" alt="2018-06-23 10 28 35" src="https://user-images.githubusercontent.com/40336920/41810671-defdf5a6-7734-11e8-9c5b-c8ecd600aafd.png">

* Then move the number like this ↓

<img src ="https://user-images.githubusercontent.com/40336920/41810877-1c527fa0-7738-11e8-95bb-b76c5f68cc21.gif" width="300" height="300">

<br>

***The Third Part:***

* Numbers of the 3rd part will always be at **the right and down side**.

<img width="300" alt="2018-06-23 11 03 37" src="https://user-images.githubusercontent.com/40336920/41810994-ea91788e-7739-11e8-8bde-affc8380ea86.png">

</p>
<p align="center">
**↑ No difficulty at this part either !**
</p>
<br>

***The Fourth Part:*** 

* The last part is **the last number of the section**, the number will always be at **the up and right side**.

<img width="300" alt="2018-06-23 11 15 38" src="https://user-images.githubusercontent.com/40336920/41811084-61595580-773b-11e8-8d32-89932b321bc4.png">

****NOTE: How to move the number inside ?***

* Similiar to the **2nd part**, put the blank and the number here first.  (B:  blank, n: number)

<img width="300" alt="2018-06-23 11 20 29" src="https://user-images.githubusercontent.com/40336920/41811126-242aeb64-773c-11e8-95f4-a61324ae868c.png">

* Then move the number inside.

<img src ="https://user-images.githubusercontent.com/40336920/41811213-22774428-773e-11e8-8225-6371e3e6dd06.gif" width="300" height="300">

* After moving all the numbers inside this section, go for the next section.

<img width="300" alt="2018-06-23 11 42 08" src="https://user-images.githubusercontent.com/40336920/41811288-386fa9a4-773f-11e8-88f2-cc1928c63cdc.png">











 

