section .data
    hello db "Hello, Holberton", 0
    format db "%s", 10, 0

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp
sub rsp, 8 ; Reserve space for the 64-bit alignment

    mov rdi, format
    mov rsi, hello
    xor eax, eax
    call printf

    mov eax, 0
    leave
    ret

