section .text
    global ft_list_push_front
    extern malloc

ft_list_push_front:
    push rsp
    push rdi
    push rsi
    mov rdi, 16
    call malloc wrt ..plt
    pop rsi
    pop rdi
    cmp rax, 0
    jz return
    mov [rax], rsi
    mov rsi, [rdi]
    mov qword [rax + 8], rsi
    mov [rdi], rax

return:    
    pop rsp
    ret