section .text
    global ft_write
    extern ___error

ft_write:
    mov rax, 1
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
