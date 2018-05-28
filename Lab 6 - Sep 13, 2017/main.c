#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{


    char str[100];

    printf("Please input the string!\n");

    gets(str);

    char *buf = str;

    int fd = open( "demo.txt", O_RDWR | O_TRUNC);

    int ret = write(fd, buf, strlen(str));

    ret = close(fd);

    printf("Written to file\n");

    printf("%s", str);

    return 0;
}
