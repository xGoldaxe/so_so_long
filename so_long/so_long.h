/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:59:51 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/20 17:55:42 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<stdio.h>
# include	<mlx.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<stdarg.h>
# include	"libft/libft.h"
# include	"../mif_manager/get_next_line/get_next_line.h"

# define GAME_WIDTH 1024
# define GAME_HEIGHT 1024

/* touch */
# define TOUCH_RIGHT 2
# define TOUCH_LEFT 0
# define TOUCH_UP 13
# define TOUCH_DOWN 1
# define ESCAPE 53

/* SPEEDS */
# define HERO_SPEED 60
# define ENNEMIES_SPEED 60

/* SPRITES */
# define HERO_SPRITE 5
# define HERO_WALK_SPRITE 7
# define ENNEMIES_SPRITE 0
# define C_SPRITE 2
# define EXIT_SPRITE 3
# define WALL_SPRITE 4

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}								t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}								t_vars;

typedef struct s_size {
	int	width;
	int	height;
}								t_size;

typedef struct s_coord {
	int	x;
	int	y;
}								t_coord;

typedef struct s_element {
	char		type;
	t_coord		coord;
	t_size		size;
	int			visible;
	int			collision_enable;
	int			speed;
	int			direction;
	int			actual_frame;
	int			number_frames;
	int			frame_speed;
	int			sprite;
}								t_element;

typedef struct s_mif {
	unsigned int	*container;
	int				width;
	int				height;
	t_list			*colors;
}	t_mif;

typedef struct s_gamestate {
	t_vars			vars;
	int				touch_press;
	t_data			background;
	t_data			blocks_layer;
	t_list			*elements;
	t_size			map_size;
	t_element		hero;
	int				moving;
	int				nbr_c;
	int				collected_c;
	int				state;
	int				score;
	int				unit_size;
	int				game_speed;
	t_mif			*mif;
	char			**str_loaded;
}								t_gamestate;

typedef struct s_elt_opt {
	t_data	img;
	int		color;
	t_coord	coord;
	t_size	size;
	int		direction;
}	t_elt_opt;

typedef struct s_malloc {
	void	*content;
	void	(*cleaner)(void *var);
}	t_malloc;

/* COLORS */
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
int			create_trgb(int t, int r, int g, int b);

/* PUT SHAPES */
char		**put_str(t_elt_opt options, char *content, int size);
void		ft_put_gradient(t_size size, int a,
				int b, t_data img);
void		put_square(t_elt_opt options, int width,
				int height, int color);
void		put_square_from_bg(t_data *img, t_data *bg, t_elt_opt options);

/* PIXEL INTERFACE */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		my_mlx_pixel_put_from(t_data *data, t_data *from, int x, int y);

/* GLOBAL EVENTS */
void		game_over(t_gamestate *gamestate);

/* RENDERING */
void		render_layers(t_gamestate *gamestate);
void		copy_img(t_data *src, t_data *dst, int width, int height);

/* COLLISION */
int			verify_collision(t_coord *coord, t_gamestate *gamestate);

/* MAP GENERATION */
void		place_elements(t_gamestate *gamestate);
void		put_elt(t_element *elt, t_gamestate *gamestate,
				t_data *dst, t_data *src);

/* MAP */
t_list		*store_map(char	*file, t_gamestate *gamestate);
void		read_map(int fd, t_gamestate *gamestate, int is_storing);
void		add_element(char c, t_coord coord, t_gamestate *gamestate);
t_element	*find_create_element(char c, t_coord coord, t_gamestate *gamestate);

/* UTILS */
char		*ft_realloc_merge(int nb_str, ...);
char		*ft_realloc_cat(char *src, char *dst);

/* ENNEMIES */
void		move_ennemies(t_gamestate *gamestate);
int			verify_collision_ennemies(t_element *elt,
				t_gamestate *gamestate);

/* LOADING */
void		load_gamestate(t_gamestate *gamestate, char *map_src);
void		*malloc_load(int size, void free_function(void *));
//free
void		free_sprites(t_mif *mif);
void		*clean_str(char **loaded);

/* GLOBAL and SAFETY */
void		clean_exit(t_gamestate *gamestate);
void		parse_error(t_gamestate *gamestate);

/* INPUTS EVENTS */
int			on_press(int keycode, t_gamestate *gamestate);
int			on_release(int keycode, t_gamestate *gamestate);

/* RENDER FRAMES */
int			render_next_frame(t_gamestate *gamestate);

/* PLAYERS INTERACTION */
int			update_coord(int keycode, t_coord *player_coord,
				t_gamestate *gamestate);

/* MIF MANAGER */
void		mif_read(char *file, t_mif *options);
void		mif_to_img(t_mif *mif, t_data *img, t_data *ref, t_elt_opt ref_opt);
void		load_sprites(t_gamestate *gamestate);
void		mif_clean(t_mif *mif);

#endif