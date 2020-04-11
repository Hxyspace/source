/*
 * @Author: xinyuan
 * @Date: 2020-02-24 21:09:00
 * @Last Modified by: xinyuan
 * @Last Modified time: 2020-02-24 22:52:22
 * @矩阵按键
 */

	ORG 0000H
    AJMP MAIN
    ORG 30H
    DB 0c0h,0f9h,0a4h,0b0h,99h,92h,82h,0f8h,80h,90h         //数字段码
    KEYVAL EQU 40H

MAIN:
    MOV DPTR, #30H
    MOV KEYVAL, #00H
S:  ACALL JUDGE
    ACALL DISPLAY
    AJMP S

JUDGE:
    MOV A, #0F0H            //列置1 行置0
    MOV P1, A
    XRL A, P1
    JZ BREAK                //如果异或之后，A != 0， 则说明有按键
    ACALL DELAY10MS
    MOV A, #0F0H
    XRL A, P1
    JZ BREAK                //延时消抖后再判断，如果为 0 ，说明无按键，跳出
    ACALL JUDGEC            //转去判断具体为哪一列
BREAK:
    RET

JUDGEC:
    MOV A, #10H
CC1:MOV R0, A
    INC KEYVAL
    XRL A, #0F0H
    XRL A, P1
    JNZ CNEXT
    ACALL JUDGER
    RET
CNEXT:MOV A, R0
    RL A
    CJNE A, #80H, CC1
    INC KEYVAL
    ACALL JUDGER
    RET

JUDGER:
    MOV A, #0FH
    MOV P1, A

    MOV R0, #01H
RR1:MOV A, KEYVAL
    ADD A, #4
    MOV KEYVAL, A
    MOV A, R0
    XRL A, #0FH
    XRL A, P1
    JNZ RNEXT
    RET
RNEXT:MOV A, R0
    RL A
    MOV R0, A
    CJNE A, #08H, RR1
    MOV A, KEYVAL
    ADD A, #4
    MOV KEYVAL, A
    RET

DISPLAY:
    MOV A, KEYVAL
    MOV B, #10
    DIV AB

    CLR P2.1
    SETB P2.0
    MOV DPTR, #30H
    MOVC A, @A+DPTR
    MOV P0, A
    ACALL DELAY0_5MS

    MOV A, B
    CLR P2.0
    SETB P2.1
    MOV DPTR, #30H
    MOVC A, @A+DPTR
    MOV P0, A
    ACALL DELAY0_5MS
    RET

DELAY10MS:
    MOV R7,#1
    DL2:MOV R6,#38
    DL1:MOV R5,#130
    DJNZ R5,$
    DJNZ R6,DL1
    DJNZ R7,DL2
    RET

DELAY0_5MS:
    MOV R7,#2
    DL3:MOV R5,#71
    DJNZ R5,$
    DJNZ R7,DL3
    RET

END