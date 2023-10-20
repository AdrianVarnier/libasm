section .text
    global ft_list_remove_if

; Used registers: RDI, RSI, RDX, RCX, R8, R9, R10, R11

ft_list_remove_if:
    cmp qword [rdi], 0  ; null check
    jz return
    cmp rsi, 0
    jz return
    cmp rdx, 0
    jz return
    cmp rcx, 0
    jz return
    mov r8, [rdi]       ; init actual to begin
    mov r9, 0           ; init last to null

loop:
    cmp r8, 0           ; check end
    jz return
    push rdi            ; call cmp
    push rsi
    push rdx
    push rcx
    push r8
    mov rdi, [r8]
    call rdx
    pop r8
    pop rcx
    pop rdx
    pop rsi
    pop rdi
    cmp eax, 0          ; if cmp != 0 remove
    jz remove
    mov r9, r8          ; increment last
    mov r8, [r8 + 8]    ; increment actual
    jmp loop

remove:
    mov r10, r8         ; remove actual and fix list
    mov r11, [r8 + 8]
    mov [r8], r11
    mov r8, r11
    cmp r9, 0
    jz first_elem
    mov [r9 + 8], r11
    jmp free

first_elem:
    mov [rdi], r11      ; update begin
    jmp free

free:
    push rdi            ; free actual
    push rsi
    push rdx
    push rcx
    push r8
    push r9
    mov rdi, r10
    call rcx
    pop r9
    pop r8
    pop rcx
    pop rdx
    pop rsi
    pop rdi
    jmp loop

return:
    ret