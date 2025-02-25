CC			=	cc -I$(INCLUDE) # -Wall -Wextra -Werror -g3 -fsanitize=address 

NAME		=	push_swap
INCLUDE		=	include
SRCDIR		=	src/
OBJDIR		=	objs/
SRCS		=	$(SRCDIR)push_swap.c
OBJS		=	$(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

AR			=	ar rcs
RM			=	rm -f

all:		$(NAME)

$(NAME):    $(OBJS)
			@echo "Creating objects... 🔨🪛"
			@$(CC) $(OBJS) -o $(NAME)
			@echo "Cooking up the program... 🍲🍳"
			@echo "✅ Done ✅"

$(OBJDIR)%.o: $(SRCDIR)%.c
			@mkdir -p $(OBJDIR)
			@$(CC) -c $< -o $@

clean:
			@$(RM) $(OBJS)
			@rm -rf $(OBJDIR)
			@echo "Cleaning up... 🧹💨"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(EXEC)

re:			fclean all

.PHONY:        all lib clean fclean re bonus