on error resume next

Dim fso

Set fso = CreateObject("Scripting.FileSystemObject")

fso.CopyFolder"D:\杂七杂八的文件\Git库\make",".\\",False

set oFolder = fso.GetFolder(".")

For each file in oFolder.Files
	sExt = LCase(fso.GetExtensionName(file))
	If sExt = "c" Then name = name & fso.GetBaseName(file)&".o "
Next

'修改gcc参数 和o文件
Call AddLine(fso,"make\makefile",5,"CFLAGS = -g -Wall -mwindows -lmingw32 -lSDL2main -lSDL2"&Chr(10)&"OBJ = person.o "&name)

fso.DeleteFile"make\makefile"

fso.MoveFile "make"&"\New","make"&"\makefile"

Set Ws = CreateObject("WScript.Shell")
Ws.Run "cmd /c make\Compile.bat",0,True

fso.DeleteFolder"make"

Function AddLine(Fso,strPath,IntLine,strInput)
    '以只读的方式打开文件
    Set ReadFile = Fso.OpenTextFile(strPath,1,true)
    '以只写的方式打开文件
    Set WriteFile = Fso.OpenTextFile("make\New",2,true)
    '如果当前的指针不在整个文档的末尾，读取文本的整行内容
    Do Until ReadFile.AtEndOfStream
        WriteFile.WriteLine ReadFile.ReadLine
        IntLine = IntLine - 1
        '判断光标是否已达到指定行，达到则退出函数       
        If IntLine = 0 Then
           WriteFile.WriteLine strInput
        End If
    Loop
    ReadFile.Close
    WriteFile.Close
End Function