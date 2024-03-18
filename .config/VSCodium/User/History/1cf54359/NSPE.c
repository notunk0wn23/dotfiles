#include <stdio.h>

void printUsage()
{
    printf("Usage: shiba <command> <package>\n\n");

    printf("Commands:\n");
    printf("  install <package> - Install a package, from the AUR or Sync\n");
    printf("  uninstall <package> - Removes a package that is already installed\n");
    printf("  download <package> - Downloads a package, but does not install it. Good if you need specific parameters for the PKGBUILD.\n");
};

int main(int argc, char *argv[])
{
    if (argv[1] == NULL) {
        printUsage();
        return 1;
    }

    printf("Hello, World!\n");
    return 0;
}