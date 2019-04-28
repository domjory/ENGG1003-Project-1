#include <stdio.h>
#include <string.h>


//A large block comment should be at the top of your code which describes the high-level operation of
//the program. It should also include any user-interface notes (eg: how should the demonstrator choose
//between encryption and decryption?).

int search(char alphabet[],char index){
    for (int i=0;i<26;i++){
        if(alphabet[i]==index){
            return i;
        }
    }
    return 0;
}

int main() {
int k,x,i,cypher,key;
char str[1000];
char subcypher[1000];
char decypher[1000];

printf("Enter message:\n");

fgets(str,1000,stdin);

printf("You entered: %s",str);
printf("\nWhat would you like to do?\n");
printf("1 = Encrypt message via rotation\n");
printf("2 = Decrypt message via rotation\n");
printf("\n3 = Encrypt message via substitution\n");
printf("4 = Decrypt message via substitution\n");

scanf("%d",&x);

switch(x) {
    
    case 1:
    printf("Enter key:\n");
    scanf("%d",&k);
    
    if (k>=26) {
        k = k % 26;
    }
      printf("Encrypted message is:\n");
      
        for(i=0;i<strlen(str);i++) {
        cypher=str[i]+k;
        
            if ((str[i]<90)&&(cypher>90)) {
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
                printf("%c",str[i]);
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
        
        if ((str[i]<=90)&&(cypher>90)) {
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
    
    printf("Enter key:\n");
    scanf("%d",&key);
    
    char alphabet[26] = {'X','G','T','Z','P','N','B','W','O','J','K','L','M','F','I','E','Q','R','S','C','U','V','H','A','Y','D'};
    
    printf("Encrypted message is:\n");
    
     for(i=0;i<strlen(str);i++) {
        key = (str[i])-65;
        subcypher[i] = alphabet[key];
        
        if ((str[i]>90)||(str[i]<65)) {
            subcypher[i] = str[i];            
                                }
                                
        printf("%c",subcypher[i]);
                                
                                }
        
       break;
       
       case 4:
       
         printf("Enter key:\n");
         scanf("%d",&key); 
         
         printf("Decrypted message is:\n");
         
         for (i=0;i<strlen(str);i++){
             
             int key_solved = search(alphabet,str[key]);
             decypher[i]=65+key_solved;
             
             if ((str[i]>90)||(str[i]<65)) {
                decypher[i] = str[i];            
                printf("%c",decypher[i]);
             }
         }
       
       break;
       
        default:
    printf("Error: Please enter an integer from 1 - 4");
    
    return 0;
    }
}

  
