source ./functions.sh

installlist-pacman=(
    # Tools and Packages from pacman

    #loginmanager
    "sddm"


    # Terminal 
    "alacritty" # Terminal Emulator
    "kitty" # Used for Command Bar & Neovim
    "starship" # Prompt

    # Fonts
    "ttf-firacode-nerd"
    "ttf-font-awesome"
    "ttf-fira-sans"
    "ttf-fira-code"

    # Audio
    "pavucontrol" # Volume Control

    # Desktop Stuff
    "xdg-desktop-portal-hyprland"
    "xdg-desktop-portal-gtk"
    

    # Text Editor
    "sublime-text-4" # Sublime Text 4
    "neovim" # Neovim

    # File Manager
    "thunar" # PCManFM

    # Networking & Web Browser
    "networkmanager"
    "networkmanager-applet" # Netowork Manager, but with a GUI
    "networkmanager-openvpn" # If you want to use a VPN (I dont but if you want to)

    "blueman" # Bluetooth Manager
    "bluez"
    "bluez-utils"

    "chromium" # Web Browser

    "rofi" # Application launcher


    "waybar" # Status Bar

)

installlist-aur=(
    # Tools and Packages from AUR
    "hyprland-git" # Use the Git version of Hyprland

    "pfetch" # literally just for flexing
    "swww" # SWWW because hyprpaper kinda sucks

    "pywal" # Color-based theming
    "wlogout" # Logout Menu

    "VSCodium-bin" # quite literally better vscode
)

installPackagesPacman "${installlist-pacman[@]}"
installPackagesAur "${installlist-aur[@]}"


echo "Finished! Make sure you run a system update, then reboot."