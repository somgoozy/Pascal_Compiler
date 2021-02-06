Project 2 

1. What is it?
2. How is it used?
3. How does it work?
4. What can be expected

1. What is it?
This is a program created by Jonathon Ashkani for his CS450 class. This program
sorts input data, that are sets of 4 reals, into a KD tree with a bucket max
size of ten. It then takes input data sets and outputs the contents of the
bucket that it would have been placed in.

2. How is it used?
This program can be used on a computer with a compiler that can compile
Pascal code with the Free Pascal Compiler (FPC). I would recommend using the
UK Multilab. The easiest way to compile this program is to use the included
makefile. The input for this program is all through a data file. From there,
you should be able to run the created executable. The data file must be named
"asg.pascal.data". The data file must be formatted in a specific way. The
program allows for 4 reals per line, with the first line being a positive
integer. This first number tells the program how many following lines are going
to be inserted into the KD tree. After the sets of reals that you wish to have
stored in the tree, you need to include a positive integer that tells the
program how many sets of reals you wish to compare to the previously created
KD tree.

3. How does it work?
This program was written in Pascal, which has several quirks, and thus this
program was a HEADACHE to write. This made me miss FORTRAN. This program
creates a 2 dimensional array of the size nx4, where n is the size specified by
the first line of input. The data gets passed to a recursive function. This
recursive function first passes the data to another function that returns the
dimension that has the largest span. The recursive function then calls a
different recursive function that does the QuickSelect algorithm with Lomuto's
partition method to put the data on the correct half of the tree. It then
splits the data into 2 sub trees by recursing. It stops recursing when the
final buckets are less than 10, and stores the data. It then reads the probe
data, then uses a very simple recursive algorithm to find the correct bucket
to display to the user.


What can be expected?
You can expect this program to work. I have provided 4 test files to show how
some use cases. They do need to be renamed before use.

example1: This test case shows what happens when a number less than 1 is
entered for n, which is exit gracefully.

example2: This test case has both valid numbers for p and n, and shows the
extreme example of the program functioning.

example3: This test case gives a valid tree, but an invalid n. The program shows
that a tree was made, but that there was nothing to compare it to.

example4: This test case is a standard use case adapted from the example one
provided.