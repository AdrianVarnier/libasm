section .text
    global ft_list_sort

ft_list_sort:
    cmp qword [rdi], 0
    jz return
    mov r10, [rdi]
    mov r11, rsi

start_loop:
    mov r12, r10
    jmp loop

loop:
    mov r13, [r12 + 8]
    cmp r13, 0
    jz return
    mov rdi, r12
    mov rsi, r13
    call r11
    cmp rax, 0
    jg swap
    mov r12, r13
    jmp loop

swap:
    mov r14, r12
    mov [r12], r13
    mov [r13], r14
    jmp start_loop

return:
    ret