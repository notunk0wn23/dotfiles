#!/bin/bash

killall -e waybar 
killall -e ags
killall -e eww

hyprctl dispatch exec waybar