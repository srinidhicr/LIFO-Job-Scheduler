# LIFO-Job-Scheduler
This C++ implementation, inspired by a dynamic programming approach outlined in a research paper, addresses a scheduling problem in a deterministic single-machine environment. The problem involves optimizing a job sequence according to a non-decreasing objective function of job completion times.

You can refer to the research paper [here](https://arxiv.org/pdf/2106.15901.pdf).

## Problem Statement
Consider a scenario where a set of 'n' jobs must be scheduled based on a regular objective function. Each job has a processing time ('pj'), a due date ('dj'), and possibly a weight ('wj'). The initial job sequence ('σ0') is given, and the objective is to find a new sequence ('σ') that minimizes the objective function while allowing a constrained number of feasible moves.

## Scheduling Environment
Moves in the scheduling environment are executed by a physical device, such as a robot arm, operating on a sequence of jobs arranged along a line. The device performs actions like picking up jobs, placing them in a stack with a bounded capacity ('S'), and reinserting them later in the sequence based on a Last-In-First-Out (LIFO) policy.

## Approach
The goal is to find an optimal job sequence that minimizes the starting time of a subsequence while allowing a constrained number of feasible moves. Each job has a processing time, due date, and weight.

The algorithm maintains a state, denoted as s(i, j, m, l), representing the minimum decrease of the starting time of a subsequence σ0(i, j) to obtain m late jobs, using moves up to level l.

The dynamic programming table s is initialized as - for the base case, l = 0. It computes the initial state values by considering the lateness values of jobs in the subsequence. For each level l >= 1, the algorithm extends the state based on three job subsets: jobs nested in the move, the moved job, and other jobs. It computes a multi-set S(i, j, k, l) representing the minimum reduction of starting time needed to achieve m late jobs for each possible move (i, k, l0).

The optimal solution value is obtained by finding the minimum number m such that s(1, n, m, S) ≤ 0, indicating the minimum number of late jobs in the optimal sequence.

The code initializes the dynamic programming table and performs the recursive computation of states using nested loops. The main function then determines the minimum number of late jobs based on the final state values and prints the result.

This algorithm is particularly applicable to scheduling scenarios where jobs need to be rearranged to minimize lateness, and the code provides a practical implementation of the dynamic programming approach outlined in the research paper.
