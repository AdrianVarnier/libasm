section .text
    global ft_list_remove_if

ft_list_remove_if:
    mov r10, rdx        ; save cmp function
    mov r11, rcx        ; save free function
    mov r12, rdi        ; save list begin
    mov r13, [r12]      ; init at the begining of the list

start:
    cmp r13, 0          ; check end
    jz return
    mov rdi, [r13]
    call r10
    cmp eax, 0          ; if cmp = 0 erase element
    jz erase1
    mov r13, [r13 + 8]  ; increment list
    jmp loop

erase1:                 ; erase first element and update begin
    mov r14, [r13 + 8]
    mov [r12], r14
    mov rdi, r13
    call r11
    mov r13, [r12]      ; increment list

loop:
    cmp r13, 0          ; check end
    jz return
    mov rdi, [r13]
    call r10
    cmp eax, 0          ; if cmp = 0 erase element
    jz erase2
    mov r13, [r13 + 8]  ; increment list
    jmp loop

erase2:
    mov r14, [r13 + 8]
    mov r15, [r13]
    mov [r13], r14
    mov rdi, [r15]
    call r11
    mov r13, r14      ; increment list
    jmp loop

return:
    ret