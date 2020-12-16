#include <stdio.h>
#include <stdlib.h>

//bu program fork ile çağrıldığında çalışmaktadır.
//1.argümanı 2. argüman kadar ekrana yazdırmaktadır.

int main(int arg, char *argv[]) {
  int n = atoi(argv[2]);
  //char name = argv[1];
  int i;
  for(i=1;i<=n;i++){
    printf("%s \n",argv[1]);
  }

  return 0;
}
