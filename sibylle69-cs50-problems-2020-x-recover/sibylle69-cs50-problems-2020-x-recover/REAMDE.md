A program that recovers JPEGs from a forensic image.

- The program accepts exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
- If the program is not executed with exactly one command-line argument, it reminds the user of correct usage, and main should return 1.
- If the forensic image cannot be opened for reading, the program informs the user as much, and main returns 1.
- The files generated are each named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.
- The program does not leak any memory.
