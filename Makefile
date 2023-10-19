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

SRC=	ft_strlen.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_read.s \
		ft_write.s \

OBJ= $(SRC:.s=.o)

SRC_B=	ft_list_size.s \
		ft_list_push_front.s \
		ft_list_sort.s \
		ft_list_remove_if.s \

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