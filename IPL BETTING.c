#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long int random()
{
  int r;
  char ball[4][100] = {
    {"leg bye"},
    {"wide ball"},
    {"no ball"},
    {"wicket"}
  };
  srand(time(0));
  r=rand()%11;
  if(r<=6)
  {
    printf("RUNS SCORED = %d \n",r);
  }
  else
  {
    printf("BALL TYPE IS = %s ",ball[r-7]);
  }
  
  return r;
}


void function(float bal,float ubal)
{
  int urun,run;
  float bet;
  int i;
  float b[11]={1.60,2.00,4.00,6.00,8.00,10.00,12.00,1.5,2,2.5,15.00};
  printf("\nnumber of runs\t-  Return multiplier\t-   Enter code");
  printf("\ndot ball\t-  1.60   \t\t-\t0 ");
  printf("\nsingle run\t-  2.00  \t\t-\t1 ");
  printf("\ntwo runs\t-  4.00   \t\t-\t2 ");
  printf("\nthree runs\t-  6.00  \t\t-\t3 ");
  printf("\nfour runs\t-  8.00   \t\t-\t4 ");
  printf("\nfive runs\t-  10.00  \t\t-\t5 ");
  printf("\nsixruns   \t-  12.00 \t\t-\t6 "); 
  printf("\nbye or leg bye(l)  -  1.5  \t\t-\t7 ");
  printf("\nwide(w)   \t-  2.00 \t\t-\t8 ");
  printf("\nno ball(n)   \t-  2.5  \t\t-\t9");
  printf("\nwicket(q)    \t-  15.00  \t\t-\t10");
  

  printf("\n\nEnter your bet amount: ");
  scanf("%f",&bet);
  if(bet<=ubal)
  {
    printf("Enter your code : ");
    scanf("%d",&run);
    urun=random();
    if(urun==run)
    {
    printf("\nCONGRATULATIONS!!!!!\nYOU WON\n");

    ubal=bal-bet+(b[run]*bet);
    printf("UPDATED BALANCE=%f\n",ubal);
    }
   else
    {
    printf("\nBETTER LUCK NEXT TIME!!\nYOU LOST\n");
    ubal=ubal-bet;
    printf("\nUPDATED BALANCE=%f\n",ubal);
    }
    printf("\nDo you want to continue(1/0): " );
    scanf("%d",&i);
    if(i==1)
    {
        system("clear");
        printf("\nUPDATED BALANCE =%f\n",ubal);
     bal=ubal;
     function(bal,ubal);
    }
    else
    {
        system("clear");
        printf("\nREMAINING BALANCE=%f",ubal);
     printf("\nTHANKYOU FOR PLAYING");
    }
  }

  else
  {
    int i1;
    printf("\nYOU DO NOT HAVE ENOUGH BALANCE");
    printf("\nADD %f TO YOUR ACCOUNT",bet-ubal);
    printf("\nDO YOU WANT TO ADD BALANCE(1/0)? : ");
    scanf("%d",&i1);
    if(i1==1)
    {
      printf("Enter amount you want to add: ");
      scanf("%f",&bal);
      system("clear");
      ubal=ubal+bal;
      printf("CURRENT BALANCE= %f\n",ubal);
      function(bal,ubal);
    }
    else
    {
        system("clear");
         printf("\nREMAINING BALANCE= %f\n",ubal);
        
      printf("THANKYOU FOR PLAYING");
    }

  }
} 

void upper_string(char s[]) {
   int c = 0;
   
   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}


int main()
{ 
  float bal,ubal=0,bet;
  char username[100];
  printf("Enter Username: ");
  gets(username);
  upper_string(username);
  system("clear");

  printf("\t\t*******************************\t\t\n");
  printf("\t\t\t WELCOME ");
  puts(username);
  printf("\t\t*******************************\t\t\n");
  printf("Enter your balance: ");
  scanf("%f",&bal);
  ubal=bal;

 function(bal,ubal);
 
 return 0;
}

