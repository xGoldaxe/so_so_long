SRC = colors.c ft_realloc_merge.c load_sprites.c my_mlx_pixel_put.c render_frames.c \
copy_img.c game_over.c loaded_ressources.c place_elements.c render_layers.c \
ennemies.c gradient.c main.c put_square.c store_map.c \
ennemies_collison.c input_events.c movement.c put_str.c verify_collision.c \

CC = gcc

HEADER = so_long.h

OBJ = $(SRC:%.c=./.build/%.o)

NAME = so_long

RM = rm -f

LIBC = ar -rc

CFLAGS = -Wall -Wextra -Werror

LIBFT = cd libft && make libft.a

MIF = cd ../mif_manager && make all

./.build/%.o : %.c
	$(CC) ${CFLAGS} -I. -o $@ -c $?

${NAME} :$(OBJ)
	${LIBFT}
	${MIF}
	${CC} ${CFLAGS} -o ${NAME} -I /usr/local/include/mlx.h ${OBJ} ./libft/libft.a ../mif_manager/mif_manager.a -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit

all :	${NAME} 

clean :
	${RM} ${OBJ}

fclean :	clean
	cd libft && make fclean
	cd ../mif_manager && make fclean
	${RM} ${NAME}

re :	fclean all
