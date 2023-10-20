NAME = test
NAME_B = test_bonus
LNAME = libasm.a
LNAME_B = libasm_bonus.a

AS = nasm
ASFLAGS = -f elf64

CC= gcc
CFLAGS= -Wall -Wextra -Werror

AR= ar
ARFLAGS= rcs

SRC=	srcs/ft_strlen.s \
		srcs/ft_strcmp.s \
		srcs/ft_strcpy.s \
		srcs/ft_strdup.s \
		srcs/ft_read.s \
		srcs/ft_write.s \

OBJ= $(SRC:.s=.o)

SRC_B=	srcs_bonus/ft_atoi_base.s \
		srcs_bonus/ft_list_size.s \
		srcs_bonus/ft_list_push_front.s \
		srcs_bonus/ft_list_sort.s \
		srcs_bonus/ft_list_remove_if.s \
		utils_bonus/ft_str_check_dup.s \

OBJ_B= $(SRC_B:.s=.o)

%.o : %.s
	$(AS) $(ASFLAGS) $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(LNAME) main.o
	$(CC) $(CFLAGS) main.c -c -o main.o -L $(LNAME)
	$(CC) $(CFLAGS) -o $(NAME) main.o $(LNAME)

$(LNAME): $(OBJ)
	$(AR) $(ARFLAGS) $(LNAME) $(OBJ)

.PHONY: bonus
bonus: $(LNAME_B) main_bonus.o
	$(CC) $(CFLAGS) main_bonus.c -c -o main_bonus.o -L $(LNAME_B)
	$(CC) $(CFLAGS) -o $(NAME_B) main_bonus.o $(LNAME_B)

$(LNAME_B): $(OBJ_B) $(OBJ)
	$(AR) $(ARFLAGS) $(LNAME_B) $(OBJ_B) $(OBJ)

.PHONY: clean
clean:
	rm -rf $(OBJ) main.o
	rm -rf $(OBJ_B) main_bonus.o

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)
	rm -rf $(LNAME)
	rm -rf $(LNAME_B)

.PHONY: re
re: fclean $(NAME)

.PHONY: re_bonus
re_bonus: fclean bonus