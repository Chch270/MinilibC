BITS 64

extern strpbrk
extern strlen

section .text
    global my_strcspn

%ifndef TU
    global strcspn
%endif

strcspn:
my_strcspn:
    xor r9, r9
    xor r10, r10
    xor rcx, rcx
    mov r9, rdi
    call strpbrk wrt ..plt
    cmp rax, 0
    je .length
    mov r10b, byte [rax]

.loop:
    cmp byte [r9], byte r10b
    je .return
    inc r9
    inc rcx
    jmp .loop

.length:
    mov rdi, r9
    call strlen wrt ..plt
    ret

.return:
    mov rax, rcx
    ret
