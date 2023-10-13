section .text
    global ft_read
    extern ___error

ft_read:
    mov rax, 0
    syscall
    test rax, rax
    js error
    ret

error:
    push rax
    pop r8
    call ___error
    mov [rax], r8
    mov rax, -1
    ret
