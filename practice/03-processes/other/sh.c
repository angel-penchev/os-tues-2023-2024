#include <unistd.h>

int main(int argc, char const *argv[])
{
    execl("/bin/sh", "/bin/sh", NULL);
    return 0;
}
