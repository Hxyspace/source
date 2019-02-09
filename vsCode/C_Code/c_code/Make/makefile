
CC = gcc

Path = ..\SDL2\1.shadow
File = main

CFLASS = -Wall -mwindows -lmingw32 -lSDL2main -lSDL2

EXE = $(Path)\$(File).exe
OBJ = $(Path)\$(File).o

$(EXE):$(OBJ) icon.o
	@$(CC) $^ $(CFLASS) -o $@
$(Path)\%.o:$(Path)\%.c 
	@$(CC) -c $^ -o $@
clean:
	@del $(OBJ)