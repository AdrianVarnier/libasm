section .text
    global ft_get_base_value

; Argument: RDI, RSI, RDX
; Modified: RAX

ft_get_base_value:
    xor rax, rax

loop:
    mov r8b, [rsi + rax]
    cmp r8b, 0
    je return
    cmp r8b, [rdi + rdx]
    je return
    inc rax
    jmp loop

return:
    ret