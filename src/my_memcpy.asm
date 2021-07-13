BITS 64

section .text
    global my_memcpy

%ifndef TU
    global memcpy
%endif

memcpy:
my_memcpy:
    mov rax, rdi

.loop:
    cmp rdx, 0
    je .return
    mov bl, byte [rsi]
    mov byte [rdi], byte bl
    inc rdi
    inc rsi
    dec rdx
    jnz .loop

.return:
    ret
