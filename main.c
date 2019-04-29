#include <stdio.h>
#include <string.h>

// The program will first prompt the user to enter either a message to encrypt,
// or an already encrypted message to decrypt. The user will then be prompted to 
// enter an integer between 1-4 based on the desired function. Entering 1 will
// encrypt the message via rotation for a given key. Entering 2 will decrypt the
// message via rotation for a known key. 

// Entering 3 will encrypt the message via substitution for a known key string, that 
// is a string of characters that each character's position corresponds to that of the
// alphabet respectively. For example, the key string qwertyuiopasdfghjklzxcvbnm would 
// assign q to a, w to b, e to c, and so on. Entering 4 will decrypt the message via
// substitution for a known key string.


int main() {
int k,x,i,cypher,index;
char str[1000];
char subcypher[1000];
char decypher[1000];
char key[26];

printf("Enter message to either encrypt or decrypt:\n");

fgets(str,1000,stdin); // reads input message string up to 1000 characters

printf("You entered: %s",str);
printf("\nWhat would you like to do?\n"); //menu options
printf("1 = Encrypt message via rotation\n");
printf("2 = Decrypt message via rotation\n");
printf("\n3 = Encrypt message via substitution\n");
printf("4 = Decrypt message via substitution\n");

scanf("%d",&x);

switch(x) {
    
    case 1:
    printf("Enter key:\n");
    scanf("%d",&k);
    
    if (k>=26) { //if entered key outside of alphabet size, ticks over back from 0
        k = k % 26;
    }
      printf("Encrypted message is:\n");
      
        for(i=0;i<strlen(str);i++) {
        cypher=str[i]+k;
        
            if ((str[i]<=90)&&(cypher>90)) { //If input capital letter results in cypher outside of ASCII 65 - 90 range, returns back to start of alphabet (65)
            cypher = cypher - 26;
            }
        
            if ((str[i]<=90)&&(cypher<65)) { 
            cypher = cypher + 26;
            }
        
            if ((str[i]>90)&&(cypher>97)) { //If input character is a lowercase letter, converts to corresponding capital and encrypts
            cypher = cypher - 32;
            }
        
            if ((str[i]>90)&&(cypher<=97)) {
            cypher = cypher - 6;
            }
        
            if ((str[i]>=65)&&(str[i]<=90)) { //Prints calculated cypher values for ASCII code A(65)-Z(90)
            printf("%c",cypher);
        }
        
            else {
                printf("%c",str[i]); //If capital or lower case is letter is not input, returns input character
                 }
    }

    break;
    
    case 2:
    printf("Enter key:\n");
    scanf("%d",&k);
    
   if (k>=26) {
        k = k % 26;
    } 
    
        
     printf("Decrypted message is:\n");
     
  for(i=0;i<strlen(str);i++) {
      
       
        cypher=str[i]-k;
        
        if ((str[i]<=90)&&(cypher>90)) { //
            cypher = cypher - 26;
        }
        
        if ((str[i]<=90)&&(cypher<65)) {
            cypher = cypher + 26;
        }
        
        if ((str[i]>90)&&(cypher>97)) {
            cypher = cypher - 32;
        }
        
         if ((str[i]>90)&&(cypher<=97)) { 
            cypher = cypher - 6;
        }
        
        if ((str[i]>=65)&&(str[i]<=90)) { //Prints calculated cypher values for ASCII code A(65)-Z(90)
            printf("%c",cypher);
        }
        
        else {
            printf("%c",str[i]); //Simply returns whatever the input character is if not a letter
        }
    }

   
    break;
    
    case 3: 
    
    printf("Enter key string (26 unique characters):\n");
    fgets(key,26,stdin);
    
    printf("\nEncrypted message is:\n");
    
    for(i=0;i<strlen(str);i++) {
        index = (str[i])-65; //converts letter to encrypted letter based on its position in string key
        subcypher[i] = key[index]; 
        
        if ((str[i]>90)||(str[i]<65)) {
            subcypher[i] = str[i];            
                                }
                                
        printf("%c",subcypher[i]);
                                
                                }
        
break;
      
  
       
      case 4:
       
         printf("Enter key string (26 unique characters):\n");
         fgets(key,26,stdin);
         
         printf("\nDecrypted message is:\n");
         
         char alphabet[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
         
         for (i=0;i<26;i++) {
               index = strchr(key,alphabet[i]); //searches the key for input string character location for each character
         }
              
         for(i=0;i<strlen(str);i++) {
            
        decypher[i] = alphabet[index]; //prints the character that corresponds to cyphered character
        
        if ((str[i]>90)||(str[i]<65)) {
            decypher[i] = str[i];            //prints input string if not a capital letter
                                }
                                
        printf("%c",decypher[i]);
                                
                                }

       break;
       
        default:
    printf("Error: Please enter an integer from 1 - 4"); //if integer 1-4 not entered
    
    return 0;
    }
}

  
