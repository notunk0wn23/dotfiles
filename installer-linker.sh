# Second install script, creates symlinks to the dotfiles
echo "This will delete the follwing config folders:

alacritty
hypr
rofi
scripts
VSCodium
wal
wallpapers
waybar
"

read -p "Are you sure? " -n 1 -r
echo
if [[ ! $REPLY =~ ^[Yy]$ ]]
then
    exit 1
fi

dotfileFiles=(
    ".config/starship.toml"
    ".bashrc"
    ".bash_profile"
    ".viminfo"
    "gtkrc-2.0"
    ".gitconfig"   
)

dotfileFolders=(
    "alacritty"
    "hypr"
    "rofi"
    "scripts"
    "VSCodium"
    "wal"
    "wallpapers"
    "waybar"
)

for folder in "${dotfileFolders[@]}"; do
    rm -rf "$HOME/.config/$folder"
    ln -s "$HOME/.dotfiles/$folder" "$HOME/$folder"
done

