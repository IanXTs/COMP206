#include<stdio.h>
#include<stdlib.h>

int main(void){
 //enter the msg and the key
 char msg[10000];
 int key;
 
 printf("msg: ");
 scanf("%s", msg); // create scanner for the message
 printf("Key: ");
 scanf("%d", &key); //create scanner for the key
 
 //to make sure that all inputs are from a to z
 if (key < 1 || key > 25){
  printf("Invalid key input!\n");
 }

 //print original message
 printf("Original message: %s \n", msg);

 //encrypte msg
 //without key
 // we loop through both capital and noncapital letters
 char encrypted[10000];
 for (int i = 0; i < strlen(msg); i++){
  //capital letter
  if (msg[i]<='Z'){
   encrypted[i]='A' + (msg[i]-'A'-key+26)%26; 
  }else if (msg[i]>='a'){ 
   encrypted[i]='a' + (msg[i]-'a'-key+26)%26;
  }
 }
 printf("Encrypted message: %s \n", encrypted);

 //decrypt msg
 //same as encrypt but we add key to the decrypt
 // same here, we loop through both capital and noncapital letters
 char decrypted[10000];
 for (int j = 0; j < strlen(msg); j++){
  if (encrypted[j]<='Z'){
   decrypted[j]='A' + (encrypted[j]-'A'+key)%26; 
  }else if (encrypted[j]>='a'){
   decrypted[j]='a' + (encrypted[j]-'a'+key)%26;
  }
 }
 printf("Decrypted message: %s \n", decrypted);
 return 0;
}

//Ian Tsai 260741766
