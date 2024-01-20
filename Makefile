### COMPILATION ###
CC = cc
CFLAGS = -Wall -Wextra -Werror

### INCLUDES ###
PROJECT = fract_ol
PROJECT_DIR = ./

SRC_DIR = src
SRC_FILE = $(SRC_DIR)/ft_math.c $(SRC_DIR)/complex.c $(SRC_DIR)/ft_str_to_double.c \
			$(SRC_DIR)/colors.c $(SRC_DIR)/ft_mlx.c \
			$(SRC_DIR)/arg_setter.c $(SRC_DIR)/arg_parser.c \
			$(SRC_DIR)/hook.c $(SRC_DIR)/env.c	$(SRC_DIR)/fract_ol.c \
			$(SRC_DIR)/main.c
			   
			  

BONUS_DIR =
BONUS_FILE = 

# Development tools -> printing stuff
TOOLS_DIR = tools
TOOLS_FILE = $(TOOLS_DIR)/print_fract_ol.c

# BONUS_FILE = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
# 			 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
# 			 ft_lstmap.c

### HEADER FILE ###
HEADER_DIR = includes

# MNIILIBX
MLX_DIR = miniLibX
MLX = mlx
MLX_FLAG = -L$(MLX_DIR) -lmlx -lXext -lX11

# MATH
MATH_FLAG = -lm

# LIBFT
FT_DIR = ./libft
FT = ft
FT_FLAG = -L$(FT_DIR) -l$(FT)

## OBJECT FILE ###
OBJ_DIR = .obj
OBJ_SRC = $(addprefix $(SRC_DIR)/, $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILE:.c=.o))))
# OBJ_TOOLS = $(addprefix $(SRC_DIR)/, $(addprefix $(OBJ_DIR)/, $(notdir $(TOOLS_FILE:.c=.o))))

.PHONY=bonus

### RULES ###
all : $(PROJECT)

$(PROJECT) : $(OBJ_SRC) $(OBJ_TOOLS)
	make -C $(MLX_DIR)
	make -C $(FT_DIR)
	$(CC) -g3 $(CFLAGS) $(OBJ_SRC) -o $(PROJECT) $(FT_FLAG) $(MLX_FLAG) $(MATH_FLAG)

$(SRC_DIR)/$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -g3 $(CFLAGS) -I ./$(HEADER_DIR)  -c $< -o $@

# bonus : $(OBJ_BONUS)
# 	make -C $(FT_DIR)
# 	$(CC) $(CFLAGS) $(OBJ_BONUS) -o checker $(FT_FLAG)

# $(BONUS_DIR)/$(OBJ_DIR)/%.o : $(BONUS_DIR)/%.c
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -I $(BONUS_DIR) -c $< -o $@
# 
# %.o : %.c
# 	$(CC) -g3 $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(OBJ_DIR)/$@

fclean : clean
	rm -f $(PROJECT)
	@cd $(FT_DIR) && make fclean

#Suppresion des fichiers objet
clean :
	rm -f $(SRC_DIR)/$(OBJ_DIR)/*.o
	@rm -df $(SRC_DIR)/$(OBJ_DIR)/
	rm -f $(BONUS_DIR)/$(OBJ_DIR)/*.o
	@rm -df $(BONUS_DIR)/$(OBJ_DIR)/
	@cd $(FT_DIR) && make clean

re : fclean all
