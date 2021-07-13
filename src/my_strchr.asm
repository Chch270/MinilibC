BITS 64

section .text
    global my_strchr

%ifndef TU
    global strchr
%endif

strchr:
my_strchr:
    mov rax, rdi

.loop:
    cmp byte [rax], byte sil
    je .return
    cmp byte [rax], 0
    je .null
    inc rax
    jne .loop

.null:
    cmp byte sil, 0
    je .return
    mov rax, 0

.return:
    ret
