bits 64

global ft_strcpy

section .text
    ft_strcpy:
        mov rax, 0
    .loop:
        mov cl, [rsi + rax]
        mov [rdi + rax], cl
        cmp BYTE[rsi + rax], 0
        je .loopend
        inc rax
        jmp .loop
    .loopend:
        mov rax, rdi
        ret