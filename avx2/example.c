#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "mkem.h"
#include "randombytes.h"
#include <time.h>



int main(void)
{
  uint8_t pk[MKYBER_PUBLICKEYBYTES];
  uint8_t sk[MKYBER_SECRETKEYBYTES];
  uint8_t seed[KYBER_SYMBYTES];
 

  size_t i;
  
  randombytes(seed, KYBER_SYMBYTES);
 

clock_t t;
    t = clock();
     crypto_mkem_keypair(pk, sk, seed);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("%f@@", time_taken*1000);


  
  
  for (i = 0; i < MKYBER_PUBLICKEYBYTES; i++) {
    printf("%02x", pk[i]);
  } 
  printf("@@");
  for (i = 0; i < MKYBER_SECRETKEYBYTES; i++) {
    printf("%02x", sk[i]);
  }


  return 0;
}



