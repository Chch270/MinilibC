##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## for compile
##

SRC_ASM		=		src/my_strlen.asm		\
				src/my_strchr.asm		\
				src/my_memset.asm		\
				src/my_rindex.asm		\
				src/my_strstr.asm		\
				src/my_strcmp.asm		\
				src/my_strncmp.asm		\
				src/my_memcpy.asm		\
				src/my_strcasecmp.asm		\
				src/my_strpbrk.asm		\
				src/my_strcspn.asm		\
				src/my_memmove.asm

OBJ_ASM		=		$(SRC_ASM:.asm=.o)

SRC_TEST	=		test/test_asm.c		\

NAME		=		libasm.so

NAME_TEST	=		unit_tests

NASM		=		nasm

CC		=		gcc

LD		=		ld

RM		=		rm -f

CRITERION	=		-lcriterion --coverage

CFLAGS		=		-Wall -f elf64

all:	$(NAME)

$(NAME):	$(OBJ_ASM)
	$(LD) -o $(NAME) -shared $(OBJ_ASM)

%.o:	%.asm
	$(NASM) $(CFLAGS) -o $@ $<

clean:
	$(RM) *~ $(OBJ_ASM)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

tests_run: CFLAGS += -DTU
tests_run: $(NAME)
	$(CC) -o $(NAME_TEST) $(SRC_TEST) $(OBJ_ASM) $(CRITERION)
	./$(NAME_TEST)

.PHONY: all clean fclean re tests_run
