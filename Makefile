CC				= 	cc -I$(INCLUDE) -g3 -Wall -Wextra -Werror #-fsanitize=address 

NAME			= 	push_swap
CHECKER			= 	checker
INCLUDE			= 	include
SRCDIR			= 	src/
OBJDIR			= 	objs/

SRCS			= 	$(SRCDIR)push_swap.c \
					$(SRCDIR)moves.c \
					$(SRCDIR)k_sort.c \
					$(SRCDIR)utils_aux.c \
					$(SRCDIR)utils_args.c \
					$(SRCDIR)utils_sort.c
OBJS			= 	$(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

CHECKER_SRCS	= 	$(SRCDIR)checker.c \
					$(SRCDIR)moves.c \
					$(SRCDIR)utils_aux.c \
					$(SRCDIR)utils_args.c \
					$(SRCDIR)checker_utils.c
CHECKER_OBJS	= 	$(CHECKER_SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

LIBFT			= 	src/libft/
LIBFT_A			= 	$(LIBFT)libft.a

RM				= 	rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
				@echo "Creating objects 🔨🪛"
				@$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)
				@echo "Cooking up the program 🍲🍳"
				@echo "✅ Done ✅"

$(CHECKER): $(CHECKER_OBJS) $(LIBFT_A)
				@$(CC) $(CHECKER_OBJS) $(LIBFT_A) -o $(CHECKER)
				@echo "✅ checker built"

$(LIBFT_A):
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

$(OBJDIR)%.o: $(SRCDIR)%.c
				@mkdir -p $(OBJDIR)
				@$(CC) -c $< -o $@

bonus: $(CHECKER)

clean:
				@$(RM) $(OBJS) $(CHECKER_OBJS)
				@rm -rf $(OBJDIR)
				@make -C $(LIBFT) clean -s
				@echo "Cleaning up... 🧹💨"

fclean: clean
				@make -C $(LIBFT) fclean -s
				@$(RM) $(NAME)
				@$(RM) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus