section .text
    global ft_atoi_base
    extern ft_strlen

ft_atoi_base:
    cmp rdi, 0          ; check null string
    jz return_error
    cmp rsi, 0          ; check null base
    jz return_error
    push rdi            ; check len = 1 base
    push rsi
    mov rdi, rsi
    call ft_strlen
    pop rsi
    pop rdi
    cmp eax, 1
    je return_error

return:
    mov rax, 1
    ret

return_error:
    mov rax, 0
    ret