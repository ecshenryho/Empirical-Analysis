# Empirical-Analysis
# Abstract
In this project you will design, implement, and analyze two algorithms for the same problem. For this problem, you will design two separate algorithms, describe the algorithms using clear pseudocode, analyze them mathematically, implement your algorithms in C++, measure their performance in running time, compare your experimental results with the efficiency class of your algorithms, and draw conclusions. The first algorithm has a tractable (polynomial) running time, while the second algorithm has an intractable (exponential or factorial) running time.
# The Hypotheses
This experiment will test the following hypotheses:
Exhaustive search algorithms are feasible to implement, and produce correct outputs.
Algorithms with exponential or factorial running times are extremely slow, probably too slow to be of practical use.
The Longest Increasing Subsequence Problem
The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique. The longest increasing subsequence problem can be formulated as follows.

# Longest increasing subsequence
input: a vector V of n comparable elements
output: a vector R containing the longest increasing subsequence of V

There is a complicated algorithm that solves this problem in O(n n) time, but we will be implementing two simpler algorithms with slower time complexities.

# The End-to-Beginning Algorithm
There is a straightforward algorithm that solves the problem and has O(n2) time complexity. The algorithm uses an additional array H of length n, of non-negative integers. The value H[i] will indicate how many elements, greater or equal to than A[i], are further in the sequence A and have some special property.

Initially, the array H is set to 0 (all the elements are 0). The algorithm proceeds by attempting to increase the values of H starting with the previous to last element and going down to the first element. Then a longest subsequence can be identified by selecting elements of A in decreasing order of the H values, starting with the element in A that has the largest H value.

# Algorithm End_to_Beginning
Step 1. Set all the values in the array H to 0.
Step 2. Starting with H[n-1]  and going down to H[0] try to increase the value of H[i] as follows:
Step 3. Starting with index i+1 and going up to n-1 (the last index in the array A) repeat Steps 4 and 5:
Step 4. See if any element is bigger than A[i] and has its H value also bigger to H[i].
Step 5. If yes, then A[i] can be followed by that element in an increasing subsequence, thus set H[i] to be 1 plus the H value of that element.
Step 6. Calculate the largest (maximum) value in array H. By adding 1 to that value we have the length of a longest increasing subsequence.
Step 7. Identify a longest subsequence by identifying elements in array A that have decreasing H values, starting with the largest (maximum) value in array H.

#An Exhaustive Algorithm
There is an exhaustive algorithm that solves the problem and has O(n 2n)time complexity. The algorithm generates all possible subsequences of the array A and tests each subsequence on whether it is in increasing order. The longest such subsequence is a solution to the problem.

We note that a subsequence can be uniquely identified by the set of indices in the array A that are part of the subsequence. For example, given the array
A = [1, 0, 2, 1, 5, 3, 13, 8, 34, 21, 89, 55, 233, 143]
the subsequence R = [1, 0, 3] is uniquely identified by the set of indices {0,1,5} of the elements in the array A.
To generate all possible subsequences, one may consider generating the power set of {0,1,...n-1} and consider each subset of the power set as the set of indices in A of the subsequence.

There are several ways to generate the power set. One way is to implement an iterative algorithm that uses a stack to grow and shrink the set as needed. The benefit of this approach is that it prints the subsets in lexicographic order

