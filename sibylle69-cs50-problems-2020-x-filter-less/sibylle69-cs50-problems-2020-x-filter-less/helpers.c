#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //for each line
    for (int i = 0; i < height; i++)
    {
        //for each pixel
        for (int j = 0; j < width; j++)
        {
            BYTE avg_byte;
            avg_byte = round(((int) image[i][j].rgbtBlue + (int) image[i][j].rgbtGreen + (int) image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg_byte;
            image[i][j].rgbtGreen = avg_byte;
            image[i][j].rgbtRed = avg_byte;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // for each line
    for (int i = 0; i < height; i++)
    {
        //for each pixel
        for (int j = 0; j < width; j++)
        {
            int a = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int b = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int c = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (a > 255)
            {
                a = 255 ;
            }

            if (b > 255)
            {
                b = 255;
            }

            if (c > 255)
            {
                c = 255;
            }

            image[i][j].rgbtRed = a;
            image[i][j].rgbtGreen = b;
            image[i][j].rgbtBlue = c;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //create a copy
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0, w2 = (width / 2); j < w2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    int Blue;
    int Green;
    int Red;
    int c;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Green = 0;
            Blue = 0;
            Red = 0;
            c = 0;

            //check if pixels around and change pixels
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if ((k >= 0 && k <= (height - 1)) && (l >= 0 && l <= (width - 1)))
                    {
                        Blue += image[k][l].rgbtBlue;
                        Green += image[k][l].rgbtGreen;
                        Red += image[k][l].rgbtRed;
                        c++;
                    }
                }
            }
            printf("%i", c);
            //change the pixels
            original[i][j].rgbtGreen = round((float)Green / c);
            original[i][j].rgbtBlue = round((float)Blue / c);
            original[i][j].rgbtRed = round((float)Red / c);
        }
    }
    //replacing stuff
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            image[a][b].rgbtBlue = original[a][b].rgbtBlue;
            image[a][b].rgbtGreen = original[a][b].rgbtGreen;
            image[a][b].rgbtRed = original[a][b].rgbtRed;
        }
    }
}