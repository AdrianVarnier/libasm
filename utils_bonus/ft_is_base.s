section .text
    global ft_is_base

; Argument: RDI, RSI, RDX
; Modified: RAX, R8

ft_is_base:
    xor rax, rax

loop:
    mov r8b, [rsi + rax]
    cmp r8b, 0
    je return_error
    cmp [rdi + rdx], r8b
    je return
    inc rax
    jmp loop

return_error:
    mov rax, 0
    ret

return:
    mov rax, 1
    ret