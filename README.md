darkwin
=======

### Overview

Darkwin is a basic command-line program that creates a single window with no
decorations (titlebar or borders). Additionally, the window is created with a
hint to have it always below other windows.

### Usage

Darkwin expects two arguments: A screen position and a size. The first is given
as `x`,`y` and the second is `width`x`height`. 

```
    # Create a window at x 0, y 389 that's 1280x720 in size.
    darkwin 0,389 1280x720
```

### Why

**Streaming**: I use this program to cover a portion of my desktop when I have a
Steam game that doesn't output 1280x720. It's to make the screen less bright for
my eyes since I like dark mode a lot.

**Template**: I sometimes use this project's CMakeLists.txt as a starting point
for other projects given how basic this project is.
