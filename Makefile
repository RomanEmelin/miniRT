NAME = miniRT

SRCS = minirt.c

VECUTILS = vect_utils.c  vect_utils2.c

VECDIR = vector_utils

VECTRS = $(addprefix $(VECDIR)/, $(VECUTILS))

MLX = color_utl.c\
	  light.c\
	  plane.c\
	  square.c\
	  triangle.c\
	  cylinder.c\
	  mlx_utils.c\
	  sphere.c\
	  start_rt.c\
	  utils.c

MLXDIR = my_mlx

MLXS = $(addprefix $(MLXDIR)/, $(MLX))

PARSER = c_count.c\
		 find_figure.c\
		 parse_figures.c\
		 parsers.c\
		 check_parse.c\
		 parse_ambient.c\
		 parse_light.c\
		 split_color.c\
		 check_triangle.c\
		 parse_camera.c\
		 parse_resolution.c\
		 split_vector.c

PARSERDIR = parsers

PARSERSRCS = $(addprefix $(PARSERDIR)/, $(PARSER))

UTILS = arg_count.c\
	   	ft_isspace.c\
	   	ft_setsplit.c\
	   	ft_strlen.c\
	   	ft_atof.c\
	   	ft_lstadd_back.c\
	   	ft_split.c\
	   	get_next_line.c\
	   	ft_atoi.c\
	   	ft_lstlast.c\
	   	ft_strchr.c\
	   	ft_extension.c\
	   	ft_lstnew.c\
	   	ft_strcmp.c\
	   	get_next_line_utils.c\
	   	ft_isdigit.c\
	   	ft_lstsize.c\
	   	ft_strlcpy.c\
	   	handle_error.c

UTILSDIR = sprt_srcs

UTILSSRC = $(addprefix $(UTILSDIR)/, $(UTILS))

BMP = bitmap_maker.c

BMPDIR = bitmap

BMPSRCS = $(addprefix $(BMPDIR)/, $(BMP))

HDR0 = .

HDR1 = ./sprt_srcs/ 

HDR2 = ./minilibx_mms_20200219

ALLSRCS = $(UTILSSRC) $(BMPSRCS) $(PARSERSRCS) $(MLXS) $(VECTRS) $(SRCS)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBMLX = libmlx.dylib

OBJS	= $(ALLSRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -I$(HDR0) -I$(HDR1) -I$(HDR2) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -I$(HDR0) -I$(HDR1) -I$(HDR2) $(LIBMLX) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re specular
