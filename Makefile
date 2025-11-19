NAME=		libftprintf.a
LIBFT=		$(BUILD_DIR)/libft.a
BONUS=		$(BUILD_DIR)/libftprintf_bonus.a

SRC_DIR=	src
B_SRC_DIR=	bonus
INC_DIR=	include
LIBFT_DIR=	libft
BUILD_DIR=	.build

SRC=		$(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/ft_putnbr_base.c \
			$(SRC_DIR)/print_char.c \
			$(SRC_DIR)/print_hex.c \
			$(SRC_DIR)/print_number.c \
			$(SRC_DIR)/print_pointer.c \
			$(SRC_DIR)/print_str.c \
			$(SRC_DIR)/print_unsigned.c \

B_SRC=		$(B_SRC_DIR)/ft_printf_bonus.c \
			$(B_SRC_DIR)/ft_putnbr_base_bonus.c \
			$(B_SRC_DIR)/print_char_bonus.c \
			$(B_SRC_DIR)/print_hex_bonus.c \
			$(B_SRC_DIR)/print_number_bonus.c \
			$(B_SRC_DIR)/print_pointer_bonus.c \
			$(B_SRC_DIR)/print_str_bonus.c \
			$(B_SRC_DIR)/print_unsigned_bonus.c \
			$(B_SRC_DIR)/ft_create_arg_bonus.c \
			$(B_SRC_DIR)/ft_main_arg_bonus.c \
			$(B_SRC_DIR)/ft_parsing_bonus.c \
			$(B_SRC_DIR)/utils_flag_bonus.c


OBJ=		$(SRC:%.c=$(BUILD_DIR)/%.o)
B_OBJ=		$(B_SRC:%.c=$(BUILD_DIR)/%.o)
DEP=		$(SRC:%.c=$(BUILD_DIR)/%.d)
B_DEP=		$(B_SRC:%.c=$(BUILD_DIR)/%.d)

CC=			cc
CFLAGS=		-Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -MMD -MP
AR=			ar rcs

all: $(NAME)

bonus: $(BONUS)
	cp $(BONUS) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(LIBFT)

$(BONUS): $(B_OBJ) $(LIBFT)
	cp $(LIBFT) $(BONUS)
	$(AR) $(BONUS) $(B_OBJ)

clean:
	rm -f $(OBJ) $(DEP) $(B_OBJ) $(B_DEP)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS) $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP) $(B_DEP)

.PHONY: all clean fclean re bonus
