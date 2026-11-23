#ifndef MINIRT_H
# define MINIRT_H

/* <===================================> */
// Macro Declarations
# define WIDTH 800		// Window/Image width
# define HEIGHT 600		// Window/Image height
# define E 1			// 'Error' return value
# define S 0			// 'Success' return value
# define U -1			// 'Undefined' return value (used for any type of special error that isn't defined)
# define RATIO 0		// ratio type for ft_def_atod
# define ORIENTATION 1	// orientation type for ft_def_atod
# define FOV 0			// fov type for ft_def_atoi
# define RGB 1			// rgb type for ft_def_atoi
# define DEF 2			// default type for both ft_def_atoi and ft_def_atod
# define TRANSFORM_CAMERA 0
# define TRANSFORM_LIGHT 1
# define TRANSFORM_OBJECT 2

/* <===================================> */
// Library Declarations

// Main Libraries
# include <unistd.h> 
# include <stdlib.h> 
# include <stdio.h> 
# include <errno.h> 
# include <fcntl.h>
# include <string.h> 
# include <math.h>
# include <sys/time.h>

// MiniLibX
# include "./minilibx/mlx.h"
//# include "./minilibx/mlx_int.h"

// Libft
# include "./libft/libft.h"

// GetNextLine
# include "./get_next_line/get_next_line.h"

/* <===================================> */
// Struct Declarations

// Vector Struct | Used to make vectors for positions, orientations, etc
typedef struct	s_vector 
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

typedef struct	s_camera_frame
{
	t_vector	origin;
	t_vector	forward;
	t_vector	right;
	t_vector	up;
	double		half_view_width;
	double		half_view_height;
}	t_camera_frame;

// RGB Vector Struct | Used to make vectors for RGB color definition
typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct	s_hit
{
	double		distance;
	t_vector	point;
	t_vector	normal;
	t_rgb		color;
	int			object_type;
}	t_hit;

// MLX Struct | Contains the MLX data
typedef struct  s_mlx
{
    void    *mlxcon;
    void    *window;
    void    *image;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_mlx;

// Camera Struct | Contains the camera data defined by the argument
typedef struct	s_camera
{
    t_vector	position;
	t_vector	orientation;
	int			fov;
}	t_camera;

// Ambient Struct | Contains the ambient data defined by the argument
typedef struct	s_ambient
{
	double	ratio;
	t_rgb	color;	
}	t_ambient;

// Light Struct | Contains the light data defined by the argument
typedef struct	s_light
{
	t_vector	position;
	double		ratio;
	t_rgb		color;
}	t_light;

// Objects
// Sphere Struct | Contains the sphere data defined by the argument
typedef struct	s_sphere
{
	t_vector	center;
	double		diameter;
	t_rgb		color;
}	t_sphere;

// Plane Struct | Contains the plane data defined by the argument
typedef struct	s_plane
{
	t_vector	point;
	t_vector	normal;
	t_rgb		color;
}	t_plane;

// Cylinder Struct | Contains the cylinder data defined by the argument
typedef struct	s_cylinder
{
	t_vector	center;
	t_vector	normal;
	double		diameter;
	double		height;
	t_rgb		color;
}	t_cylinder;

// Objects Struct | Contains the objects defined by the argument
typedef struct	s_objects
{
	int		type;
	void	*obj;
}	t_objects;

// Scene Struct | Contains the scene data defined by the argument
typedef struct	s_scene
{
	t_ambient	ambient;
	t_light		light;
	t_camera	camera;
	t_objects	*objs;
	int			obj_count;
}	t_scene;

// Main program struct | Contains all of the programs data
typedef struct	s_data
{
	t_mlx		mlx;
	t_scene		scene;
	int			transform_target;
	int			selected_object;
}	t_data;

/* <===================================> */
// Function Declarations


/* <======== cleanup ==================> */
// free.c:
void	free_objects(t_data *data);


/* <======== input_validation =========> */
// extension.c:
int		input_validation(char *arg);


/* <======== parser ===================> */
// extract_objs.c:
int	extract_plane(t_data *data, char *line);
int	extract_sphere(t_data *data, char *line);
int	extract_cylinder(t_data *data, char *line);

// extract_scene.c:
int	extract_ambient(t_data *data, char *line);
int	extract_camera(t_data *data, char *line);
int	extract_light(t_data *data, char *line);

// scene_parser.c:
void	skip_newline(char *line, int *i);
int		parse_scene(t_data *data, const char *scene);


/* <======== program_execution ========> */
// body.c:
int		program_execution(char *arg);

// initialization.c:
int		initialize_program(t_data *data);

// camera_rays.c:
int		initialize_camera_frame(const t_camera *camera, t_camera_frame *frame);
int		camera_ray_for_pixel(const t_camera_frame *frame, int x, int y,
			t_ray *ray);

// intersect.c:
int		intersect_sphere(const t_ray *ray, const t_sphere *sphere,
			double *distance, t_vector *point);
int		intersect_plane(const t_ray *ray, const t_plane *plane,
			double *distance, t_vector *point);
int		intersect_cylinder(const t_ray *ray, const t_cylinder *cylinder,
			double *distance, t_vector *point);
int		intersect_scene(const t_scene *scene, const t_ray *ray, t_hit *hit);

// lighting.c:
t_rgb	shade_hit(const t_scene *scene, const t_hit *hit);

// transform.c:
int		apply_transform_key(t_data *data, int keycode);

// scene_renderer.c:
int		render_scene(t_data *data);


/* <======== tools ====================> */
// ft_def_atod.c:
double	ft_def_atod(char *line, int *i, int type);

// ft_def_atoi.c:
int		ft_def_atoi(char *line, int *i, int type);

// vector_math1.c
t_vector	vector_add(t_vector a, t_vector b);

// vector_math1.c
t_vector	vector_sub(t_vector a, t_vector b);

// vector_math1.c
t_vector	vector_mult(t_vector v, double scalar);

// vector_math1.c
t_vector	vector_div(t_vector v, float scalar);

// vector_math2.c
double	vector_dot(t_vector a, t_vector b);

// vector_math2.c
t_vector	vector_cross(t_vector a, t_vector b);

// vector_math2.c
double	vector_len(t_vector v);

// vector_math2.c
t_vector	vector_norm(t_vector v);

// vector_math2.c
t_vector	vector_scale(t_vector vector, double scale);
/* Notes:
 => in this project, 'double' is used instead of 'int' in some occasions since it helps with 'float' type calculations.
*/
#endif