on error resume next

Dim fso

Set fso = CreateObject("Scripting.FileSystemObject")

fso.CopyFolder"D:\�����Ӱ˵��ļ�\Git��\make",".\\",False

set oFolder = fso.GetFolder(".")

For each file in oFolder.Files
	sExt = LCase(fso.GetExtensionName(file))
	If sExt = "c" Then name = name & fso.GetBaseName(file)&".o "
Next

'�޸�gcc���� ��o�ļ�
Call AddLine(fso,"make\makefile",5,"CFLAGS = -g -Wall -mwindows -lmingw32 -lSDL2main -lSDL2"&Chr(10)&"OBJ = person.o "&name)

fso.DeleteFile"make\makefile"

fso.MoveFile "make"&"\New","make"&"\makefile"

Set Ws = CreateObject("WScript.Shell")
Ws.Run "cmd /c make\Compile.bat",0,True

fso.DeleteFolder"make"

Function AddLine(Fso,strPath,IntLine,strInput)
    '��ֻ���ķ�ʽ���ļ�
    Set ReadFile = Fso.OpenTextFile(strPath,1,true)
    '��ֻд�ķ�ʽ���ļ�
    Set WriteFile = Fso.OpenTextFile("make\New",2,true)
    '�����ǰ��ָ�벻�������ĵ���ĩβ����ȡ�ı�����������
    Do Until ReadFile.AtEndOfStream
        WriteFile.WriteLine ReadFile.ReadLine
        IntLine = IntLine - 1
        '�жϹ���Ƿ��Ѵﵽָ���У��ﵽ���˳�����       
        If IntLine = 0 Then
           WriteFile.WriteLine strInput
        End If
    Loop
    ReadFile.Close
    WriteFile.Close
End Function