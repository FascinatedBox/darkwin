darkwin
=======

### Overview

Darkwin is a basic command-line program that creates a single window with no
decorations (titlebar or borders). Additionally, the window is created with a
hint to have it always below other windows.

### Usage

```
Create borderless window

Options:
  -h, --help     Displays help on commandline options.
  --help-all     Displays help including Qt specific options.
  -v, --version  Displays version information.
  -c <color>     hex color (RRGGBB) (default: 000000)

Arguments:
  x              Window x coordinate
  y              Window y coordinate
  height         Window height
  width          Window width
```

### Why

**Streaming**: I use this program to cover a portion of my desktop when I have a
Steam game that doesn't output 1280x720. It's to make the screen less bright for
my eyes since I like dark mode a lot.

**Template**: I sometimes use this project's CMakeLists.txt as a starting point
for other projects given how basic this project is.
