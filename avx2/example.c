#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "mkem.h"
#include "randombytes.h"
#include <time.h>

int main(void)
{
  uint8_t *pk;
  uint8_t *sk;
  uint8_t seed[KYBER_SYMBYTES];
  uint8_t *c2;                // private
  uint8_t c1[MKYBER_C1BYTES]; // public
  uint8_t key_a[KYBER_SSBYTES]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
  uint8_t key_b[KYBER_SSBYTES]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

  size_t i;

  pk = malloc(MKYBER_PUBLICKEYBYTES);
  sk = malloc(MKYBER_SECRETKEYBYTES);
  c2 = malloc(MKYBER_C2BYTES);

 // randombytes(seed, KYBER_SYMBYTES);

  

  clock_t t;
  t = clock();
  crypto_mkem_keypair(pk, sk, seed);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("%f@@", time_taken * 1000);

 randombytes(key_a, KYBER_SSBYTES);

    t = clock();
  crypto_mkem_enc(c1, &c2, key_a, seed, 1, &pk);
    t = clock() - t;
     time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
     printf("%f@@", time_taken * 1000);

      t = clock();
  crypto_mkem_dec(key_b, c1, c2, sk);
      t = clock() - t;
     time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
     printf("%f", time_taken * 1000);
/*
  for (i = 0; i < MKYBER_PUBLICKEYBYTES; i++)
  {
    printf("%02hhx", pk[i]);
  }
  printf("@@");
  for (i = 0; i < MKYBER_SECRETKEYBYTES; i++)
  {
    printf("%02hhx", sk[i]);
  }
  printf("\n");
 
  printf("@@");
  for (i = 0; i < KYBER_SSBYTES; i++)
  {
    printf("%02hhx", key_a[i]);
  }
  printf("\n");
  printf("@@");
  for (i = 0; i < KYBER_SSBYTES; i++)
  {
    printf("%02hhx", key_b[i]);
  }
  printf("\n");
*/
  return 0;
}