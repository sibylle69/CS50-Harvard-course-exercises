#include <cs50.h>
#include <stdio.h>

int main(void)
{
top: //referencing the line
    if (1 == 1) //always do what follows
    {
        int height = get_int("Give a height between 1 and 8\n"); //ask for the height
        //if the height is between 1 and 8 do what follows
        if (height >= 1 && height <= 8)
        { 
            int i; //create an integer
            int j; //create an integer
            int y; //create an integer
            // on each line one by one from 1 to the height
            for (i = 0; i < height; i++)
            { 
                // do one less time on each line
                for (y = 1; y < height - i; y++)
                { 
                    printf(" "); //write a dot
                }
                // do what follows one more time on each line
                for (j = 0; j < i; j++) 
                { 
                    printf("#"); // write #
                }
            
                // create a new line
                printf("#\n"); 
            } 
    
            // if the height is not between 1 and 8,
        }
        else 
        {
            //go back up to the top
            goto top; 
        }       
    } 
}
