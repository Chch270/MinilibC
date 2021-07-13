BITS 64

section .text
    global my_strlen

%ifndef TU
    global strlen
%endif

strlen:
my_strlen:
    xor rax, rax

.loop:
    cmp byte [rdi + rax], 0
    je .return
    inc rax
    jne .loop

.return:
    ret
