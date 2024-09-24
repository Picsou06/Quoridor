CC = gcc
CFLAGS = -Wall -I./header
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXEC = ./bin/program.exe
HEADER_DIR = ./header

# Règle principale
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	@mkdir -p ./bin
	$(CC) $(OBJ) -o $(EXEC)

# Compilation des fichiers objets
%.o: %.c $(HEADER_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f *.o $(EXEC)

# Nettoyage complet
fclean: clean
	rm -rf ./bin

# Rebuild complet
re: fclean all
