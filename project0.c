#include <stdio.h>
#include <stdlib.h>

//typedef NumberChars;

typedef struct NumberChars
{
    unsigned char character[4];
    int bytes;
    int num;
} NumberChars;

// size of array
const int ARR_SIZE = 100000;

// function prototype
int hasChar(struct NumberChars mainArr[], unsigned char chars[]);

int main()
{
    struct NumberChars chararacterCount[ARR_SIZE];

    // initialize array of structures
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            chararacterCount[i].character[j] = 0;
        }
        chararacterCount[i].bytes = 0;
        chararacterCount[i].num = 0;
    }

    int charByte;
    unsigned char tempChar[4] = {0, 0, 0, 0};
    unsigned char temp;
    int numDiffChars = 0;

    while ((charByte = fgetc(stdin)) != EOF) 
    {
        temp = (unsigned char)charByte;
        
        //reset tempChar
        for (int i = 0; i < 4; ++i)
        {
            tempChar[i] = 0;
        }

        if(temp < 128) // 1 byte (ascii) char
        { 
            // read in char
            tempChar[0] = charByte;
            int indexPrensent = hasChar(chararacterCount, tempChar);
            if(indexPrensent >= 0)
            {
                ++chararacterCount[indexPrensent].num;
                continue;
            }
            
            // char not present
            for (int i = 0; i < 4; ++i)
            {
                chararacterCount[numDiffChars].character[i] = tempChar[i];
            }
            chararacterCount[numDiffChars].bytes = 1;
            ++chararacterCount[numDiffChars].num;
        }
        else if(temp < 224) // 2 byte char
        {
            // read in char
            tempChar[0] = charByte;
            tempChar[1] = fgetc(stdin);

            int indexPrensent = hasChar(chararacterCount, tempChar);
            if(indexPrensent >= 0)
            {
                ++chararacterCount[indexPrensent].num;
                continue;
            }

            // char not present
            for (int i = 0; i < 4; ++i)
            {
                chararacterCount[numDiffChars].character[i] = tempChar[i];
            }
            chararacterCount[numDiffChars].bytes = 2;
            ++chararacterCount[numDiffChars].num;
        }
        else if(temp < 240) // 3 byte char
        {
            // read in char
            tempChar[0] = charByte;
            tempChar[1] = fgetc(stdin);
            tempChar[2] = fgetc(stdin);

            int indexPrensent = hasChar(chararacterCount, tempChar);
            if(indexPrensent >= 0)
            {
                ++chararacterCount[indexPrensent].num;
                continue;
            }

            // char not present
            for (int i = 0; i < 4; ++i)
            {
                chararacterCount[numDiffChars].character[i] = tempChar[i];
            }
            chararacterCount[numDiffChars].bytes = 3;
            ++chararacterCount[numDiffChars].num;
        }
        else // 4 byte char
        { 
            // read in char
            tempChar[0] = charByte;
            tempChar[1] = fgetc(stdin);
            tempChar[2] = fgetc(stdin);
            tempChar[3] = fgetc(stdin);

            int indexPrensent = hasChar(chararacterCount, tempChar);
            if(indexPrensent >= 0)
            {
                ++chararacterCount[indexPrensent].num;
                continue;
            }

            // char not present
            for (int i = 0; i < 4; ++i)
            {
                chararacterCount[numDiffChars].character[i] = tempChar[i];
            }
            chararacterCount[numDiffChars].bytes = 4;
            ++chararacterCount[numDiffChars].num;
        }

        ++numDiffChars;
    }
    
    // sort
    int max;
    for(int i = 0; i < ARR_SIZE-1; ++i)
    {
        // no more characters to search
        if(chararacterCount[i].num == 0)
        {
            break;
        }

        max = i;

        for(int j = i + 1; j < ARR_SIZE; ++j)
        {
            // no more characters to search
            if(chararacterCount[j].num == 0)
            {
                break;
            }

            if (chararacterCount[j].num > chararacterCount[max].num)
            {
                max = j;
            }
        }

        //swap
        if (max != i)
        {
            NumberChars arrChar = chararacterCount[i];
            chararacterCount[i] = chararacterCount[max];
            chararacterCount[max] = arrChar;
        }
    }

    // print char plus count
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        if(chararacterCount[i].num == 0)
        {
            break;
        }
        
        if (chararacterCount[i].bytes == 1)
        {
            fprintf(stdout, "%c", chararacterCount[i].character[0]);
        }
        else if (chararacterCount[i].bytes == 2)
        {
            fprintf(stdout, "%c%c", chararacterCount[i].character[0], chararacterCount[i].character[1]);
        }
        else if (chararacterCount[i].bytes == 3)
        {
            fprintf(stdout, "%c%c%c", chararacterCount[i].character[0], chararacterCount[i].character[1], chararacterCount[i].character[2]);
        }
        else if (chararacterCount[i].bytes == 4)
        {
            fprintf(stdout, "%c%c%c%c", chararacterCount[i].character[0], chararacterCount[i].character[1], chararacterCount[i].character[2], chararacterCount[i].character[3]);
        }      
        printf("->");
        fprintf(stdout, "%d", chararacterCount[i].num);
        fprintf(stdout, "%c", '\n');
    }
}

// returns -1 if char is not present
// returns index if char is present
int hasChar(struct NumberChars mainArr[], unsigned char chars[])
{
    // if same == 4 them it returns the index
    int same;

    for (int i = 0; i < ARR_SIZE; ++i)
    {
        // new char to test
        same = 0;

        // no more available spaces to check for chars
        if(mainArr[i].num == 0)
        {
            break;
        }
       
        for (int j = 0; j < 4; ++j)
        {
            if (mainArr[i].character[j] == chars[j])
            {
                ++same;
            }
            if (same == 4)
            {
                return i;
            }
        }
    }
    // char not found
    return -1;
}
