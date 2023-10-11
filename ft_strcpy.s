section .text
    global _ft_strcpy
    extern _ft_strlen
_ft_strcpy:
    push rdi
    mov rdi, rsi
    call _ft_strlen
    mov ax, cx
    pop rdi
    mov [rdi + cx], 0
    rep movsb
    mov rax, rdi
    ret