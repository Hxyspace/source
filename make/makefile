#编译器常量
CC = gcc
CC2 = windres

#依赖参数

#依赖的头文件,如果需要头文件  要加参数  -I.

EXE = ..\main.exe

$(EXE): $(OBJ)
	@$(CC) $^ $(CFLAGS) -o $@
%.o: ..\%.c $(DEPS)
	@$(CC) -c $< $(CFLAGS) -o $@

#编译图标
%.o: %.rc
	@$(CC2) $^ -o $@

clean:
	@del $(OBJ)