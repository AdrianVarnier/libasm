section .text
    global ft_check_base
    extern ft_strlen

; Argument: RDI
; Modified: R8, RCX, RAX

ft_check_base:
    call ft_strlen
    cmp rax, 1
    je return_error
    mov rax, -1

outer_loop:
    inc rax
    mov rcx, rax            ; increment check begin
    inc rcx
    mov r8b, [rdi + rax]    ; increment char to check
    cmp r8b, 0              ; check null
    je return
    cmp r8b, 9              ; check withespace
    je return_error
    cmp r8b, 10
    je return_error
    cmp r8b, 11
    je return_error
    cmp r8b, 12
    je return_error
    cmp r8b, 13
    je return_error
    cmp r8b, 32
    je return_error
    cmp r8b, 43             ; check + and -
    je return_error
    cmp r8b, 45
    je return_error
    jmp inner_loop

inner_loop:
    cmp byte [rdi + rcx], 0     ; check null
    je outer_loop
    cmp byte [rdi + rcx], r8b   ; check duplicate
    je return_error
    inc rcx                     ; increment
    jmp inner_loop

return:
    mov rax, 0
    ret

return_error:
    mov rax, 1
    ret