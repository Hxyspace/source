/*
 * @Author: xinyuan
 * @Date: 2020-02-23 14:55:47
 * @Last Modified by: xinyuan
 * @Last Modified time: 2020-02-24 22:26:26
 * @数码管显示
 */

	org     0000h
    ajmp    main
    org     30h
    db      0c0h,0f9h,0a4h,0b0h,99h,92h,82h,0f8h,80h,90h

main:
    setb p2.0
    s:
        mov r1, #0
    ss:
        mov a, r1
        mov dptr, #30h
        movc a, @a+dptr
        mov p0, a

        acall delay
        inc r1
        cjne r1, #10, ss
        ajmp s

delay:
    mov r7,#10
    dl2:mov r6,#200
    dl1:mov r5,#250
    djnz r5,$
    djnz r6,dl1
    djnz r7,dl2
    ret

end

