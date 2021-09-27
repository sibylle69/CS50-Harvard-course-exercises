A program that identifies to whom a sequence of DNA belongs.

- The program requires as its first command-line argument the name of a CSV file containing the STR counts for a list of individuals and requires as its second command-line argument the name of a text file containing the DNA sequence to identify.
- If the program is executed with the incorrect number of command-line arguments, the program prints an error message. If the correct number of arguments are provided, we assume that the first argument is indeed the filename of a valid CSV file, and that the second argument is the filename of a valid text file.
- The program opens the CSV file and read its contents into memory.
- We assume that the first row of the CSV file will be the column names. The first column will be the word name and the remaining columns will be the STR sequences themselves.
- The program should open the DNA sequence and read its contents into memory.
- For each of the STRs (from the first line of the CSV file), the program computes the longest run of consecutive repeats of the STR in the DNA sequence to identify.
- If the STR counts match exactly with any of the individuals in the CSV file, the program prints out the name of the matching individual.
- We assume that the STR counts will not match more than one individual.
- If the STR counts do not match exactly with any of the individuals in the CSV file, the program prints "No match".
