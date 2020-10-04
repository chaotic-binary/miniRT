NAME		=	miniRT

SRC_DIR		=	./src/
SRC			=	intersect_plane.c\
				intersect_sphere.c\
				intersect_triangle.c\
				intersect_square.c\
				intersect_cylinder_no_caps.c\
				intersect_cylinder_with_caps.c\
				intersect_cone.c\
				exit_cases.c\
				exit_parser.c\
				parser.c\
				parse_pl_tr_sq_sp_cy.c\
				parse_cu_py_co.c\
				parse_scene_info.c\
				parser_datacheck.c\
				parser_utils.c\
				get_next_line.c\
				normal_correct.c\
				normals_cy_co.c\
				normals_pl_tr_sq_sp.c\
				window.c\
				bmp.c\
				raytracer.c\
				render_utils.c\
				main.c\
				antialiasing.c

O_DIR		=	./bin
OBJ			=	$(addprefix $(O_DIR)/, $(SRC:c=o))

H_DIR		=	./Includes
INCLUDES	=	$(H_DIR)/*

LIB			=	./libft/libft.a \
				./libvector/libvector.a\
				./libmlx.dylib

FLAGS		= -Wall -Wextra -Werror

all bonus : $(NAME)

$(NAME)	:	$(OBJ) $(INCLUDES)
	@make -C ./minilibx_mms/
	@make -C ./libvector/
	@make bonus -C ./libft/
	@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(H_DIR) $(LIB)

$(O_DIR)/%.o: ./src/*/%.c $(INCLUDES) | $(O_DIR)
	@gcc -DSHINE=15  $(FLAGS) -I $(H_DIR) -c $< -o $@

$(O_DIR):
	@mkdir $(O_DIR)

clean:
	@rm -rf $(O_DIR)
	@echo "$(NAME) object files deleted"

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./minilibx_mms/
	@make fclean -C ./libvector/
	@make fclean -C ./libft/
	@rm -rf libmlx.dylib
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re bonus
