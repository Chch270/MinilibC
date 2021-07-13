BITS 64

extern memcpy

section .text
    global my_memmove

%ifndef TU
    global memmove
%endif

memmove:
my_memmove:
    cmp rdi, rsi
    jle .call_memcpy
    mov rax, rdi
    mov r8, rsi
    mov rcx, rdx
    sub rcx, 1

.loop:
    cmp rdx, 0
    je .return
    mov r9b, byte [r8 + rcx]
    mov byte [rdi + rcx], byte r9b
    dec rcx
    dec rdx
    jmp .loop

.call_memcpy:
    call memcpy wrt ..plt

.return:
    ret
