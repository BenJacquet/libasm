NAME = libasm.a

SRCSDIR = srcs/

SRCS =	srcs/ft_read.s\
		srcs/ft_strcmp.s\
		srcs/ft_strcpy.s\
		srcs/ft_strdup.s\
		srcs/ft_strlen.s\
		srcs/ft_write.s

OBJS = $(SRCS:.s=.o)

INCS = incs/libasm.h

NASM = nasm

FLAGS = -f macho64

%.o : %.s
	$(NASM) -I $(INCS) $(FLAGS) $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re