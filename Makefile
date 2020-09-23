# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ldideric <ldideric@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/06 14:04:07 by ldideric      #+#    #+#                  #
#    Updated: 2020/09/23 17:39:43 by ldideric      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

SRC_PATH		=	src
PARS_PATH		=	./$(SRC_PATH)/parsing/
EXTRA_PATH		=	./$(SRC_PATH)/extras/

PARS_SRC		=	reader.c 
# 					reader_basic.c \
# 					read_object.c

EXTRA_SRC		=	error.c \
					hooks.c \
					extra1.c

PARS_SRC_DIR	=	$(PARS_SRC:%=$(PARS_PATH)%)
EXTRA_SRC_DIR	=	$(EXTRA_SRC:%=$(EXTRA_PATH)%)

PARS_OBJ_DIR	=	$(PARS_SRC_DIR:.c=.o)
EXTRA_OBJ_DIR	=	$(EXTRA_SRC_DIR:.c=.o)

C_FILES			=	./$(SRC_PATH)/cub3d.c \
					$(PARS_SRC_DIR) \
					$(EXTRA_SRC_DIR) 
O_FILES			=	$(C_FILES:.c=.o)
EXTRAS			=	libmlx.dylib src/biglib.a

W_FLAGS			=	-Wall -Werror -Wextra
LIB_FLAGS		=	-framework OpenGL -framework AppKit -Imlx -Iinc
FLAGS			=	$(W_FLAGS) $(LIB_FLAGS)
MMLX			=	make -C ./mlx && cp mlx/libmlx.dylib .
CMLX			=	$(NAME) libmlx.dylib

ifdef DEBUG
FLAGS	+= -g
endif
ifdef FSAN
FLAGS	+= -fsanitize=address
endif
ifdef MLX
MMLX	= @echo "$(R)Skipping re-compiling the MLX Library.$(RES)"
CMLX	= $(NAME)
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
	@echo "$(P)Compiling cub3D$(PI)"
	gcc $(C_FILES) $(FLAGS) $(EXTRAS) -o $(NAME)
	@echo "$(G)Done!$(RES)"

clean:
	@echo "$(P)Cleaning mlx object files$(RES)"
	@make clean -C ./mlx
	@echo "$(P)Cleaning cub3d object files$(RES)"
	@rm -rf $(O_FILES)

fclean: clean
	@echo "$(P)Cleaning executable$(RES)"
	@rm -rf $(CMLX)

re: fclean all

test:
	@echo "$(O_FILES:.o=.o\n)"

norm:
	@echo "$(R)Norminette:$(RES)"
	@norminette $(C_FILES) Makefile \
		| grep -c "Error" || printf ""
	@echo "$(R)Norminette+:$(RES)"
	@python ~/norminette+/run.py $(C_FILES) Makefile \
		| grep -c "Error" || printf ""

normall:
	@echo "$(R)Norminette:$(RES)"
	@norminette $(C_FILES) Makefile
	@echo "$(R)Norminette+:$(RES)"
	@python ~/norminette+/run.py $(C_FILES) Makefile
