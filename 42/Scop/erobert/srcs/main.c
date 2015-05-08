/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 09:50:41 by erobert           #+#    #+#             */
/*   Updated: 2015/05/08 16:59:29 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <math.h>
// storage for Matrices
float projMatrix[16];
float viewMatrix[16];
 
// ----------------------------------------------------
// VECTOR STUFF
//
 
// res = a cross b;
void crossProduct( float *a, float *b, float *res) {
 
    res[0] = a[1] * b[2]  -  b[1] * a[2];
    res[1] = a[2] * b[0]  -  b[2] * a[0];
    res[2] = a[0] * b[1]  -  b[0] * a[1];
}
 
// Normalize a vec3
void normalize(float *a) {
 
    float mag = sqrt(a[0] * a[0]  +  a[1] * a[1]  +  a[2] * a[2]);
 
    a[0] /= mag;
    a[1] /= mag;
    a[2] /= mag;
}
 
// ----------------------------------------------------
// MATRIX STUFF
//
 
// sets the square matrix mat to the identity matrix,
// size refers to the number of rows (or columns)
void setIdentityMatrix( float *mat, int size) {
 
    // fill matrix with 0s
    for (int i = 0; i < size * size; ++i)
		mat[i] = 0.0f;
 
    // fill diagonal with 1s
    for (int i = 0; i < size; ++i)
        mat[i + i * size] = 1.0f;
}
 
//
// a = a * b;
//
void multMatrix(float *a, float *b) {
 
    float res[16];
 
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            res[j*4 + i] = 0.0f;
            for (int k = 0; k < 4; ++k) {
                res[j*4 + i] += a[k*4 + i] * b[j*4 + k];
            }
        }
    }
    ft_memcpy(a, res, 16 * sizeof(float));
 
}
 
// Defines a transformation matrix mat with a translation
void setTranslationMatrix(float *mat, float x, float y, float z) {
 
    setIdentityMatrix(mat,4);
    mat[12] = x;
    mat[13] = y;
    mat[14] = z;
}
 
// ----------------------------------------------------
// Projection Matrix
//
 
void buildProjectionMatrix(float fov, float ratio, float nearP, float farP) {
 
    float f = 1.0f / tan (fov * (M_PI / 360.0));
 
    setIdentityMatrix(projMatrix,4);
 
    projMatrix[0] = f / ratio;
    projMatrix[1 * 4 + 1] = f;
    projMatrix[2 * 4 + 2] = (farP + nearP) / (nearP - farP);
    projMatrix[3 * 4 + 2] = (2.0f * farP * nearP) / (nearP - farP);
    projMatrix[2 * 4 + 3] = -1.0f;
    projMatrix[3 * 4 + 3] = 0.0f;
}
 
// ----------------------------------------------------
// View Matrix
//
// note: it assumes the camera is not tilted,
// i.e. a vertical up vector (remmeber gluLookAt?)
//
 
void setCamera(float posX, float posY, float posZ,
               float lookAtX, float lookAtY, float lookAtZ) {
 
    float dir[3], right[3], up[3];
 
    up[0] = 0.0f;   up[1] = 1.0f;   up[2] = 0.0f;
 
    dir[0] =  (lookAtX - posX);
    dir[1] =  (lookAtY - posY);
    dir[2] =  (lookAtZ - posZ);
    normalize(dir);
 
    crossProduct(dir,up,right);
    normalize(right);
 
    crossProduct(right,dir,up);
    normalize(up);
 
    float aux[16];
 
    viewMatrix[0]  = right[0];
    viewMatrix[4]  = right[1];
    viewMatrix[8]  = right[2];
    viewMatrix[12] = 0.0f;
 
    viewMatrix[1]  = up[0];
    viewMatrix[5]  = up[1];
    viewMatrix[9]  = up[2];
    viewMatrix[13] = 0.0f;
 
    viewMatrix[2]  = -dir[0];
    viewMatrix[6]  = -dir[1];
    viewMatrix[10] = -dir[2];
    viewMatrix[14] =  0.0f;
 
    viewMatrix[3]  = 0.0f;
    viewMatrix[7]  = 0.0f;
    viewMatrix[11] = 0.0f;
    viewMatrix[15] = 1.0f;
 
    setTranslationMatrix(aux, -posX, -posY, -posZ);
 
    multMatrix(viewMatrix, aux);
}



static void			ft_init_gl(t_env *e)
{
	GLchar const	*vertex_shader = e->v_shader;
	GLchar const	*fragment_shader = e->f_shader;

	glClearColor(0.1, 0.25, 0.66, 0.3);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glGenBuffers(1, &e->vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, e->vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, e->buffer_size * sizeof(t_vertex), e->vertices, GL_DYNAMIC_DRAW);
	glGenVertexArrays (1, &e->vertex_array);
	glBindVertexArray (e->vertex_array);
	glEnableVertexAttribArray (0);
	glBindBuffer(GL_ARRAY_BUFFER, e->vertex_buffer);
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	e->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(e->vertex_shader, 1, &vertex_shader, NULL);
	glCompileShader(e->vertex_shader);
	e->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(e->fragment_shader, 1, &fragment_shader, NULL);
	glCompileShader(e->fragment_shader);
	e->shader_program = glCreateProgram();
	glAttachShader(e->shader_program, e->fragment_shader);
	glAttachShader(e->shader_program, e->vertex_shader);
	glLinkProgram(e->shader_program);
}
#include <stdio.h>
int					main(int ac, char **av)
{
	t_env			e;
	t_vertex		vbd[MAX_SIZE];
	GLuint			ibd[MAX_SIZE];

	if (ac != 2)
		return (ft_error("scop obj", 0));
	if (ft_load_obj(&e, vbd, ibd, av[1]))
		return (ft_error("obj load error", -1));
	if (ft_load_shader(&e))
		return (ft_error("shader load error", -1));
	e.size[0] = 1024;
	e.size[1] = 768;
	e.mlx_ptr = mlx_init();
	if (!e.mlx_ptr)
		return (ft_error("mlx init error", -1));
	e.win_ptr = mlx_new_opengl_window(e.mlx_ptr, e.size[0], e.size[1], av[0]);
	if (!e.win_ptr)
		return (ft_error("win init error", -1));
	ft_init_gl(&e);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float ratio = (1.0f * 1024.) / 768.;
    buildProjectionMatrix(53.13f, ratio, 1.0f, 30.0f);

	setCamera(0, 0, -10, 0, 0, 1);

	glUseProgram(e.shader_program);
	glUniform1f(glGetUniformLocation(e.shader_program, "x"), 0.);
	glUniform1f(glGetUniformLocation(e.shader_program, "y"), 0.);
	glUniform1f(glGetUniformLocation(e.shader_program, "z"), 0.);
	glUniform1f(glGetUniformLocation(e.shader_program, "zoom"), 1);

	printf("%f %f %f %f\n", projMatrix[0], projMatrix[1], projMatrix[2], projMatrix[3]);
	printf("%f %f %f %f\n", projMatrix[4], projMatrix[5], projMatrix[6], projMatrix[7]);
	printf("%f %f %f %f\n", projMatrix[8], projMatrix[9], projMatrix[10], projMatrix[11]);
	printf("%f %f %f %f\n", projMatrix[12], projMatrix[13], projMatrix[14], projMatrix[15]);

	glUniformMatrix4fv(glGetUniformLocation(e.shader_program, "projMatrix"), 1, 0, projMatrix);
	glUniformMatrix4fv(glGetUniformLocation(e.shader_program, "viewMatrix"), 1, 0, viewMatrix);
	GLfloat		proj[16];

	proj[0] = 1;
	proj[1] = 0;
	proj[2] = 0;
	proj[3] = 0;

	proj[4] = 0;
	proj[5] = 1;
	proj[6] = 0;
	proj[7] = 0;

	proj[8] = 0;
	proj[9] = 0;
	proj[10] = 1;
	proj[11] = 0;

	proj[12] = 0;
	proj[13] = 0;
	proj[14] = 0;
	proj[15] = 1;

/*	float ratio = (1.0f * 1024.) / 768.;
	float fov = 120.13f;
	float farP = 50.f;
	float nearP = 1.f;

	float f = 1.0f / tan (fov * (M_PI / 360.0));
	proj[0] = f / ratio;
    proj[1 * 4 + 1] = f;
    proj[2 * 4 + 2] = (farP + nearP) / (nearP - farP);
    proj[3 * 4 + 2] = (2.0f * farP * nearP) / (nearP - farP);
    proj[2 * 4 + 3] = -1.0f;
    proj[3 * 4 + 3] = 0.0f;
*/
//	glUniformMatrix4fv(glGetUniformLocation(e.shader_program, "proj"), 1, 0, proj);



	glBindVertexArray(e.vertex_array);
	glDrawArrays(GL_TRIANGLES, 0, e.buffer_size * 3);
	mlx_opengl_swap_buffers(e.win_ptr);
	mlx_hook(e.win_ptr, 2, 3, ft_key_hook, &e);
	mlx_loop_hook(e.mlx_ptr, ft_loop_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
