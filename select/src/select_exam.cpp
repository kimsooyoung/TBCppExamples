#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
  int fd, n, ret;

  char buf[128];
  struct timeval tv;

  fd_set readfds;
  fd = open("/home/kimsooyoung/Documents/test1.txt", O_RDONLY);

  if(fd < 0){
        perror("file open error ");
        exit(0);
  }
  memset(buf, 0x00, 128);
  
  FD_ZERO(&readfds);
  while(1){
        FD_SET(fd,&readfds);

        ret = select(fd+1, &readfds, NULL, NULL, NULL);

        if(ret == -1){
                perror("select error ");
                exit(0);
        }

        if(FD_ISSET(fd, &readfds)){
                while(( n = read(fd, buf, 128)) > 0)
                        printf("%s",buf);
        }

        memset(buf, 0x00, 128);
        usleep(1000);
  }
}