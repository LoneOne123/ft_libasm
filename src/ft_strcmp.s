bits 64

global ft_strcmp

section .text
    ft_strcmp:
        mov rax, 0
    .loop:
        mov dl, [rdi + rax]
        mov cl, [rsi + rax]
        cmp dl, cl
        jne .loopend
        cmp dl, 0
        je .loopend
        cmp cl, 0
        je .loopend
        inc rax
        jmp .loop
    .loopend:
        movzx eax, dl
        movzx ecx, cl
        sub eax, ecx
        ret