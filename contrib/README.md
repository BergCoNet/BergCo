
Debian
====================
This directory contains files used to package bergcod/bergco-qt
for Debian-based Linux systems. If you compile bergcod/bergco-qt yourself, there are some useful files here.

## bergco: URI support ##


bergco-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install bergco-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your bergcoqt binary to `/usr/bin`
and the `../../share/pixmaps/bergco128.png` to `/usr/share/pixmaps`

bergco-qt.protocol (KDE)

