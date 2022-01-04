#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define charLimit = 2000

bool lookingForJPG(FILE f);

int main()
{
    //make array for each letter
    int letters[26] = {0};

    //get number of times to run
    int numTimesToRun = get_int("");

    for (int a = 0; a < numTimesToRun; a++)
    {
        //number of lines
        int numLines = get_int("");

        for (int b = 0; b < numLines; b++)
        {
            //get line
            string line = get_string("");

            //get string lenth
            int stringlen = strlen(line);

            //check if line is above char limit
            if (stringlen > 2000)
            {
                return 1;
            }

            //for each letter in line add 1 to the corraspoding letter in the letters array
            for (int i = 0; i < stringlen; i++)
            {
                //convert line to upper
                int currentLetter = toupper(line[i]);

                //covert to indice and use array
                currentLetter -= 65;
                if (currentLetter > -1 && currentLetter < 66)
                {
                    letters[currentLetter]++;
                }
            }
        }
        //get total amount of string
        float totalAmount = 0;
        for (int i = 0; i < 26; i ++)
        {
            totalAmount += letters[i];
        }

        //print the percentages
        for (int i = 0; i < 26; i++)
        {
            //print the letter
            printf("%c: ", i+65);

            //print the percentage of that letter in the paragraph
            float percentage = letters[i] * 100.0 / totalAmount;
            printf("%.2f%%\n", percentage);
        }
    }
}
