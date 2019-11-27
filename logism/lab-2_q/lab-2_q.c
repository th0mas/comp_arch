/* Copyright (C) 2017 Daniel Page <csdsp@bristol.ac.uk>
 *
 * Use of this source code is restricted per the CC BY-NC-ND license, a copy of 
 * which can be found via http://creativecommons.org (and should be included as 
 * LICENSE.txt within the associated archive or repository).
 */

#include "lab-2_q.h"

uint8_t cp_mod( uint8_t x, int n ) {
  return x ^ ( ( x >> n ) << n ); // COPIED SOLUTION!
}

int sign(int8_t x) {
  return (x >> BITSOF( x ) ) & 1;
}

int8_t neg(int8_t x) {
  return (x ^ -1) + 1;
}

void rep( int8_t x ) {
  printf( "%4d_{(10)} = ", x );

  for( int i = ( BITSOF( x ) - 1 ); i >= 0; i-- ) {
    printf( "%d", ( x >> i ) & 1 );
  }

  printf( "_{(2)}" );
  printf(" sign: %d neg: %d\n", sign(x), neg(x));
}

int main( int argc, char* argv[] ) {
  int8_t t;
  t =    0; rep( t );
  t =   +1; rep( t );
  t =   -1; rep( t );
  t = +127; rep( t ); 
  t = -127; rep( t ); 
  t = -128; rep( t ); 

  printf("5 mod 4 = %d\n", cp_mod(5, 2));
  printf("7 mod 4 = %d\n", cp_mod(7, 2));
  printf("10 mod 4 = %d\n", cp_mod(10, 2));

  // for( int i = -127; i < 128; i++) {
  //   rep(i);
  // }

  return 0;
}
