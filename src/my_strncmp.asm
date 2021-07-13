BITS 64

section .text
    global my_strncmp

%ifndef TU
    global strncmp
%endif

strncmp:
my_strncmp:
.loop:
    cmp rdx, 0
    je .return
    cmp byte [rdi], 0
    je .return
    cmp byte [rsi], 0
    je .return
    mov al, byte [rsi]
    cmp byte [rdi], al
    jne .return
    dec rdx
    cmp rdx, 0
    je .return
    inc rdi
    inc rsi
    jnz .loop

.return:
    mov al, byte [rdi]
    mov r8b, byte [rsi]
    sub al, r8b
    movsx rax, al
    ret
