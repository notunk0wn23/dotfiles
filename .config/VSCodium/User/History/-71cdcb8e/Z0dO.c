#include <stdio.h>

void installPackage(char *package)
{
    printf("Installing %s\n", package);

    int syscode = system("pacman -Ss %s", package);

    if (syscode == -1) {
        printf("Could not install package %s, failed to query pacman sync\n", package);
        return 1;
    } else if (syscode == 1) {
        printf("Could not install package %s, package not found\n", package);
        return 1;
    }
}

void uninstallPackage(char *package)
{
    printf("Uninstalling %s\n", package);
}

void downloadPackage(char *package)
{
    printf("Downloading %s\n", package);
}