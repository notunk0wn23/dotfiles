#include <stdio.h>

void printUsage()
{
    printf("Usage: shiba <command> <package>\n\n");

    printf("Commands:\n");
    printf("  install <package>\n");
    printf("  uninstall <package>\n");
    printf("  download <package>\n");
}

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) {
        printUsage();
        return 1;
    }

    printf("Hello, World!\n");
    return 0;
}