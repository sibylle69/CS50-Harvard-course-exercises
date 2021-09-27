#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//int main(int argc, char *argv[])
//{
//    int sz;
//    int count = 0;
//    char *filename = malloc(3);
//    int filenum = 0;
//   typedef uint8_t BYTE;


//    if (argc < 2)
//    {
//        printf("Usage: ./recover image");
//        return 1;
//    }

//    FILE *card = fopen(argv[1], "r");

//   if (card == NULL)
//   {
//        fprintf(stderr, "Could not open input file!");
//        return (1);
//    }

/*    BYTE bytes[512];

    int num = fread(&bytes, sizeof(BYTE), 512, card);

    do
    {
        fread(bytes, 512, 1, card);

        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] + 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.png", filenum);
            FILE *img = fopen(filename, "w");
            //copy the bytes
            while (bytes[0] != 0xff && bytes[1] != 0xd8 && bytes[2] != 0xff && (bytes[3] + 0xf0) != 0xe0)
            {
                fwrite(bytes, 512, 1, img);
            }
            fclose(img);
            filenum++;
        }
    }
    while (num == 512);
}
*/

int main(int argc, char *argv[])

{
    typedef uint8_t BYTE;

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }
    FILE *fileout = NULL;
    char name[8];
    BYTE buffer[512];
    int count = 0;
    while (&free)
    {
        unsigned int byter = fread(buffer, sizeof(BYTE), 512, file);
        if (byter == 0 && feof(file))
        {
            break;
        }
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) && fileout != NULL)
        {
            fclose(fileout);
            count++;
        }

        // if we found a JPEG, we need to open the file for writing
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(name, "%03i.jpg", count);
            fileout = fopen(name, "w");
        }

        // write anytime we have an open file
        if (fileout != NULL)
        {
            fwrite(buffer, sizeof(BYTE), byter, fileout);
        }
    }
    fclose(fileout);
    fclose(file);

}