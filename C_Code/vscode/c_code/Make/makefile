
CC = gcc

Path = ..\hello
File = hello

EXE = $(Path)\$(File).exe
OBJ = $(Path)\$(File).o

$(EXE):$(OBJ)
	@$(CC) $^ -o $@
$(Path)\%.o:$(Path)\%.c 
	@$(CC) -c $^ -o $@
clean:
	@del $(OBJ)