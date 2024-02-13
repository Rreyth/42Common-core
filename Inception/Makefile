NAME = Inception

all:
	@mkdir -p /home/tdhaussy/data/database /home/tdhaussy/data/www
	@docker compose -f srcs/docker-compose.yml up --build -d
	
clean:
	@docker compose -f srcs/docker-compose.yml down
	
fclean:	clean
	@docker image rm $$(docker image ls -aq)  2>/dev/null || echo No image to delete
	@docker volume rm $$(docker volume ls -q) 2>/dev/null || echo No volume to delete
	@docker system prune -af
	@sudo rm -rf /home/tdhaussy/data

re: fclean all

.PHONY: all clean fclean re
