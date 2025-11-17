NAME=		libftprintf.a

SRC_DIR=	src
INC_DIR=	include
LIBFT_DIR=	libft

SRC=		$(SRC_DIR)/ft_printf.c \

OBJ=		$(SRC:.c=.o)
DEP=		$(SRC:.c=.d)

CC=			cc
CFLAGS=		-Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -MMD -MP
AR=			ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(DEP)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
