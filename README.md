# 42_miniRT
## My first RayTracer with miniLibX.
This project is about creating a Ray Tracer in C. A Ray Tracer is a program that accurately simulates the illumination of objects by light sources by tracing how the light rays interact with the objects and the camera (eye).
## Project Goals and rules
The program takes in a ".rt" file as a parameter, that will set how the scene will look like. The scene contains:
### Camera
```
* Identifier: C
* Position: x, y, z
* Orientation vector: x, y, z (normalized)
* FOV: from 0 to 180 degrees
```
### Ambient Light
```
* Identifier: A
* Ambient lighting ratio in range [0.0,1.0]: 0.2
* R,G,B colors in range [0-255]: 255, 255, 255
```
### Light Source
```
* Identifier: L
* x,y,z coordinates of the light point: -40.0,50.0,0.0
* The light brightness ratio in range [0.0,1.0]: 0.6
* (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
```
### Objects
#### Sphere
```
* Identifier: sp
* x,y,z coordinates of the sphere center: 0.0,0.0,20.6
* The sphere diameter: 12.6
* R,G,B colors in range [0-255]: 10, 0, 255
```
#### Plane
```
* Identifier: pl
* x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
* 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
* R,G,B colors in range [0-255]: 0,0,225
```
#### Cylinder
```
* identifier: cy
* x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
* 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
* The cylinder diameter: 14.2
* The cylinder height: 21.42
* R,G,B colors in range [0,255]: 10, 0, 255
```
### Example .rt file for scene
```
A 0.2 255,255,255

C -50,0,20 0,0,1 70
L -40,0,30 0.7 255,255,255

pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```
## Tasks
- [ ] Minilibx - Set up functional window management: opening, free, closing, ESC
- [ ] Parser - Analyze the file and create structures for each object and light.  
- [ ] Utilities  
  - [ ] Functions to calculate vector sum, multiplication, calculate the simetric of a vetor, magnitude and to normalize  
  - [ ] Function - dot product  
  - [ ] Matrizes - criar funcoes: invert, transpose, multiply  
  - [ ] Matrizes - funcoes transformacao de objetos: translation and rotation  
  - [ ] Create ray structure - vector and starting point (camera).  
  - [ ] Function to calculate the first intersection between a ray and an object.  
  - [ ] Functions to calculate the vectors associated to an intersection (normal, eye, light and reflection)  
  - [ ] Diffuse_light = object_color * light_intensity * dot_product(normal_vector, light_vector)  
  - [ ] Function color_pixel_hit = diffuse + ambient light
  - [ ] Shadows - Implement shadowing

## References
* jburlama: https://github.com/Jburlama/miniRT?tab=readme-ov-file
* Ray Tracing by Joao Manuel Brisson Lopes: https://disciplinas.ist.utl.pt/leic-cg/textos/livro/Ray%20Tracing.pdf
* The Raytracer Challenge: https://www.bharatchan.com/images/uploads/g/173159035800090.pdf
* Shader Toy: https://www.shadertoy.com/view/tl23Rm
* Ray Tracing in one week: https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class/colorutilityfunctions


## Installing and Using
To download, clone the repository into your device and navigate inside using `cd push_swap`, then typing  `make` to compile all the functions and generate the executable push_swap, which you can run as follows:

## Disclaimer
At 42 School our projects have to adhere to the 42 Norm of coding standards and good practices. These include:
- Maximum 25 lines per function and 5 functions per file;
- No variable declarations and assignments in the same line;
- Forbiden structures: `for`, `switch`, `goto` and `case`;
- No more than 5 variables per function.

All of my projects strictly adhere to this Norm, that promotes code simplicity and readability.

