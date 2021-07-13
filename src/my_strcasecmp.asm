BITS 64

section .text
    global my_strcasecmp

%ifndef TU
    global strcasecmp
%endif

strcasecmp:
my_strcasecmp:
.loop:
    cmp byte [rdi], 0
    je .return
    cmp byte [rsi], 0
    je .return
    mov al, byte [rsi]
    cmp byte [rdi], al
    jg .upper_right
    jl .upper_left
    inc rdi
    inc rsi
    jnz .loop

.upper_right:
    add al, 32
    cmp byte [rdi], al
    jne .return
    inc rdi
    inc rsi
    jmp .loop

.upper_left:
    mov r8b, byte [rdi]
    add r8b, 32
    cmp r8b, al
    jne .return
    inc rdi
    inc rsi
    jmp .loop

.return:
    mov al, byte [rdi]
    mov r8b, byte [rsi]
    sub al, r8b
    movsx rax, al
    ret
