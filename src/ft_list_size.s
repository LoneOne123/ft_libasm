bits 64

%define T_LIST_DATA_OFFSET 0
%define T_LIST_NEXT_OFFSET 8

global ft_list_size

section .text
    ; int ft_list_size(t_list *begin_list);
    ft_list_size:
        mov rax, 0
        cmp rdi, 0              ;check if list is null
        je .end
        mov rax, 1              ;start counting from 1, because we already know that the list is not null
    .loop:
        cmp qword [rdi + T_LIST_NEXT_OFFSET], 0
        je .end
        inc rax
        mov rdi, qword [rdi + T_LIST_NEXT_OFFSET]
        jmp .loop
    .end:
        ret