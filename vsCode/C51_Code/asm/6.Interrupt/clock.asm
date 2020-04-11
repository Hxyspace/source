    ORG 0000H
    AJMP MAIN   ;转向主程序
    ORG 001BH
    LJMP IT1P   ;转T1中断服务程序
    ORG 0030H
    DB 0c0H,0f9H,0a4H,0b0H,99H,92H,82H,0f8H,80H,90H
    ORG 0100H

MAIN:
    MOV SP,#60H     ;主程序,设堆栈指针
    CLR A
    MOV 40H, A
    MOV 41H, A
    MOV 42H, A
    MOV TMOD,#10H   ;T1为模式 1
    MOV 30H,#64H    ;设置中断计数器次数
    SETB ET1
    SETB EA
    MOV TH1, #0D8H   ;设置计数初值
    MOV TL1, #0EFH
    SETB TR1
LOOP: LCALL SHOW1   ;调用显示子程序
    SJMP LOOP

IT1P:
    PUSH PSW
    PUSH ACC
    MOV TH1, #0D8H       ;重新装入计数初值
    MOV TL1, #0EFH
    DJNZ 30H, RETURN    ;1秒未到,返回
    MOV 30H, #64H       ;重置中断次数
    INC 40H             ;“秒”单元增1
    MOV A, 40H
    DA A
    MOV 40H, A
    CJNE A, #60H,RETURN  ;判断是否到60秒,未到则返回
    MOV 40H, #00H       ;计满60秒,“秒”单元清零
    INC 41H             ;“分”单元增1
    MOV A, 41H
    DA A
    MOV 41H, A
    CJNE A, #60H, RETURN     ;判断是否到60分,未到则返回
    MOV 41H, #00H           ;计满60分,“分”单元清零
    INC 42H                 ; “时”单元增1
    MOV A, 42H
    DA A
    MOV 42H, A
    CJNE A, #24H,RETURN      ;判断是否到24小时,未到则返回
    MOV 42H, #00H           ;计满24小时,“时”单元清零
RETURN:POP ACC              ;恢复现场
    POP PSW
    RETI

SHOW1:
    MOV DPTR, #30H
    MOV A, #01H
    MOV P2, A
    MOV A, 42H
    ANL A, #0F0H
    SWAP A
    MOVC A, @A+DPTR
    MOV P0, A           ;时的十位
    LCALL DELAY

    MOV A, #02H
    MOV P2, A
    MOV A, 42H
    ANL A, #0FH
    MOVC A, @A+DPTR
    ANL A, #7FH
    MOV P0, A
    LCALL DELAY

    MOV A, #04H
    MOV P2, A
    MOV A, 41H
    ANL A, #0F0H
    SWAP A
    MOVC A, @A+DPTR
    MOV P0, A           ;分的十位
    LCALL DELAY

    MOV A, #08H
    MOV P2, A
    MOV A, 41H
    ANL A, #0FH
    MOVC A, @A+DPTR
    ANL A, #7FH
    MOV P0, A
    LCALL DELAY

    MOV A, #10H
    MOV P2, A
    MOV A, 40H
    ANL A, #0F0H
    SWAP A
    MOVC A, @A+DPTR
    MOV P0, A           ;秒的十位
    LCALL DELAY

    MOV A, #20H
    MOV P2, A
    MOV A, 40H
    ANL A, #0FH
    MOVC A, @A+DPTR
    MOV P0, A
    LCALL DELAY
    RET

//延时0.5ms
DELAY:
    MOV R7,#2
    DL1:MOV R5,#71
    DJNZ R5,$
    DJNZ R7,DL1
    RET

END