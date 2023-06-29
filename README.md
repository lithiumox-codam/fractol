<!-- background should be white and rounded corners -->
<p align="center">
  <img src="https://d33wubrfki0l68.cloudfront.net/eb7c586de8a2960c7c958dc46601035e531ed893/cd160/images/general/logo_codam_black-eb7c586d.png" alt="Codam logo" width="200"/>
</p>

# Fract-ol - [![Norminette check](https://github.com/lithiumox-codam/fractol/actions/workflows/norminette.yml/badge.svg)](https://github.com/lithiumox-codam/fractol/actions/workflows/norminette.yml) 
Program that visualizes the julia & mandelbrot set using MLX42

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Usage](#usage)
* [Fractals](#fractals)
* [Controls](#controls)
* [Status](#status)

## General info
This project is part of the Codam Coding College curriculum. The goal of this project is to create a program that visualizes the julia & mandelbrot set using MLX42.

## Technologies
Project is created with:
* C language
* MLX42
* Make

## Setup
To run this project, install it locally using Make:

```
$ cd ../fractol
$ make
```

## Usage
```
$ ./fractol [fractal] (optional constant for julia set)
```

### Fractals
* mandelbrot
* juli

### Controls
* Zoom in: scroll up
* Zoom out: scroll down
* Move: arrow keys or wasd
* Change fractal: tab
* Exit: esc

## Status
Project is: _in progress_
