#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    struct stat file_info;
    
    stat("example.txt", &file_info);
    return 0;
}
