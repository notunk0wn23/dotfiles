#include <stdio.h>

void installPackage(char *package)
{
    printf("Installing %s\n", package);

    bool aur = false;
    bool sync = false;

    int syscode = system("pacman -Ss %s", package);

    if (syscode == -1) {
        printf("Could not install package %s, failed to query pacman sync\n", package);
        return 1;
    } else if (syscode == 0) {
        bool sync = true;
    }

    if (!sync) {
        int syscode = system("yay -Ss %s", package);

        if (syscode == -1) {
            printf("Could not install package %s, failed to query AUR \n", package);
            return 1;
        } else if (syscode == 1) {
            printf("Could not install package %s, package not found or yay is not installed\n", package);
            return 1;
        } else if (syscode == 0) {
            bool aur = true;
        }
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