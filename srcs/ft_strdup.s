section .text
    global ft_strdup
    extern ft_strlen
    extern ft_strcpy
    extern malloc

ft_strdup:
    call ft_strlen
    inc rax
    push rdi
    mov rdi, rax
    call malloc wrt ..plt
    pop rsi
    mov rdi, rax
    call ft_strcpy
    ret