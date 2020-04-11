/*
 * @Author: xinyuan
 * @Date: 2020-02-21 23:39:57
 * @Last Modified by: xinyuan
 * @Last Modified time: 2020-02-22 00:24:42
 * @program: LED闪烁
 */

    org 000h
    ajmp main
    org 0100h

main:
    clr p2.0
    acall delay
    setb p2.0
    acall delay
    ajmp main

    //延时程序1s (三循环)
delay:
    mov r7,#10
    dl2:mov r6,#200
    dl1:mov r5,#250
    djnz r5,$           //r5自减1 如果不等于0则跳转，“$”为当前地址，本条指令相当于 while(r5--)
    djnz r6,dl1         //r6自减1 不为零则跳转
    djnz r7,dl2
    ret

end
