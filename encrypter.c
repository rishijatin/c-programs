//c program to use the concepts of pointers,passing arguments to functions.
#include <stdio.h>
#include <stdlib.h>
//using pass by refrence and pass by value
void encrypt(char[],const int*,int);
void decrypt(char[],const int*,int);
void newKey(int *);

int main(int argc, char const *argv[]) {
char text[20]={'\0'};
int choice=1;
int key;
key=(rand()%4)+1;// creates a random number from 1 to 4
int i=0;

while (choice!=0) {
printf("enter 1 to encrypt a message\n enter 2 to decrypt a string\n enter 3 to change the encryption key \n enter 4 to diasplay he encryption key \n enter 0 to quit " );
scanf("%d",&choice );
switch (choice) {
  case 1:encrypt(text,&key,i);
   printf("the encrypted message is: %s\n",text );
   break;
   case 2: decrypt(text,&key,i);
   printf("the decrypted message is %s\n",text );
   break;
   case 3: newKey(&key);
   break;
   case 4: printf("the key used for encryption is:%d \n",key );
   break;
   case 0:break;
   default:printf("wrong choice nigga!!!\n" );
}
}

return 0;
}
void encrypt(char text[],const int *key,int i ) {
  printf("enter the message:\n" );
scanf("%s",text );
while (text[i]!='\0') {
  text[i]=text[i]+ *key;
  i++;
}

}
void decrypt(char text[],const int *key, int i){
if(text[0]!='\0'){
while (text[i]!='\0') {
  text[i]=text[i]- *key;
  i++;
}}
else
printf("first enter the message to encrypt it first\n" );
 }

void newKey(int *key) {
*key=(rand()%4)+1;
}
