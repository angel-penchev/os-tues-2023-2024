# head

Да се реализира програма, която приема като аргумент име на файл и изкарва първите му 10 реда. Ако файлът е по-къс от това, нека се извежда изцяло.

```
$ ./head example.txt
According to all known laws of aviation,
there is no way a bee should be able to fly.
Its wings are too small to get its fat little body off the ground.
The bee, of course, flies anyway because bees don't care what humans think is impossible.
Yellow, black. Yellow, black. (x2)
Ooh, black and yellow!
Let's shake it up a little.
Barry! Breakfast is ready!
Ooming!
Hang on a second.
```

При подаване на аргумента `-n <число>`, нека програмата извежда само толкова наброй редове, колкото е подаденото число.

```
$ ./head -n 2 example.txt
According to all known laws of aviation,
there is no way a bee should be able to fly.
```
