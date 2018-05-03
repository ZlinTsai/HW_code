# StatMech Assignment 1

## Problem 0: One die with 6 sides

Sample code: [Sample_OneDie.py](Sample_OneDie.py) or [Sample_OneDie_np.py](Sample_OneDie_np.py)

1. Write a program (or modify the one given) to calculate and print out the histogram of the number of times each side occurs, the deviation of this number from one-sixth of the number of trials, the frequency with which each side occurs, and the deviation of this from one sixth. Hand in a copy of the code you used.
2. Show a typical print-out of your program.
3. Run the program for various numbers of random integers, starting with a small number, say 10, and increasing to a substantially larger number. The only upper limit is that the program should not take more than about one second to run. ([Your time is valuable.) THIS IS A COMPUTATIONAL PROBLEM. ANSWERS MUST BE ACCOMPANIED BY DATA. Please hand in hard copies for all data to which you refer in your answers.
4. As the number of trials increases, does the magnitude (absolute value) of the differences between the number of times a given side occurs and one-sixth of the number of trials increase or decrease? (Hint: This is not the same question as the next one.)
5. As you increase the number of trials, does the ratio of the number of times each side occurs to the total number of trials approach closer to 1/6?

## Problem 1: One die with S sides

Sample code: [Sample_OneDieS.py](Sample_OneDieS.py) or [Sample_OneDie_np.py](Sample_OneDie_np.py)

Suppose we have a die with S sides, where S is an integer, but not necessarily equal to 6. The set of possible outcomes is then {n|n = 1,...,S} (or {n|n = 0,...,S−1}, your choice). Assume that all sides of the die are equally probable, so that P(n) = 1/S. Since this is partly a computational problem, be sure to support your answers with data from your computer simulations.

1. What are the theoretical values of the mean, variance, and standard deviation as functions of S? The answers should be in closed form, rather than expressed as a sum (Hint: It might be helpful to review the formulas for the sums of integers and squares of integers.)
2. Modify the program you used for an earlier problem to simulate rolling a die with S sides, and print out the mean, variance, and standard deviation for a number of trials. Have the program print out the theoretical predictions in each case, as well as the deviations from theory to facilitate comparisons.
3. Run your program for two different values of S. Are the results for the mean, variance, and standard deviation consistent with your predictions? (Do not use such long runs that the program takes more than about a second to run. It would be a waste of your time to wait for the program to finish.)
4. Experiment with different numbers of trials. How many trials do you need to obtain a rough estimate for the values of the mean and standard deviation? How many trials do you need to obtain an error of less than 1%? Do you need the same number of trials to obtain 1% accuracy for the mean and standard deviation.
