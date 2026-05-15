CC				=	cc -I$(INCLUDE) -g3 -Wall -Wextra -Werror -fsanitize=address 

NAME			=	push_swap
INCLUDE			=	include
SRCDIR			=	src/
OBJDIR			=	objs/
SRCS			=	$(SRCDIR)push_swap.c \
					$(SRCDIR)moves.c \
					$(SRCDIR)k_sort.c \
					$(SRCDIR)utils_aux.c \
					$(SRCDIR)utils_args.c \
					$(SRCDIR)utils_sort.c
OBJS			=	$(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

CHECKER			=	checker
CHECKER_SRCS	=	$(SRCDIR)checker.c \
					$(SRCDIR)moves.c \
					$(SRCDIR)utils_aux.c \
					$(SRCDIR)utils_args.c \
					$(SRCDIR)checker_utils.c
CHECKER_OBJS	=	$(CHECKER_SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

LIBFT			=	src/libft/
LIBFT_A			=	$(LIBFT)libft.a

AR				=	ar rcs
RM				=	rm -f

all:		$(NAME)

$(NAME):    $(OBJS)
$(NAME):    $(OBJS)
				@( \
					i=1; \
					while :; do \
						case $$i in \
							1) dots="." ;; \
							2) dots=".." ;; \
							3) dots="..." ;; \
							4) dots="...." ;; \
							5) dots="....." ;; \
							6) dots="......" ;; \
							7) dots="......." ; i=0 ;; \
						esac; \
						printf "\rCompiling libft %s" "$$dots"; \
						sleep 0.15; \
						i=$$(expr $$i + 1); \
					done & \
					ANIM_PID=$$!; \
					make -C $(LIBFT) -s; \
					kill $$ANIM_PID; \
					wait $$ANIM_PID 2>/dev/null; \
					printf "\n"; \
				)
				@echo "Creating objects 🔨🪛"
				@$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)
				@echo "Cooking up the program 🍲🍳"
				@echo "✅ Done ✅"
				@$(RM) 

$(OBJDIR)%.o: $(SRCDIR)%.c
				@mkdir -p $(OBJDIR)
				@$(CC) -c $< -o $@

bonus: $(CHECKER_OBJS)
				@make -C $(LIBFT) -s
				@$(CC) $(CHECKER_OBJS) $(LIBFT_A) -o checker
				@echo "✅ checker built"

clean:
				@$(RM) $(OBJS)
				@rm -rf $(OBJDIR)
				@make -C $(LIBFT) clean -s
				@echo "Cleaning up... 🧹💨"

fclean:			clean
				@make -C $(LIBFT) fclean -s
				@$(RM) $(NAME)
				@$(RM) $(CHECKER)
				@$(RM) $(PROG_BAR_FILE)

re:				fclean all

.PHONY:       	all lib clean fclean re bonus