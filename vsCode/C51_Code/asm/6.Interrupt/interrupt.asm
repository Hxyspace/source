/*
 * @Author: xinyuan
 * @Date: 2020-02-26 16:42:13
 * @Last Modified by: xinyuan
 * @Last Modified time: 2020-02-26 17:02:13
 * @中断
 */

	ORG 0000H
    LJMP MAIN

    ORG 0003H
    LJMP CHANGE
    ORG 0100H

MAIN:
    MOV SP,#60
    SETB P3.2           //由于准双口特性，令P3.2输出1  为读引脚做准备
    MOV 30H,#00H

    SETB EX0    //允许外部中断0
    CLR IT0     //电平触发方式， 低电平有效
    SETB EA     //中断允许总控制位
    SJMP $

CHANGE:
    PUSH PSW
    PUSH ACC

    //p0口取反
    MOV A, 30H
    XRL A, #0FFH
    MOV 30H, A
    MOV P0, A

    ACALL DELAY

    POP ACC
    POP PSW
    RETI

//延时0.5s
DELAY:
    MOV R7,#167
    DL2:MOV R6,#171
    DL1:MOV R5,#8
    DJNZ R5,$
    DJNZ R6,DL1
    DJNZ R7,DL2
    NOP
    RET

END
