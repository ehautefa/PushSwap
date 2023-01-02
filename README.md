# PushSwap
_*Sorting data on a stack, with a limited set of instructions, and the smallest number of moves.*_


```./test <stackSize>``` will generate stack-size aleatory digits, show with a little visualizer how it works, and finally print the number of instructions used!

## Subject

- You have 2 stacks named a and b.
- At the beginning:
  ◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.  
  ◦ The stack b is empty.  
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

### SA
  (swap a): Swap the first 2 elements at the top of stack a.
### SB
  (swap b): Swap the first 2 elements at the top of stack b.
### SS
  sa and sb at the same time.
### PA
  (push a): Take the first element at the top of b and put it at the top of a.
### PB
  (push b): Take the first element at the top of a and put it at the top of b.
### RA
  (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
### RB
  (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
### RR
  ra and rb at the same time.
### RRA
  (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
### RRB
  (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
### RRR
  rra and rrb at the same time
  
 ## Solution implemented
 
 I begin with a QuickSort, I took the median of the first stack and I push on stack B all element that are superior to the median.
 I doing this until it stay only 3 digits on stack A. Next, I push in the sorted order, the element on stack a.
