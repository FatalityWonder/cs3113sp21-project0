#include <stdio.h>
#include <stdlib.h>

struct NumberChars
{
    unsigned char character[4];
    int num;
};

/**
#define declare_NumberChars(name, character, num) struct NumberChars name = {character, num}

struct NumberChars* newNumberChars(char character, int num)
{
    struct NumberChars* temp = malloc(sizeof(struct NumberChars));

    if(temp)
    {
        temp->character[0] = character;
        temp->num = num;
    }
}
**/

//function prototype
void print(struct NumberChars** array);

int main()
{
    struct NumberChars* chararacterCount[100];

    unsigned char charByte;
    unsigned char temp;
    unsigned char charSecond;
    unsigned char charThird;
    unsigned char charFourth;
    int i = 0;

    while ((charByte = fgetc(stdin)) != EOF) 
    {
        temp = (unsigned char)charByte;
        //This is a check to see if the character is one byte
        if(temp < 128)
        {
            printf("test1"); 
            chararacterCount[0]->character[0] = temp;
            printf("test2"); 
        }
        else if(temp < 224)
        {
            printf("test3"); 
            charSecond = fgetc(stdin);            
        }
        else if(temp < 240)
        {
            printf("test4"); 
            charSecond = fgetc(stdin);
            charThird = fgetc(stdin); 
        }
        else
        {
            printf("test5"); 
            charSecond = fgetc(stdin);
            charThird = fgetc(stdin);
            charFourth = fgetc(stdin); 
        }
        ++i;
        if(i>5)
            break;
    }
    printf("testmain"); 
    /**
    for (int i = 0; i < 100; ++i)
    {
        chararacterCount[i] = newNumberChars('c', 1);
    }
    **/

    // print plus count
    for (int i = 0; i < 100; ++i)
    {
        if(!chararacterCount[i])
        {
            break;
        }
        //printf(i + '\n'); 
        printf(chararacterCount[i]->character[0] + "->" + chararacterCount[i]->num + '\n');
        
        // exit loop if there is no char
        /**if(array[i]->num == 0)
        {
            break;
        }**/
    }
}