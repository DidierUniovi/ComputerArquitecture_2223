#include <stdio.h>
#include <stdlib.h>

#define PRIME_NUM 70000   //Prime numbers to be generated
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

const unsigned int nTimes = 300;

void primeGenerator(int v1[], int v2[]);
BOOLEAN checkPrime_fast (int number);
void powerTo(int v1[], int exp);
int getRandom();

int main()
{
  int v1[PRIME_NUM/2];
  int v2[PRIME_NUM/2];

  primeGenerator(v1, v2);

  int v3[PRIME_NUM/2];
  srand(1);
  for (int i = 0; i<nTimes; i++){
    for (int j = 0; j<PRIME_NUM/2; j++){
      v3[j] = getRandom();
      
    }
  }

  powerTo(v3, 3);
  powerTo(v3, 3);
  for (int k = 0; k<PRIME_NUM/2; k++){
    v3[k] = getRandom();
  }
  powerTo(v3, 3);
  powerTo(v3, 3);

  return 0;
}

void primeGenerator(int v1[], int v2[]){
  v1[0] = 1;
  v2[0] = 2;
  int count = 2; 
  BOOLEAN isPrime;
  int i = 0;

  for (i = 3; count != PRIME_NUM; i++){
    isPrime = checkPrime_fast(i);    
    if (isPrime) {
      if (count % 2 == 0)
        v1[count/2] = i;
      else
        v2[count/2] = i;

      count++;
    }
  }

}

BOOLEAN checkPrime_fast(int number) {
  BOOLEAN isPrime = TRUE;
  for (int j = 2; j*j<=number; j++){
    if (number % j == 0) {
      return FALSE;
    }
  }
  
  return TRUE;
}

void powerTo(int v1[], int exp){
  int base;
  for (int i = 0; i<PRIME_NUM/2; i++){
    base = v1[i];
    for (int j = 1; j<exp; j++){
      v1[i] = v1[i] * base;
    }
  }
}

int getRandom(){  //Random int in [1,50]
  return (rand() % 50 + 1);
}

