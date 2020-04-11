/*
 * @Author: xinyuan
 * @Date: 2020-02-22 00:08:18
 * @Last Modified by: xinyuan
 * @Last Modified time: 2020-02-22 00:24:43
 * @流水灯
 */

    org 0000h
    ajmp main
    org 0100h

main:
    mov a,#0feh
    led:
        mov p2,a
        acall delay
        rl a            //rl 循环左移
        ajmp led

delay:
    mov r7,#10
    dl2:mov r6,#200
    dl1:mov r5,#250
    djnz r5,$
    djnz r6,dl1
    djnz r7,dl2
    ret

end
