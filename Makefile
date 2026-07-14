SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
TEST_DIR	= tests

SRCS =	ft_strlen.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_read.s \
		ft_write.s \
		ft_strdup.s

SRCS_BONUS =	ft_strlen.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_read.s \
				ft_write.s \
				ft_strdup.s \
				ft_atoi_base.s \
				ft_list_push_front.s \
				ft_list_size.s \
				ft_list_sort.s \
				ft_list_remove_if.s

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.s=.o))
OBJS_BONUS	= $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.s=.o))

CC = gcc
CFLAGS = -g -I$(INC_DIR)
AR = ar rcs
NASM = nasm -g -F dwarf -f elf64

NAME = libasm.a
NAME_BONUS = libasm_bonus.a
TEST = test_mandatory
TEST_BONUS = test_bonus

.PHONY: all bonus clean fclean re test test_bonus

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(AR) $(NAME_BONUS) $(OBJS_BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(NASM) $< -o $@

test_mandatory: $(NAME)
	$(CC) $(CFLAGS) -o $(TEST) $(TEST_DIR)/test_mandatory.c -L. -lasm

test_bonus: $(NAME_BONUS)
	$(CC) $(CFLAGS) -o $(TEST_BONUS) $(TEST_DIR)/test_bonus.c -L. -lasm_bonus

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(TEST) $(TEST_BONUS)

re: fclean all