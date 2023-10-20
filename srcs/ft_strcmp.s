section .text
    global ft_strcmp

ft_strcmp:
    xor rcx, rcx
    xor rax, rax

loop:
    mov al, BYTE[rdi + rcx]
    cmp BYTE[rdi + rcx], 0
    jz end
    cmp BYTE[rsi + rcx], 0
    jz end
    cmp al, BYTE[rsi + rcx]
    jne end
    inc rcx
    jmp loop

end:
    sub al, BYTE[rsi + rcx]
    movsx eax, al
    ret