
installPackagesPacman() {
    for package in "$@"; do
        sudo pacman -S "$package" --noconfirm
    done

    return 0
}

installPackagesAur() {
    for package in "$@"; do
        yay -S "$package" --noconfirm
    done

    return 0
}