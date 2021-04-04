#include "types.h"
#include "user.h"
#include "fcntl.h"

int main()
{
    int n = 1;
    for (n = 1; n <= 7; n++)
    {
        int fd = open("README", O_RDONLY);

        if (fd == -1)
        {
            printf(1, "Opening error");
            return 1;
        }
        char string[100];
        if (read(fd, string, 10) == -1)
        {
            printf(1, "Reading -> lseek error\n");
            break;
        }
        printf(1, "Case : %d\nStarting read : %s\n", n, string);
        switch (n)
        {
        case 1:
            if (lseek(fd, 2, SEEK_END))
            {
                printf(1, "Lseek error\n");
                continue;
            }
            break;
        case 2:
            if (lseek(fd, -20, SEEK_END))
            {
                printf(1, "Lseek error\n");
                continue;
            }
            break;
        case 3:
            if (lseek(fd, -30, SEEK_CUR))
            {
                printf(1, "Lseek error\n");
                continue;
            }
            break;
        case 4:
            if (lseek(fd, -5, SEEK_CUR))
            {
                printf(1, "Lseek error\n");
                continue;
            }
            break;
        case 5:
            if (lseek(fd, 10, SEEK_CUR) == -1)
            {
                printf(1, "Lseek error\n");
                continue;
            }
            break;
        case 6:
            if (lseek(fd, -10, SEEK_SET) == -1)
            {
                printf(1, "Lseek error\n");
                continue;
            }
            break;
        case 7:
            if (lseek(fd, 10, SEEK_SET) == -1)
            {
                printf(1, "Lseek error\n");
                continue;
            }
            break;
        }
        if (read(fd, string, 10) == -1)
        {
            printf(1, "lseek -> Reading error\n");
            return 1;
        }
        printf(1, "Ending read : %s\n", string);
        close(fd);
    }
    exit();
}