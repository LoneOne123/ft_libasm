bits 64

%define T_LIST_DATA_OFFSET 0
%define T_LIST_NEXT_OFFSET 8

global ft_list_push_front
extern malloc

section .text
    ; void ft_list_push_front(t_list **begin_list, void *data);
    ft_list_push_front:
        ; backup registers !!!Reihenfolge!!!
        push r12
        push r13
        mov r12, rdi
        mov r13, rsi

        ; null check list
        cmp r12, 0
        je .end
    
        ; allocate new list element
        mov rdi, 16
        sub rsp, 8
        call malloc wrt ..plt
        add rsp, 8
        cmp rax, 0
        je .end

        ; set data and set to front of list
        mov [rax + T_LIST_DATA_OFFSET], r13
        mov rcx, [r12]
        mov [rax + T_LIST_NEXT_OFFSET], rcx
        mov [r12], rax


    .end:
        ; restore registers
        pop r13
        pop r12
        ret
