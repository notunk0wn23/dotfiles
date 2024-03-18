#include <stdio.h>
#include <string.h>


enum Command {
    INSTALL,
    UNINSTALL,
    DOWNLOAD
};

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

    if (strcmp(argv[1], "install") == 0) {
        printf("Installing %s\n", argv[2]);
    }
    return 0;
}