#! /bin/bash

wal -q -i ~/.config/wallpapers/

source "$HOME/.cache/wal/colors.sh"

swww img $wallpaper \
    --transition-bezier .43,1.19,1,.4 \
    --transition-fps=60 \
    --transition-type="wipe" \
    --transition-duration=0.7 \
    --transition-pos "$( hyprctl cursorpos )"

hyprctl reload
sh ~/.config/scripts/reload-status-bars.sh
