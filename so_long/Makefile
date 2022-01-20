SRC = colors.c ft_realloc_merge.c load_sprites.c my_mlx_pixel_put.c render_frames.c \
utils.c \
copy_img.c game_over.c place_elements.c render_layers.c \
ennemies.c gradient.c main.c put_square.c store_map.c \
ennemies_collison.c input_events.c movement.c put_str.c verify_collision.c \
read_map.c create_element.c clean_exit.c \

CC = gcc

HEADER = so_long.h

OBJ = $(SRC:%.c=./.build/%.o)

NAME = so_long

RM = rm -rf

LIBC = ar -rc

CFLAGS = -Wall -Wextra -Werror

LIBFT = @printf "\n\t\t${B_CYAN}GENERATE libft library ...\n\n${NONE}"  && cd libft && make libft.a

MIF = @printf "\n\t\t${B_CYAN}GENERATE mif_manager library ...\n\n${NONE}" && cd ../mif_manager && make all

# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m

./.build/%.o : %.c
	@$(CC) ${CFLAGS} -I. -o $@ -c $?
	@printf "${B_MAGENTA}Compilling $? ...\n${NONE}"

all :	
	@mkdir -p .build
	@make ${NAME}

${NAME} : $(OBJ)
	${LIBFT}
	${MIF}
	${CC} ${CFLAGS} -o ${NAME} -fsanitize=address -g  -static-libsan \
	-I /usr/local/include/mlx.h ${OBJ} ./libft/libft.a ../mif_manager/mif_manager.a -L \
	/usr/local/lib/ -lmlx -framework OpenGl -framework Appkit
	@printf "${B_GREEN}\t\t ==>{${NAME}} LINKED SUCCESFULLY<==${NONE}\n"

clean :
	@${RM} .build
	@printf "${B_RED}\t\t XX{${NAME}} CLEANED SUCCESFULLY XX${NONE}\n"

fclean :	clean
	@cd libft && make fclean
	@cd ../mif_manager && make fclean
	@${RM} ${NAME}
	@printf "${B_RED}\t\t XX{${NAME}} FCLEAN SUCCESFULL XX${NONE}\n"

re :	fclean all