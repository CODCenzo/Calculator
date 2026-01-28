# Variáveis de compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g -Iinclude
LDFLAGS = -lm

# Definição de diretórios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
EXEC = calc

# Localiza automaticamente todos os arquivos .c na pasta src
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Mapeia os arquivos .o correspondentes dentro da pasta build
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Alvo principal
all: $(OBJ_DIR) $(EXEC)

# Linkagem do executável final
$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# Compilação dos arquivos de objeto (.o)
# O símbolo $< refere-se ao arquivo .c e $@ ao arquivo .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cria a pasta build caso ela não exista
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Evita conflitos com arquivos de mesmo nome e otimiza a execução
.PHONY: all clean