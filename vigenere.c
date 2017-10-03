#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //verify that there is an argument when executing the program.
    if (argc != 2)
    {
        printf("Error 404\n");
        printf("Please enter a valid agrument for the command ./vigenere\n");
        return 1;
    }
    
    //initializes key variable
    string key = argv[1];
    
    //verify the characters in the key are all alpha.
    int keyLength = strlen(argv[1]);
    for(int j = 0; j < keyLength; j++)
    {
        while(!isalpha(key[j]))
        {
            printf("Error: Characters must be alpha.\n");
            return 1;
        }
    }
         
    //ask for the plaintext that the user wants encrypted
    printf("plaintext: ");
    string plainText = get_string();
    
    //prints cypertext title
    printf("ciphertext: ");
    
    //loop through the plaintext
    for (int i = 0, j = 0, ptLength = strlen(plainText); i < ptLength; i++, j++)
    {
        //gets ASCII value of key
        int keyValue = isupper(key[j % keyLength]) ? 'A' : 'a';
        
        //gets ASCII value of plaintext
        int ptValue = isupper(plainText[i]) ? 'A' : 'a';
        
        //gets cyphertext value
        char cipherText = ((plainText[i] - ptValue + (key[(j % keyLength)] - keyValue)) % 26) + ptValue;
        
        //prints cyphertext of plaintext, skpping plaintext if value is not alpha
        if(isalpha(plainText[i]))
        {
            
        printf("%c", cipherText);
        
        }
            else
            {
                
            printf("%c", plainText[i]);
            
            }
    }
    
    printf("\n");
    
    return 0;
}