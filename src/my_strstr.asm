BITS 64

section .text
    global my_strstr

%ifndef TU
    global strstr
%endif

strstr:
my_strstr:
    xor rcx, rcx
    jmp .loop

.loop:
    cmp byte [rdi], 0
    je .return_null
    mov rax, rdi
    mov rbx, rsi

.compare:
    cmp byte [rbx], 0
    je .return
    cmp byte [rax], 0
    je .inc_rdi
    mov dl, byte [rbx]
    cmp byte [rax], dl
    jne .inc_rdi
    inc rax
    inc rbx
    jmp .compare

.inc_rdi:
    inc rdi
    jmp .loop

.return_null:
    cmp byte [rsi], 0
    je .return
    mov rax, 0
    ret

.return:
    mov rax, rdi
    ret
