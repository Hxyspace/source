/*
 * @Author: xinyuan
 * @Date: 2020-02-23 15:57:09
 * @Last Modified by: xinyuan
 * @Last Modified time: 2020-02-24 22:17:37
 * @动态显示数码管
 */

	ORG 0000H
    AJMP MAIN
    ORG 30H
    DB 0c0h,0f9h,0a4h,0b0h,99h,92h,82h,0f8h,80h         //段码
    DB 01H,02H,04H,08H,10H,20H,40H,80H                  //位选

MAIN:
    S:
        MOV R0, #8
    SS:
        MOV A,R0
        MOV DPTR, #38H
        MOVC A, @A+DPTR
        MOV P2,A            //位选

        MOV A,R0
        MOV DPTR, #30H
        MOVC A, @A+DPTR
        MOV P0,A            //显示

        ACALL DELAY
        DJNZ R0, SS         //动态循环
        AJMP S

DELAY:
    MOV R7,#255
    DJNZ R7,$
    RET

END