BITS 64

extern strlen

section .text
    global my_rindex

%ifndef TU
    global rindex
%endif

rindex:
my_rindex:
    xor rcx, rcx

.end_string:
    cmp byte [rdi], 0
    je .loop
    inc rdi
    inc rcx
    jmp .end_string

.loop:
    cmp rcx, 0
    je .return_zero
    cmp byte [rdi], sil
    je .then_zero
    dec rdi
    dec rcx
    jne .loop

.return_zero:
    cmp byte [rdi], sil
    jnz .else_zero

.then_zero:
    mov rax, rdi
    jmp .return

.else_zero:
    mov rax, 0
    jmp .return

.return:
    ret
