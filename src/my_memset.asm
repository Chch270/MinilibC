BITS 64

section .text
    global my_memset

%ifndef TU
    global memset
%endif

memset:
my_memset:
    mov rax, rdi

.loop:
    cmp rdx, 0
    je .return
    mov byte [rdi], byte sil
    inc rdi
    dec rdx
    jne .loop

.return:
    ret
