bits 64

; int ft_atoi_base(char *str, char *base);
global ft_atoi_base
extern ft_strlen

section .text
    ft_atoi_base:
        push r12
        ; check str, base not null, base length > 1, str length > 0
        mov r10, rdi
        mov r11, rsi
        cmp r11, 0
        je .error
        cmp r10,0
        je .error
        mov rdi, r11
        call ft_strlen wrt ..plt
        cmp rax, 1
        jle .error
        mov rdi, r10
        call ft_strlen wrt ..plt
        cmp rax, 0
        je .error

        mov rax, 0
    .check_base_loop:
        ; whitespaces
        cmp byte [r11 + rax], 9
        je .error
        cmp byte [r11 + rax], 10
        je .error
        cmp byte [r11 + rax], 11
        je .error
        cmp byte [r11 + rax], 12
        je .error
        cmp byte [r11 + rax], 13
        je .error
        cmp byte [r11 + rax], 32
        je .error
        ; + and -
        cmp byte [r11 + rax], 43
        je .error
        cmp byte [r11 + rax], 45
        je .error
        ; duplicates
        mov r12, rax
        mov r8b, [r11 + rax]
    .check_duplicate_loop:
        inc r12
        cmp byte [r11 + r12], 0
        je .continue_check_base_loop
        cmp r8b, [r11 + r12]
        je .error
        jmp .check_duplicate_loop
    .continue_check_base_loop:
        inc rax
        cmp byte [r11 + rax], 0
        jne .check_base_loop
    
        mov rax, -1
    .whitespace_loop:
        inc rax
        cmp byte [r10 + rax], 9
        je .whitespace_loop
        cmp byte [r10 + rax], 10
        je .whitespace_loop
        cmp byte [r10 + rax], 11
        je .whitespace_loop
        cmp byte [r10 + rax], 12
        je .whitespace_loop
        cmp byte [r10 + rax], 13
        je .whitespace_loop
        cmp byte [r10 + rax], 32
        je .whitespace_loop

        cmp byte [r10 + rax], 45 ; -
        je .negative
        jmp .positive

    .negative:
        mov rcx, -1
        inc rax
        jmp .convert_start
    
    .positive:
        mov rcx, 1
        cmp byte [r10 + rax], 43 ; +
        jne .convert_start
        inc rax

    .convert_start:
        mov rdx, 0
        mov r9, rax
        mov rdi, r11
        call ft_strlen wrt ..plt
        mov rdi, rax
    .convert_loop:
        mov r8b, [r10 + r9]             
        ;r9 = index_str, r10 = str, r8b = str[r9], r11 = base, rcx = sign, rdx = result
        ;rdi = base_length
        mov rsi, -1  ; rsi = index_base
        cmp r8b, 0
        je .end_convert
    .find_in_base_loop:
        inc rsi
        cmp byte [r11 + rsi], 0
        je .end_convert
        cmp r8b, [r11 + rsi]
        jne .find_in_base_loop
        imul rdx, rdi
        add rdx, rsi
        inc r9
        jmp .convert_loop


    .end_convert:
        ; rdx = result, rcx = sign
        imul rdx, rcx
        mov rax, rdx
        pop r12
        ret

    .error:
        pop r12
        mov rax, 0
        ret