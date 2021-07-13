BITS 64

extern strchr
section .text
    global my_strpbrk

%ifndef TU
    global strpbrk
%endif

strpbrk:
my_strpbrk:
    xor rax, rax
    mov r8, rsi
    mov rsi, rdi
    mov rdi, r8
    mov r8, rsi

.loop:
    cmp byte [r8], 0
    je .return_null
    movsx rsi, byte [r8]
    call strchr wrt ..plt
    cmp rax, 0
    jne .return
    inc r8
    jmp .loop

.return_null:
    mov rax, 0
    ret

.return:
    mov rax, r8
    ret
