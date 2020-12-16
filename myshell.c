#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int helpCommand(char **args);
int exitCommand(char **args);
int tekrar(char **args);
int islem(char **args);

char *komutDizisi[] = {"help", "exit", "tekrar","islem"}; 

int (*komutFonk[])(char **) = {&helpCommand,&exitCommand,&tekrar,&islem};  

int komutSayisi()
{
  return sizeof(komutDizisi) / sizeof(char *);
}

int helpCommand(char **args) //shelldeki help komutunu ifade ediyor.
{
  int i;
  printf("Bu shelldeki geçerli komutlar: \n");

  for (i = 0; i < komutSayisi(); i++)
  {
    printf("  %s\n", komutDizisi[i]);
  }

  return 1;
}

int exitCommand(char **args) //exit komutu çağrıldığında shell sonlandırılıyor
{
  printf("Shell'den Çıkılıyor...\n");
  return 0;
}


int tekrar(char **args) //tekrar komutu çağrıldığında fork ile tekrar.c çalıştırılıyor
{
  pid_t pid;
  int status, t;
  pid = fork();

  if (pid == 0)
  {

    if (args[1] == NULL && args[2] == NULL)
    {
      printf("Eksik ya da hatalı komut girdiniz.\n");
    }
    else if (args[1] == NULL || args[2] == NULL)
    {
      printf("Eksik ya da hatalı parametre girdiniz. Komuttan sonra iki parametre giriniz ! fatih 2 gibi\n");
    }

    else
    {
      t = execve(args[0], args, NULL);
    }
    return 0;
  }

  else if (pid < 0)
  {
    perror("error");
  }
  else {
      status = wait(&status);
    }
  return 1;
}

int islem(char **args){ //islem komutu çağrıldığında fork yapılarak işlem.c çalıştırılıyor.
  pid_t pid;
  int status, t;
  pid = fork();
  if (pid == 0)
  {
    //child process
    if (args[2] == NULL && args[3] == NULL)
    {
      printf("Komuttan sonra üç parametre girilmesi gerekmektedir. toplam 3 5 gibi\n");
    }
    
    else if (args[2] == NULL || args[2] == NULL)
    {
      printf("Eksik ya da hatalı parametre girdiniz. Komuttan sonra iki parametre giriniz ! 1 2 gibi\n");
    }
    else
    {
       t = execve(args[0], args, NULL);
    }
   
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
int otherCommands(char **args) //clear ve cat komutu için
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0)
  {
    if (execvp(args[0], args) == -1)
    {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  }
  else if (pid < 0)
  {
    perror("lsh");
  }
  else
  {
    do
    {
      wpid = waitpid(pid, &status, WUNTRACED); //return if a child has stopped
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int execute(char **args)
{

  if (args[0] == NULL) //komut girilmediğinde myshell>> yeni satırdan devam ediyor
  {
    return 1;
  }

  for (int i = 0; i < komutSayisi(); i++)  //girilen komut komutdizimizde var mı kontrol ediyoruz..
  {
    if (strcmp(args[0], komutDizisi[i]) == 0)
    {
      return (*komutFonk[i])(args);
    }
  }

  if (strcmp(args[0], "clear") == 0 || strcmp(args[0], "cat") == 0  || strcmp(args[0], "echo") == 0 )
  {
    return otherCommands(args);
  }

  else
  {
    printf("Yanlış Bir Komut Girdiniz. Geçerli komutlar için help komutunu kullanabilirsiniz.\n");
  }

  return 1;
}

char *readLine() //satır okuma  https://brennan.io/2015/01/16/write-a-shell-in-c/
{
  int bufsize = 100;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer)
  {
    fprintf(stderr, "Hata : allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    c = getchar();

    if ((c == '|') || (c == '\n') || (c==EOF)) // | ile birden çok komut girildiğinde de çalışıyor
    {
      buffer[position] = '\0';
      return buffer;
    }
    else
    {
      buffer[position] = c;
    }
    position++;

    if (position >= bufsize)
    {
      bufsize += 100;
      buffer = realloc(buffer, bufsize);
      if (!buffer)
      {
        fprintf(stderr, "Hata: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

#define BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
char **splitLine(char *komut)  //token ile satırı bölme https://brennan.io/2015/01/16/write-a-shell-in-c/
{

  int bufsize = BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token;
  

  if (!tokens)
  {
    fprintf(stderr, "Buffer Hatası\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(komut, TOK_DELIM);
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens)
      {
        fprintf(stderr, "Buffer Hatası\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int myshell(void)
{

  char *command;
  char **param;
  int status;
  do //programdan çıkılına kadar shell çalışmaya devam ediyor
  {
    printf("myshell>> ");
    command = readLine();
    param = splitLine(command);
    status = execute(param);

    free(command); //malloc ile kullandığımız kaynağı geri iade ediyoruz 
    free(param);
  } while (status);
}

int main()
{
  myshell();

  return EXIT_SUCCESS;
}
