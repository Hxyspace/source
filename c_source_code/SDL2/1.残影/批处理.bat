@echo off
if exist "error.txt" del error.txt

make  >>error.txt 2>&1
make clean

for %%a in ("error.txt") do (
	if "%%~za" equ "0" (
	del error.txt)
	)
exit