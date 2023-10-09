NAME = test
LNAME = libasm.a

AS = nasm
ASFLAGS = -f elf64

CC= gcc
CFLAGS= -Wall -Wextra -Werror

AR= ar
ARFLAGS= rcs

SRC= ft_strlen.s
OBJ= $(SRC:.s=.o)

%.o : %.s
	$(AS) $(ASFLAGS) $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(LNAME)
	$(CC) $(CFLAGS) main.c -o main.o
	$(CC) $(CFLAGS) main.o $(LNAME)

$(LNAME): $(OBJ)
	$(AR) $(ARFLAGS) $(LNAME) $(OBJ)

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(LNAME)

.PHONY: re
re: fclean $(NAME)