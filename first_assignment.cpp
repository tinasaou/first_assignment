#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Given grammar
<Z>::=(<K>)
<K>::=<G><M>
<G>::=ν|<Z>
<M>::=-<K>|+<K>|ε
*/


void generate_Z();
void generate_K();
void generate_G();
void generate_M();


int main()
{
  time_t t;
  srand((unsigned) time(&t));

  generate_Z();
  return 0;
}


void generate_Z()
{
  putchar('(');
  generate_K();
  putchar(')');
}

void generate_K()
{
  generate_G();
  generate_M();
}

void generate_G()
{
  switch( rand() % 2) 
  {
  case 0:
    putchar('v');
  break;
  case 1:
    generate_Z();
  break;
  }
}

void generate_M()
{
  switch ( rand() % 5) 
  {
  case 0:
    putchar('-');
    generate_K();
  break;
  case 1:
    putchar('+');
    generate_K();
  break;
  default: 
    // empty
  break;
  }
}