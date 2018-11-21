#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

 
int main()
{
  int fifo1, fifo2; /*дескриптор FIFO*/
  char buf[1024];  

  /*Если файл с таким именем существует, удалим его*/
  unlink("/home/box/in.fifo");
  unlink("/home/box/out.fifo");

  /*Создаем FIFO*/
  if((mkfifo("/home/box/in.fifo", O_CREAT | O_RDWR)) == -1)
  {
    fprintf(stderr, "Невозможно создать fifo1\n");
    exit(0);
  }

  if((mkfifo("/home/box/out.fifo", O_CREAT | O_RDWR)) == -1)
  {
    fprintf(stderr, "Невозможно создать fifo2\n");
    exit(0);
  }

  /*Открываем fifo для чтения и записи*/
  if((fifo1=open("/home/box/in.fifo", O_RDWR)) == - 1)
  {
    fprintf(stderr, "Невозможно открыть fifo\n");
    exit(0);
  }


  if((fifo2=open("/home/box/out.fifo", O_RDWR)) == - 1)
  {
    fprintf(stderr, "Невозможно открыть fifo2\n");
    exit(0);
  }


  int n;
  while(1) {

    if( (n = read(fifo1, buf, sizeof(buf))) == -1) {
      fprintf(stderr, "Невозможно прочесть из FIFO\n");
    } else {
      buf[n] = '\0';
      // printf("Прочитано из FIFO : %s\n", buf1);
      write(fifo2, buf, strlen(buf)) ;
    }
  }
  
}