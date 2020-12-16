#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//bu program fork ile çağrılmaktadır
//seçilen komuta göre tekrar fork yapılarak topla veya cikar programlarına gitmektedir.

int main(int arg, char *argv[]) {
  
  pid_t pid;
  int status, t;
  pid = fork();
  if (pid == 0){
      t = execve(argv[1], argv, NULL);
      return 0;
  }
  else if (pid < 0)
  {
    perror("error");
  }

  else
  {
    status = wait(&status);
  }
  return 1;
}