#include <stdio.h>
#include <stdlib.h>

//bu program fork ile çağrılmaktadır ve komut satırına girilen parametleri çıkartarak
//ekranda göstermektedir. Örn: islem cikar 5 4 >> (5) - (4)=1 
int main(int arg, char *argv[]) {
 

  int first = atoi(argv[2]);
  int second = atoi(argv[3]);
  int t = first - second;
  printf("(%d) - (%d) = %d\n",first, second, t);
  return 0;
}


