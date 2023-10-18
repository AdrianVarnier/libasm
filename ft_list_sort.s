section .text
    global ft_list_sort

ft_list_sort:
    cmp qword [rdi], 0  ; check NULL parameters
    jz return
    cmp qword rsi, 0
    jz return
    mov r10, rsi        ; save cmp function in r10
    mov r11, [rdi]      ; save begin in r11

start:
    mov r12, r11        ; start from the begining of the list
    jmp loop

loop:
    inc r8
    mov r13, [r12 + 8]  ; increment next list
    cmp r13, 0          ; check end
    jz return
    mov rdi, [r12]      ; call cmp(actual, next)
    mov rsi, [r13]
    call r10
    cmp eax, 0          ; if ret > 0, swap list data
    jg swap
    mov r12, r13        ; increment actual list
    jmp loop

swap:
    mov r14, [r12]      ; swap actual and next data
    mov r15, [r13]
    mov [r12], r15
    mov [r13], r14
    jmp start

return:
    ret