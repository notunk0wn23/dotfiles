#!/bin/bash
sleep 0.5
killall -e xdg-desktop-portal-wlr
killall xdg-desktop-portal
/usr/lib/xdg-desktop-portal-wlr &
sleep 0.5
/usr/lib/xdg-desktop-portal &