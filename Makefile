# compilador a ser utilizado
CC=gcc

# pasta com arquivos header
INC=./include
BUILD=./build
SRC=./src

SRCS=./src/save.c ./src/dialogo.c
OBJS=./build/save.o ./build/dialogo.o

RAYLIB_INC=./bibliotecas/raylib-5.5_linux_amd64/include
RAYLIB_LD=./bibliotecas/raylib-5.5_linux_amd64/lib/

RAYGUI_INC=./bibliotecas/raygui-4.0/src
RAYGUI_LD=$(RAYGUI_INC)

all: ./build/dialogo.o ./build/save.o ./build/logicus

# compila arquivos separadamente
./build/dialogo.o: ./src/dialogo.c
	gcc -c -I$(INC) $(SRC)/dialogo.c -o ./build/dialogo.o

./build/save.o: ./src/save.c
	gcc -c -I$(INC) $(SRC)/save.c -o ./build/save.o

# linkagem dos arquivos em um executavel
./build/logicus: ./src/main.c
	$(CC) ./src/main.c -o $(BUILD)/logicus $(OBJS) -I$(INC) -I$(RAYLIB_INC) -I$(RAYGUI_INC) -L$(RAYLIB_LD) -L$(RAYGUI_LD) -Wl,-rpath,$(RAYLIB_LD) -Wl,-rpath,$(RAYGUI_LD) -lraylib -lraygui

clean:
	rm ./build/*
