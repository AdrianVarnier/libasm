section .text
    global ft_list_sort

; Used registers: RDI, RSI, RBX, R8, R9, R10, R11

ft_list_sort:
    cmp qword [rdi], 0  ; check NULL parameters
    jz return1
    cmp qword rsi, 0
    jz return1
    mov rbx, rsi        ; rbx = cmp
    push rdi            ; save begin

start:
    pop rdi
    mov r8, [rdi]        ; init at begin
    push rdi

loop:
    mov r9, [r8 + 8]    ; increment list
    cmp r9, 0           ; check end
    jz return2
    mov rdi, [r8]       ; call cmp(actual, next)
    mov rsi, [r9]
    push r8
    push r9
    push rbx
    call rbx
    pop rbx
    pop r9
    pop r8
    cmp eax, 0          ; if ret > 0, swap list data
    jg swap
    mov r8, r9          ; increment actual list
    jmp loop

swap:
    mov r10, [r8]      ; swap actual and next data
    mov r11, [r9]
    mov [r8], r11
    mov [r9], r10
    jmp start

return1:
    ret

return2:
    pop rdi
    ret