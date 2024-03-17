global _start

section .data
    msg db 1024, 0

section .text

_getinput:
    ; Reads a line in from the user. Message is stored in ecx.
    mov     eax, 3  ; sys_read
    mov     ebx, 0  ; stdin
    mov     ecx, msg  ; buffer
    mov     edx, 1024 git c ; max size of buffer
    int     0x80

    ret

_start:
    ; call    _getinput

    ; Reads a line in from the user. Message is stored in ecx.
    mov     eax, 3  ; sys_read
    mov     ebx, 0  ; stdin
    mov     ecx, msg  ; buffer
    mov     edx, 1024  ; max size of buffer
    int     0x80

    ; print out the line of text that the user inputted
    mov     eax, 4  ; sys_write
    mov     ebx, 1  ; stdout
    mov     ecx, msg  ; buffer
    mov     edx, eax  ; the number of bytes the user inputted
    int     0x80

    ; exit with status code 0
    mov     eax, 1
    mov     ebx, 0

    int     0x80
    