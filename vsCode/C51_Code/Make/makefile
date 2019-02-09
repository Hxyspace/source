#编译器and连接器and生成.hex
CC = c51
BL = BL51
OH = OH51

#路径and文件
Path = ..\12.LCD
File = Lcdtest

CODE = $(Path)\$(File).c
OBJ = $(Path)\$(File).OBJ
OHX = $(File)
HEX = $(File).hex

$(HEX):$(OHX)
	$(OH) $^
	@move $(HEX) $(Path)
$(OHX):$(OBJ)
	$(BL) $^ TO $@
$(OBJ):$(CODE)
	$(CC) $^
#清除
clean:
	@del $(OBJ) $(OHX) $(File).M51 $(Path)\\$(File).LST
