# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mianni <mianni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 10:52:49 by mianni            #+#    #+#              #
#    Updated: 2025/02/24 14:32:31 by mianni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

# Définition des chemins pour les bibliothèques (Libft et MiniLibX sont dans includes/)
INCLUDES_DIR = ./includes
LIBFT_PATH = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = $(INCLUDES_DIR)/minilibx-linux
MLX = $(MLX_PATH)/libmlx.a

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
	MLX = $(MLX_PATH)/libmlx_Linux.a
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -L$(MLX_PATH) -lmlx
endif

# Définition du dossier de code source obligatoire
MANDATORY_DIR = mandatory

# Dossier de compilation et d'objets (uniquement obligatoire)
BUILD_DIR = $(MANDATORY_DIR)
OBJ_DIR = $(BUILD_DIR)/obj

# Définition des fichiers sources
SRCS = $(BUILD_DIR)/parsing/parsing_ressources.c $(BUILD_DIR)/parsing/error_parsing.c \
		$(BUILD_DIR)/parsing/parsing_map.c $(BUILD_DIR)/utils/parsing_utils.c \
		$(BUILD_DIR)/utils/parsing_utils2.c $(BUILD_DIR)/utils/init_utils.c \
		$(BUILD_DIR)/init/init_struct.c $(BUILD_DIR)/core/sword.c\
		$(BUILD_DIR)/init/init_minilibx.c $(BUILD_DIR)/core/minimap.c \
		$(BUILD_DIR)/core/moves.c $(BUILD_DIR)/core/ray_casting.c \
		$(BUILD_DIR)/utils/utils.c $(BUILD_DIR)/utils/moves_utils.c \
		$(BUILD_DIR)/utils/raycasting_utils.c $(BUILD_DIR)/utils/utils_bis.c \
		$(BUILD_DIR)/utils/minimap_utils.c $(BUILD_DIR)/utils/moves_utils2.c \
		$(BUILD_DIR)/utils/parsing_utils3.c $(BUILD_DIR)/utils/init_utils2.c \
		$(BUILD_DIR)/main.c $(BUILD_DIR)/parsing/parsing_ressources2.c

OBJS = $(SRCS:$(BUILD_DIR)/%.c=$(OBJ_DIR)/%.o)

# Définition de l'exécutable
TARGET = cub3D

# Couleurs
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

# Règle par défaut : compilation de l'exécutable obligatoire
all: $(TARGET)

# Création des dossiers nécessaires pour les objets
$(OBJ_DIR):
	@mkdir -p $(dir $(OBJS))

# Compilation de la Libft
$(LIBFT):
	@echo "${YELLOW}Compiling Libft...${NC}"
	@$(MAKE) -C $(LIBFT_PATH) >/dev/null
	@echo "${GREEN}Libft compiled successfully!${NC}"

# Compilation de la MiniLibX
$(MLX):
	@echo "${YELLOW}Compiling MiniLibX...${NC}"
	@$(MAKE) -C $(MLX_PATH) >/dev/null
	@echo "${GREEN}MiniLibX compiled successfully!${NC}"

# Compilation de l'exécutable
$(TARGET): $(OBJ_DIR) $(OBJS) $(LIBFT) $(MLX)
	@echo "${YELLOW}Compiling $(TARGET)...${NC}"
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -lm -I$(BUILD_DIR)
	@echo "${GREEN}$(TARGET) compiled successfully!${NC}"

# Compilation des fichiers objets en respectant la hiérarchie
$(OBJ_DIR)/%.o: $(BUILD_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(BUILD_DIR) -I$(INCLUDES_DIR)/libft -I$(INCLUDES_DIR)/minilibx-linux

# Nettoyage des fichiers objets
clean:
	@echo "${RED}Cleaning up object files...${NC}"
	@rm -rf $(MANDATORY_DIR)/obj
	@$(MAKE) clean -C $(LIBFT_PATH) >/dev/null
	@$(MAKE) clean -C $(MLX_PATH) >/dev/null

# Nettoyage complet (fichiers objets + binaires)
fclean: clean
	@echo "${RED}Cleaning up binary files...${NC}"
	@rm -f $(TARGET)
	@$(MAKE) fclean -C $(LIBFT_PATH) >/dev/null
	@$(MAKE) -C $(MLX_PATH) clean >/dev/null

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
