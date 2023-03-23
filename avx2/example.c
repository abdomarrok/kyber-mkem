#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "mkem.h"
#include "randombytes.h"

int main(void)
{
  uint8_t pk[MKYBER_PUBLICKEYBYTES];
  uint8_t sk[MKYBER_SECRETKEYBYTES];
  uint8_t seed[KYBER_SYMBYTES];
 

  size_t i;
  
  randombytes(seed, KYBER_SYMBYTES);
  crypto_mkem_keypair(pk, sk, seed);
  
  
  for (i = 0; i < MKYBER_PUBLICKEYBYTES; i++) {
    printf("%02x", pk[i]);
  } 
  printf("@");
  for (i = 0; i < MKYBER_SECRETKEYBYTES; i++) {
    printf("%02x", sk[i]);
  }
}
