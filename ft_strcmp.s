section .text
    global _ft_strcmp

_ft_strcmp:
    xor rcx, rcx
    xor rax, rax

check_end:
    cmp BYTE[rdi + rcx], 0
    jz end
    cmp BYTE[rsi + rcx], 0
    jz end

loop:
    jmp check_end
    mov al, BYTE[rdi + rcx]
    cmp al, BYTE[rsi + rcx]
    jne end
    inc rcx
    je loop

end:
    sub al, BYTE[rsi + rcx]
    ret