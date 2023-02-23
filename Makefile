###########################################################
#### NAME

NAME			= so_long

###########################################################
#### PATH TO SOURCES

PATH_SRCS 		+= srcs/

###########################################################
#### SOURCES

SRCS			+= so_long.c
SRCS			+= moves.c
SRCS			+= shut_down.c
SRCS			+= parsing.c
SRCS			+= parsing_utils.c
SRCS			+= pathfinding.c
SRCS 			+= print_map.c
SRCS			+= moves_utils.c

vpath %.c $(PATH_SRCS)

###########################################################
#### OBJS

PATH_OBJS		= objs/
OBJS			= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

###########################################################
#### LIBRARY

LIBFT_PATH 		= libft/
LIBFT 			= $(LIBFT_PATH)/libft.a

###########################################################
#### INCLUDES

INCLUDES 		= -I./includes -I./minilibx-linux -I./$(LIBFT_PATH)/includes
HEADER			= includes/so_long.h
HEADER			+= minilibx-linux/mlx.h
HEADER			+= minilibx-linux/mlx_int.h

###########################################################
#### COMPILATION

CC				= clang
CFLAGS			+= -Wall

ifeq ($(everything),true)
	CFLAGS		+= -Weverything
else
	CFLAGS		+= -Werror
endif

CFLAGS			+= -Wextra
CFLAGS			+= -fPIE


###########################################################
#### RULES

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L ./minilibx-linux -lmlx -lXext -lX11 $(INCLUDES) -L $(LIBFT_PATH) -lft

$(LIBFT):
	$(MAKE) -sC $(LIBFT_PATH)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) 

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC $(LIBFT_PATH) fclean

re: fclean
	$(MAKE)

del: fclean
	rm a.out

test: 
	@ $(CC) -o tests/a.out tests/main.c $(NAME) && bash tests/runtests.sh

full_test: fclean all test

norm:
	@norminette $(PATH_SRCS) $(INCLUDES)

.PHONY: all clean fclean re del test full_test

# CIBLE > DEPENDANCES > REGLES

# variables spéciales :

# $+ idem que $^ mais avec les doublons
# $| idem que $^ mais avec les doublons et triés
# $% nom de la cible d'une règle de substitution
# $! nom de la cible d'une règle de substitution
# $< nom de la première dépendance d'une règle de substitution
# $> nom de la dernière dépendance d'une règle de substitution
# $^ liste des dépendances d'une règle de substitution
# $@ nom de la cible d'une règle de substitution
# $? liste des dépendances plus récentes que la cible d'une règle de substitution
# $* nom du fichier sans son extension d'une règle de substitution