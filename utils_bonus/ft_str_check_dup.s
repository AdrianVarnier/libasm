section .text
    global ft_str_check_dup

ft_str_check_dup:
    mov rax, -1

loop_outer:
    inc rax
    mov rcx, rax
    inc rcx
    mov r8b, [rdi + rax]
    cmp r8b, 0
    je return
    jmp loop_inner

loop_inner:
    cmp byte [rdi + rcx], 0
    je loop_outer
    cmp byte [rdi + rcx], r8b
    je return_error
    inc rcx
    jmp loop_inner

return:
    mov rax, 0
    ret

return_error:
    mov rax, 1
    ret