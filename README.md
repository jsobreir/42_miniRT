# 42_miniRT
## Concepts Learned
### Tuples (vectors)
*Adding/Subtracting/Negating/Scaling
*Magnitude/Normalization
### Matrices
* Matrix Multiplication
*   By another matrix
*   By a tuple
* Identity Matrix
* Transposing Matrices
* Determinant
*   Submatrix
*   Minor
*   Cofactor
*   Determinant of Larger matrices

Tasks:
[] Parser - Analyze the file and create structures for each object and light.  
[] Utilities  
  [] Functions to calculate vector sum, multiplication, calculate the simetric of a vetor, magnitude and to normalize  
  [] Function - dot product  
  [] Matrizes - criar funcoes: invert, transpose, multiply  
  [] Matrizes - funcoes transformacao de objetos: translation and rotation  
  [] Create ray structure - vector and starting point (camera).  
  [] Function to calculate the first intersection between a ray and an object.  
  [] Functions to calculate the vectors associated to an intersection (normal, eye, light and reflection)  
  [] Diffuse_light = object_color * light_intensity * dot_product(normal_vector, light_vector)  
  [] Function color_pixel_hit = diffuse + ambient light  
[] Graficos basicos  
  [] Criate window and add functions esc e cross (exit)  