*This project has been created as part of the 42 curriculum by mprokope.*

# So Long

## Description
This is a small 2D game project where the player navigates a map, collects all collectibles, and reaches the exit.  

### Compilation
```bash
cd <name of the folder you git cloned>
make
```
## Instructions
Map must be rectangular and be surrounded by walls(1). There can be only 1 player(P), one Exit(E) and at least one Collectible(C).
There should be only Map inside of .ber file. Oh, and map file must be with .ber extension.
### Examples
```bash
./so_long maps/map.ber
```
Make usage:
To recompile the binary use:
```bash
make re
```
To clean a object files use:
```bash
make clean
```
And to clean all use:
```bash
make fclean
```

## Extras
Minimal map example:
```
111111
1P0101
100001
1C0E01
111111
```
## Resources
https://42-cursus.gitbook.io/guide - in this resource i found the best guide for MLX.
https://harm-smits.github.io/42docs/libs/minilibx/events.html - the only guide that allowed me to understand it.
https://www.geeksforgeeks.org/dsa/a-search-algorithm/ - A\* algo explained.
and some other sources i don't remmeber..
