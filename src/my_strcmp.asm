BITS 64

section .text
    global my_strcmp

%ifndef TU
    global strcmp
%endif

strcmp:
my_strcmp:
.loop:
    cmp byte [rdi], 0
    je .return
    cmp byte [rsi], 0
    je .return
    mov al, byte [rsi]
    cmp byte [rdi], al
    jne .return
    inc rdi
    inc rsi
    jnz .loop

.return:
    mov al, byte [rdi]
    mov r8b, byte [rsi]
    sub al, r8b
    movsx rax, al
    ret
