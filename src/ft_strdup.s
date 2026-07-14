bits 64

global ft_strdup
extern ft_strlen
extern malloc

section .text
    ft_strdup:
        mov r10, rdi
        sub rsp, 8
        call ft_strlen wrt ..plt
        add rsp, 8
        inc rax
        mov rdi, rax
        sub rsp, 8
        call malloc wrt ..plt
        add rsp, 8
        cmp rax, 0
        je .merror
        mov rcx, rax
        mov rax, 0
    .copy_loop:
        mov dl, [r10 + rax]
        mov [rcx + rax], dl
        inc rax
        cmp dl, 0       
        jne .copy_loop
        mov rax, rcx
        ret
    .merror:
        mov rax, 0
        ret