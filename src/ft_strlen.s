bits 64

global ft_strlen

section .text
ft_strlen:
    mov rax, 0
.loop:
    cmp BYTE[rdi + rax], 0
    je .endloop
    inc rax
    jmp .loop
.endloop:
    ret