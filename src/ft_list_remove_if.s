bits 64

global ft_list_remove_if
extern free

section .text
    ;void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
    ft_list_remove_if:
        push r12
        push r13
        push r14
        push r15

        mov r12, rdi    ; begin_list
        mov r13, rsi    ; data_ref
        mov r14, rdx    ; cmp
        mov r15, rcx    ; free_fct

        push rbx
        mov rbx, [r12]  ; current_element
        mov rax, 0      ; parent->next (0 if no parent)

    .main_loop:
        ; end if NULL
        cmp rbx, 0
        je .end

        ; call cmp()
        mov rdi, [rbx]
        mov rsi, r13
        push rax
        sub rsp, 8
        call r14
        add rsp, 8
        cmp eax, 0
        je .remove_element
        pop rax
        mov rax, rbx
        mov rbx, [rbx + 8]
        jmp .main_loop

    .remove_element:
        pop rax
        mov rcx, [rbx + 8]
        cmp rax, 0
        je .remove_start_element

        mov rdx, [rbx + 8]  ; cur->next
        mov [rax + 8], rdx  ; parent->ext = cur->next
        
        mov rdi, [rbx]      ; cur->data
        push rax
        push rdx
        call r15            ; free_fct(cur->data)
        pop rdx
        pop rax

        push rax
        push rdx
        mov rdi, rbx
        call free wrt ..plt
        pop rdx
        pop rax

        mov rbx, rdx
        jmp .main_loop
        

    .remove_start_element:
        mov [r12], rcx

        mov rdi, [rbx]      ; cur->data
        push rcx
        sub rsp, 8
        call r15            ; free_fct(cur->data)
        add rsp, 8
        pop rcx

        push rcx
        mov rdi, rbx
        sub rsp, 8
        call free wrt ..plt
        add rsp, 8
        pop rcx

        mov rbx, rcx
        jmp .main_loop


    .end:
        pop rbx
        pop r15
        pop r14
        pop r13
        pop r12
        ret