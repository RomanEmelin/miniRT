/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:20:43 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/06 14:50:17 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "sprt_srcs/get_next_line.h"
# include "./minilibx_mms_20200219/mlx.h"
# include <math.h>
# include <stdarg.h>
# ifndef SPECULAR
#  define SPECULAR 30
# endif
# ifndef REFLECTIVE
#  define REFLECTIVE 0
# endif

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct		s_crd
{
	double			x;
	double			y;
	double			z;
}					t_crd;

typedef struct		s_color
{
	double				r;
	double				g;
	double				b;
}					t_color;

typedef struct		s_res
{
	t_crd			crd;
	int				parsed;
}					t_res;

typedef struct		s_amb
{
	double			ratio;
	t_color			color;
}					t_amb;

typedef struct		s_cam
{
	t_crd			pov;
	t_crd			orient;
	int				fov;
}					t_cam;

typedef struct		s_lght
{
	t_crd			pol;
	double			brght;
	t_color			color;
}					t_lght;

typedef struct		s_figure
{
	int				id;
	t_crd			crd1;
	t_crd			crd2;
	t_crd			crd3;
	t_crd			orient;
	double			dmtr;
	double			sd_size;
	double			specular;
	double			t;
	t_color			color;
}					t_figure;

typedef struct		s_all
{
	int				bmp;
	t_cam			*cam;
	int				light_c;
	void			*mlx;
	void			*mlx_win;
	int				fd;
	char			**scene;
	char			*line;
	t_res			res;
	t_amb			amb;
	t_list			*cam_lst;
	t_list			*lght_lst;
	t_list			*figure_lst;
	int				camera_c;
	t_img			img;
}					t_all;

int					ft_isspace(int c);
double				ft_atof(const char *str);
int					ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
void				handle_error(char *s, t_all *all);
int					ft_strcmp(char *s1, char *s2);
int					ft_extension(char *s);
void				parse_scene(t_all *all);
int					ft_isdigit(int i);
size_t				ft_strlcpy(char *dst, const char *src, size_t dsize);
char				*ft_strchr(const char *s, int c);
char				**ft_setsplit(const char *s, char *set);
void				*ft_free_split(char **res);
void				parse_type(t_all *all);
void				parse_resolution(t_all *all);
void				parse_ambient(t_all *all);
int					arg_count(char **scene);
int					check_parse(char **s);
t_color				split_color(char *s, t_all *all);
int					c_count(char *s, char c);
void				free_all(t_all *all);
void				parse_camera(t_all *all);
t_crd				split_vector(char *s, t_all *all, int flag);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				parse_light(t_all *all);
void				parse_plane(t_all *all);
void				parse_sphere(t_all *all);
void				parse_square(t_all *all);
void				parse_cylinder(t_all *all);
void				parse_triangle(t_all *all);
void				start_rt(t_all *all);
void				list_init(t_list **lst, t_list *new);
void				render(t_all *all);
void				make_full_ring(t_list **cam_lst);
t_crd				cross_vec(t_crd a, t_crd b);
t_crd				multiple_vect(t_crd v, double i);
t_crd				get_tr_normal(t_figure tr);
t_crd				normalize(t_crd v);
double				intersect_cylinder(t_crd o, t_crd d, t_figure cy);
t_crd				get_cy_normal(t_figure cy, t_crd p);
double				dot(t_crd v1, t_crd v2);
double				vect_len(t_crd v);
t_crd				make_vect(t_crd v1, t_crd v2, int flag);
double				intersect_plane(t_crd o, t_crd d, t_figure pl);
double				intersect_triangle(t_crd o, t_crd d, t_figure tr);
double				intersect_sphere(t_crd o, t_crd d, t_figure sp);
t_crd				get_sp_normal(t_figure sp, t_crd p);
double				intersect_square(t_crd o, t_crd d, t_figure sq);
int					multiple_lght(t_color color, double i);
int					create_rgb(int r, int g, int b);
t_color				add_color(t_color c1, t_color c2, double i);
t_color				manage_light(t_crd p, t_crd n, t_crd v, t_all *all);
t_color				multiple_rgb(t_color c, double i);
t_figure			*closest_t(t_crd o, t_crd d, double t[2], t_all *all);
double				choose_fg(t_crd o, t_crd d, t_figure *fg);
t_crd				canvas_to_viewport(t_crd scale, t_all *all);
int					key_hook(int keycode, t_all *all);
void				my_pixel_put(t_all *all, int x, int y, int color);
t_color				check_color(t_color clr);
t_crd				get_normal(t_figure fg, t_crd p);
int					trace_ray(t_all *all, t_crd dir);
t_crd				make_cam(t_crd d, t_crd orient);
int					ft_close(void **all);
int					check_orient(t_crd o);
void				check_triangle(t_crd c1, t_crd c2, t_crd c3, t_all *all);
void				make_bmp(char *filename, t_all *all);
char				*create_file(t_all *all, char *file);
int					make_file(char *filename, t_all *all);
void				ft_bzero(void *s, size_t n);

#endif
