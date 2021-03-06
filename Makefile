# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ldideric <ldideric@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/06 14:04:07 by ldideric      #+#    #+#                  #
#    Updated: 2020/11/02 21:04:47 by ldideric      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

SRC_PATH		=	src
LIBFT_PATH		=	./$(SRC_PATH)/libft/
PRINTF_PATH		=	./$(SRC_PATH)/printf/
GNL_PATH		=	./$(SRC_PATH)/gnl/
PARS_PATH		=	./$(SRC_PATH)/parsing/
RAYC_PATH		=	./$(SRC_PATH)/raycaster/
BONUS_PATH		=	./$(SRC_PATH)/bonus/
EXTRA_PATH		=	./$(SRC_PATH)/extras/

LIBFT_SRC		=	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_atof.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_lstadd_back_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstmap_bonus.c \
					ft_lstnew_bonus.c \
					ft_lstsize_bonus.c \
					ft_ismatch.c \
					ft_strstr.c \
					ft_skipchar.c

PRINTF_SRC		=	ft_printf.c \
					ft_printf_bonus.c \
					ft_flags.c \
					ft_itoa_base.c \
					ft_ultoa_base.c \
					printf_c.c \
					printf_s.c \
					printf_di.c \
					printf_p.c \
					printf_u.c \
					printf_x.c \
					printf_per.c

GNL_SRC			=	get_next_line.c \
					get_next_line_utils.c

PARS_SRC		=	reader.c \
					reader_map.c \
					reader_extra.c \
					reader_res_f_c.c \
					validate_cub.c

RAYC_SRC		=	pxloop.c \
					pxloop_ext.c \
					textures.c \
					sprites.c \
					spr_init.c \
					move.c \
					rotate.c

BONUS_SRC		=	minimap_bonus.c \
					crosshair_bonus.c

EXTRA_SRC		=	error.c \
					hooks.c \
					hooks_move.c \
					extra1.c \
					extra2.c \
					bmp.c \
					init_data.c \
					init_data_ext.c

LIBFT_SRC_DIR	=	$(LIBFT_SRC:%=$(LIBFT_PATH)%)
PRINTF_SRC_DIR	=	$(PRINTF_SRC:%=$(PRINTF_PATH)%)
GNL_SRC_DIR		=	$(GNL_SRC:%=$(GNL_PATH)%)
PARS_SRC_DIR	=	$(PARS_SRC:%=$(PARS_PATH)%)
RAYC_SRC_DIR	=	$(RAYC_SRC:%=$(RAYC_PATH)%)
BONUS_SRC_DIR	=	$(BONUS_SRC:%=$(BONUS_PATH)%)
EXTRA_SRC_DIR	=	$(EXTRA_SRC:%=$(EXTRA_PATH)%)

LIBFT_OBJ_DIR	=	$(LIBFT_SRC_DIR:.c=.o)
PRINTF_OBJ_DIR	=	$(PRINTF_SRC_DIR:.c=.o)
GNL_OBJ_DIR		=	$(GNL_SRC_DIR:.c=.o)
PARS_OBJ_DIR	=	$(PARS_SRC_DIR:.c=.o)
RAYC_OBJ_DIR	=	$(RAYC_SRC_DIR:.c=.o)
BONUS_OBJ_DIR	=	$(BONUS_SRC_DIR:.c=.o)
EXTRA_OBJ_DIR	=	$(EXTRA_SRC_DIR:.c=.o)

C_FILES			=	./$(SRC_PATH)/cub3d.c \
					$(LIBFT_SRC_DIR) \
					$(PRINTF_SRC_DIR) \
					$(GNL_SRC_DIR) \
					$(PARS_SRC_DIR) \
					$(RAYC_SRC_DIR) \
					$(EXTRA_SRC_DIR)
O_FILES			=	$(C_FILES:.c=.o)
EXTRAS			=	libmlx.dylib

W_FLAGS			=	-Wall -Werror -Wextra -std=c89
LIB_FLAGS		=	-framework OpenGL -framework AppKit -Imlx -Iinc
FLAGS			=	$(W_FLAGS) $(LIB_FLAGS)
BONUS_FLAGS		=	$(BONUS_SRC_DIR) -D BONUS=1

MMLX			=	make -C ./mlx && cp mlx/libmlx.dylib .
CMLX			=	@make fclean -C ./mlx

ifdef DEBUG
FLAGS	+=	-g
endif
ifdef FSAN
FLAGS	+=	-fsanitize=address
endif
ifdef SPEED
FLAGS	+=	-Ofast
endif
ifdef ERROR
FLAGS	+=	-D ELABORATE_ERR=1
endif
ifdef LEAKS
FLAGS	+=	-D LEAKS=1
endif
ifdef MLX
MMLX	=	@echo "$(O) > Skipping re-compiling the MLX Library.$(RES)" \
			&& cp mlx/libmlx.dylib .
CMLX	=	@make clean -C ./mlx
endif

#COLOR CODES
#red
R	= \x1b[38;5;196m
#orange
O	= \x1b[38;5;208m
#yellow
Y	= \x1b[38;5;3m
#green
G	= \x1b[38;5;83m
#blue
B	= \x1b[38;5;21m
#purple
P	= \x1b[38;5;129m
#light pink
PI	= \x1b[38;5;219m
#grey
GR	= \x1b[38;5;244m
#reset to white
RES	= \x1b[0m

SUM		= \x1b[38;5;$(X)m
X		= 1

all: $(NAME)

$(NAME):
	@echo "$(P)Compiling MiniLibX Library$(O)"
	$(MMLX)
	@echo "$(P)Compiling cub3D$(O)"
	@gcc $(C_FILES) $(FLAGS) $(EXTRAS) -o $(NAME)
	@echo "gcc $\(FILES).c $(FLAGS) $(EXTRAS) -o $(NAME)"
	@echo "$(G) > Done compiling!$(RES)\n"

clean:
	@echo "$(P)Cleaning files.$(GR)"
	@make clean -C ./mlx
	@echo "rm -rf $\(FILES).o"
	@rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME) libmlx.dylib screenshot.bmp
	$(CMLX)
	@echo "$(G) > Done Cleaning!$(RES)\n"

re: fclean all

bonus:
	@echo "$(R)Recompiling with BONUS$(O)"
	@gcc $(C_FILES) $(BONUS_FLAGS) $(FLAGS) $(EXTRAS) -o $(NAME)
	@echo "gcc $\(FILES).c $(FLAGS) $(EXTRAS) -o $(NAME) $(BONUS_FLAGS)"
	@echo "$(G) > Done compiling!$(RES)\n"

norm:
	@echo "$(R)Norminette:$(RES)"
	@norminette $(C_FILES) $(BONUS_SRC_DIR) \
		./inc/*.h Makefile | grep -c "Error" || printf ""
	@echo "$(R)Norminette+:$(RES)"
	@python ~/norminette+/run.py $(C_FILES) $(BONUS_SRC_DIR) \
		./inc/*.h Makefile | grep -c "Error" || printf ""

normall:
	@echo "$(R)Norminette:$(RES)"
	@norminette $(C_FILES) $(BONUS_SRC_DIR) \
		./inc/*.h Makefile
	@echo "$(R)Norminette+:$(RES)"
	@python ~/norminette+/run.py $(C_FILES) $(BONUS_SRC_DIR) \
		./inc/*.h Makefile
