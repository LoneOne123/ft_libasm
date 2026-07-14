bits 64

global ft_write
extern __errno_location

section .text
    ft_write:
        mov rax, 1
        syscall
        cmp rax, 0
        jl .error
        ret
    .error:
        mov edi, eax
        neg edi
        sub rsp, 8
        call __errno_location wrt ..plt
        add rsp, 8
        mov [rax], edi
        mov rax, -1
        ret