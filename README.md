# Cub3d

This project is a 3D graphical representation of the inside of a maze from a first-person perspective, using the Ray-Casting principles. The program will take as a first argument a scene description file with the .cub extension and display the image in a window.

## Project specifications

For the project we had to use the miniLibX.

<b>Allowed functions:</b>
``` open, close, read, write, printf, malloc, free, perror, strerror, exit, All functions of the math library (-lm man man 3 math), All functions of the MinilibX ```

### Map format
The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation.\
The map must be closed/surrounded by walls, if not the program must return an error.\
Except for the map content, each type of element can be separated by one or more empty line(s).\
Except for the map content which always has to be the last, each type of element can be set in any order in the file.\
Except for the map, each type of information from an element can be separated by one or more space(s).\
The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.\
Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as:\
North texture: NO ./path_to_the_north_texture\
South texture: SO ./path_to_the_south_texture\
West texture: WE ./path_to_the_west_texture\
East texture: EA ./path_to_the_east_texture\
Floor color: F 220,100,0\
Ceiling color: C 225,30,0

### Keyboard controls
The left and right arrow keys of the keyboard allow you to look left and right in the maze.\
The W, A, S, and D keys allow you to move the point of view through the maze.\
Pressing ESC

## How to use

The current version of Cub3d is developed and tested on macOS.

<b>Requirements:</b>
- GCC / CLANG Compiler
- GNU Make

```
git clone https://github.com/srein91/cub3d.git cub3d
```
```
cd cub3d && make
```
```
./cub3D maps/<map name>
```

![alt text](https://github.com/SRein91/Cub3d/blob/main/Cub3d.png?raw=true)

<br>
<hr>
<b>This is a 42 project which has to be written in C in accordance to the 42 School Norm.<br></b>
<br>

> #### Sample restrictions:
> - All variables have to be declared and aligned at the top of each function
> - Each function can not have more then 25 lines
> - Projects should be created with allowed std functions otherwise it is cheating
