NAME = libasm.a

TEST = test

SRCSDIR = srcs/

SRCS =	srcs/ft_read.s\
		srcs/ft_strcmp.s\
		srcs/ft_strcpy.s\
		srcs/ft_strdup.s\
		srcs/ft_strlen.s\
		srcs/ft_write.s

MAIN = srcs/main.c

OBJS = $(SRCS:.s=.o)

INCS = incs/libasm.h

NASM = nasm

FLAGS = -f elf64

%.o : %.s
	$(NASM) -I $(INCS) $(FLAGS) $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

test : all
	gcc $(MAIN) $(NAME) -no-pie -o $(TEST)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(TEST) write_ft.txt write_rl.txt

re : fclean all

.PHONY : all clean fclean re