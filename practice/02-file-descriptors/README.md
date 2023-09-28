# Работа с файлове

1. Файлови дескриптори (File descriptors)
    - Цяло положително число, идентифициращо отворен файл в операционната система.
    - Всеки UNIX процес има 3 стандартни file descriptor-a

    | Integer value |                     Name                    | <stdio.h> file stream[2] |
    |:-------------:|:-------------------------------------------:|:------------------------:|
    | 0             | Стандартен вход (Standard input)            | stdin                    |
    | 1             | Стандартен изход (Standard output)          | stdout                   |
    | 2             | Стандартен изход за грешки (Standard error) | stderr                   |

2. Функции за работа с файлови дескриптори
    - **int open(const char \*pathname, int flags)** - [man 2 open](https://man7.org/linux/man-pages/man2/open.2.html)
    
        - Отваря файл от подаден път (pathname) и връща file  descriptor  идентифициращ този файл
        - Вторият аргумент - flags  се използва за определяне на режима на работа с файла - примерно O_RDONLY флагът отваря файла в режим само за четене.
        - Всички флагове са описани в man page-овете.
        - TODO: добави ги и тук

    - **int close(int fd)** - [man 2 close](https://man7.org/linux/man-pages/man2/close.2.html)

        - Затваря отворен file  descriptor
        - При грешка връща -1, а иначе 0

    - **ssize_t read(int fd, void \*buf, size_t count)** - [man 2 read](https://man7.org/linux/man-pages/man2/read.2.html)

        - Чете N на брой байтове (count) от file descriptor и ги запаметява в даден буфер (buf)
        - При грешка връща -1, а при успех - броят на прочетените байтове.

    - **ssize_t  write(int  fd, void \*buf, size_t count)** - [man 2 write](https://man7.org/linux/man-pages/man2/write.2.html)

        - Чете N на брой байтове (count) от буфер и ги записва в даден file  descriptor. При грешка връща -1, а при успех - броят на прочетените байтове.

    - **off_t lseek(int fd, off_t offset, int whence)** - [man 2 lseek](https://man7.org/linux/man-pages/man2/lseek.2.html)
        - Задава позиция в file  descriptor; като аргументи получава file  descriptor-а (fd), с колко байта да се отмести позицията на четене в него (offset) и спрямо къде да се смята отместването (whence).
        - Whence  може да е един от следните 3 аргумента:
            - `SEEK_SET` - Спрямо началото на файла
            - `SEEK_CUR` - Спрямо сегашната позиция във файла
            - `SEEK_END` - Спрямо краят на файла

3. Задача 1 - "**cat**"

    \[[Условие](./tasks/01-cat.md)\] \[[Решение](./tasks/01-cat.c)\]

4. Задача 2 - "**cp**"

    \[[Условие](./tasks/02-cp.md)\] \[[Решение](./tasks/02-cp.c)\]

5. Задача 3 - "**head**"


    \[[Условие](./tasks/03-head.md)\] \[[Решение](./tasks/03-head.c)\]
