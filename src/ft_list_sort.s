bits 64

global ft_list_sort
extern ft_list_size

section .text
    ; void ft_list_sort(t_list **begin_list, int (*cmp)());
    ft_list_sort:
        push r12        ; save r12
        push r13        ; save r13
        push r14        ; save r14
        push r15        ; save r15
        mov r12, rdi    ; **begin_list
        mov r13, rsi    ; cmp function


        mov rdi, [r12]
        sub rsp, 8
        call ft_list_size
        add rsp, 8
        mov r14, rax    ; list_size

    .first_for_loop:
        cmp r14, 1
        jle .end
        mov rdi, [r12]  ; head_node
        mov r15, 0
    .second_for_loop:
        mov rcx, r14    ; n
        dec rcx         ; n-1
        cmp r15, rcx
        jge .continue_first_for_loop

        push rdi
        mov rsi, [rdi + 8]
        mov rdi, [rdi]
        mov rsi, [rsi]
        call r13
        pop rdi
        cmp eax, 0
        jg .swap
    .continue_second_loop:
        mov rdi, [rdi + 8]
        inc r15
        jmp .second_for_loop
   
    .continue_first_for_loop:
        dec r14
        jmp .first_for_loop 

    .swap:
        push rdi
        mov rcx, [rdi + 8]
        mov rax, [rdi]          ; curr data
        mov rdx, [rcx]          ; next data

        mov [rdi], rdx
        mov [rcx], rax
        pop rdi
        jmp .continue_second_loop

    .end:
        pop r15
        pop r14
        pop r13
        pop r12
        ret