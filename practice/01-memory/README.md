# Въведение в Linux. Указатели, динамична памет и разпределение на паметта (много съкратена версия 🥲)

0. Настройка на работна среда за часа (ако не сте на Linux)

    0.1. Чрез SSH от VSCode
    - Отворете Extensions панела във VSCode.
    - Инсталирайте [Remote - SSH](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh) разширението за VSCode.
    - Изберете `Remote Explorer` в панела отляво.
    - Изберете `Remotes (Tunnels/SSH)`.
    - Добавете нова SSH среда, като за команда може да използвате
        ```
        ssh tues-b<номер в класа>@os.penchev.dev
        ```
    - Цъкнете `Refresh` на Remotes панела.
    - На `os.penchev.dev` изберете `Connect in Current Window...`.
    - Като тип на платформата изберете `Linux`.
    - Паролата е `ospracgoesbrrr`.



    0.2. WSL
        - `code` в терминала.

    1. Пререквизити

    1.1. Инсталиране на `gcc` компилатор

    На Debian базирани дистрибуции (Ubutnu, Mint, etc.)
    ```
    sudo apt install gcc
    ```

    1.2. Основни команди

        - `echo [string]`
        - `ls`
            - `ls -l`
            - `ls -a`
            - `ls -la` 
        - `cd [dirctory name]`
        - `cat [text file name]`
        - `cp [source] [destination]`
        - `mv [source] [destination]`
        - `rm [file]`
        - `mkdir [directory name]`
        - `touch [file name]`
        - `sudo [command]`
        - `apt [program]`
        - `man`
        - `nano`, `vim`, `nvim`
        - `gcc`

    
    1.3. Makefiles
    
    ```
    default:
	    gcc -Wall -pedantic -Wextra -std=c11 example.c -o example
    
    clear:
        rm example
    ```

2. Задача за преговор

array.c
\[[Условие](./tasks/01-array.md)\] \[[Решение](./tasks/01-array.c)\]

3. Как се разпределя паметта на една програма?
https://www.geeksforgeeks.org/memory-layout-of-c-program/
