section .text
    global ft_atoi_base
    extern ft_check_base
    extern ft_strlen
    extern ft_is_base
    extern ft_get_base_value

; Argument: RDI, RSI
; Modified: RAX, RCX, R8, R9, R10

ft_atoi_base:
    cmp rdi, 0          ; check null string
    jz return_error
    cmp rsi, 0          ; check null base
    jz return_error
    push rdi            ; check_base
    mov rdi, rsi
    call ft_check_base
    pop rdi
    cmp eax, 1
    je return_error
    push rdi
    mov rdi, rsi
    call ft_strlen      ; get base len
    pop rdi
    xor rcx, rcx        ; init counter, number, sign
    mov r8d, 1
    xor r9d, r9d
    mov r10d, eax

space_loop:
    cmp byte [rdi + rcx], 0     ; pass withespace
    je return_error
    cmp byte [rdi + rcx], 10
    je space_inc
    cmp byte [rdi + rcx], 11
    je space_inc
    cmp byte [rdi + rcx], 12
    je space_inc
    cmp byte [rdi + rcx], 13
    je space_inc
    cmp byte [rdi + rcx], 32
    je space_inc
    jmp sign_loop

space_inc:
    inc rcx
    jmp sign_loop

sign_loop:
    cmp byte [rdi + rcx], 0     ; get sign
    je return_error
    cmp byte [rdi + rcx], 43
    je pos_inc
    cmp byte [rdi + rcx], 45
    je neg_inc
    jmp loop

pos_inc:
    imul r8d, 1
    inc rcx
    jmp sign_loop

neg_inc:
    imul r8d, -1
    inc rcx
    jmp sign_loop

loop:
    cmp byte [rdi + rcx], 0     ; check null
    je return
    mov rdx, rcx
    push r8
    call ft_is_base             ; check if in base
    pop r8
    cmp eax, 0
    je return
    mov rdx, rcx
    push r8
    call ft_get_base_value      ; get base value
    pop r8
    imul r9d, r10d              ; mul by ten
    add r9d, eax                ; add base value
    inc rcx
    jmp loop

return:
    imul r9d, r8d               ; mul by sign
    mov eax, r9d
    ret

return_error:
    mov eax, 0
    ret