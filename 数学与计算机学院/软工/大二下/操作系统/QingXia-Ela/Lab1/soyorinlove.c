#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

const char *mygo = "It's Mygo!!!!!\n";
const char *crychic = "It's Crychic.\n";

void panic(char *msg)
{
    printf(1, "panic in soyorin love: %s", msg);
    for (;;)
        ;
}

int open_band()
{
    // define on `fcntl.h`
    int res = open("<id>.band", O_CREATE | O_RDWR);
    if (res == -1)
        panic("open fail");
    return res;
}

int main(int argc, char const *argv[])
{
    /**
     * Open before fork
     *
     * At this time the file is `open(child)` -> `open(parent)` -> `close(child)` -> `close(parent)`,
     * it will make 2 process hold at same time.
     *
     * Instead open after fork, the file keep open through child exit,
     * which means the write will still append on file tail.
     *
     * Example:
```txt
    - `It's Mygo!!!!!` -> child write

    - Close file.

    - `It's Mygo!!!!!\\n`
                        ↑
                        pointer to file tail, will begin write here

    - `It's Crychic.` -> parent write, append on file tail
```
     * To explain why xv6 run like this, you can check
     *
     * - `sysfile.c -> sys_open(): L317` -> create file symbol
     * - `file.c -> filealloc()` -> get `*file` from ftable
     * - `proc.c -> fork(): L206-L208` -> explain about ref rather copy file struct
     *
     * When 2 process open same file, they share same fd, and it point to same fd struct,
     * which cause their pointer offset is also share, and will not reset.
     */
    int fd = open_band();

    int pid = fork();
    if (pid == 0)
    {
        // print to console
        // console define at `file.h`
        // printf(1, mygo);
    }
    else
    {
        // printf(1, crychic);
        // wait for child exit
        wait();
    }

    /**
     *  Open after fork.
     *
     * At this time the file is `open(child)` -> `close(child)` -> `open(parent)` -> `close(parent)`,
     * which will make file ref reset, at this time parent process will write file at file begin.
     *
     * If you change crychic to `aaaa`, and run with it, you will found result change to `aaaa Mygo!!!!!`.
     *
     * Example like this:
     *
        ```txt
        - `It's Mygo!!!!!\\n` -> child write

        - Close file.

        - `It's Mygo!!!!!\\n`
           ↑
           pointer to file head, write will begin at here
        - `aaaa` -> parent write, cover old text
        ```
    * It also can explain why you run it at first, you will found `It's Mygo!!!!!` is disappear.
    */
    // int fd = open_band();
    int res = write(fd, pid == 0 ? mygo : crychic, strlen(pid == 0 ? mygo : crychic));
    // close file, it's useless
    // because kernel will help close when child process exit
    close(fd);
    if (res == -1)
        panic("write fail\n");

    exit();
}
