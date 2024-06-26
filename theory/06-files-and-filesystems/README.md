# Тема 6. Файлове и файлови системи
Съдържание:

1. [TL;DR](#1-tldr)
2. [Файл](#2-файл)
3. [Метадата на файл](#3-метадата-на-файл)
4. [Файлова система](#4-файлова-система)
5. [Популярни файлови системи](#5-популярни-файлови-системи)
6. [Често ползвани директории в Unix](#6-често-ползвани-директории-в-unix)
7. [Soft and Hard links](#7-soft-and-hard-links)
---

## 1. TL;DR

TL;DR: Изгледайте това [видео](https://www.youtube.com/watch?v=KN8YgJnShPM), съдържа 90% от нещата описани тук.

## 2. Файл

Файлът е основна единица за съхранение на данни в компютърните системи. Той може да съдържа текст, изображения, видео, софтуер или всякакъв вид информация. Файловете имат име и разширение, което обикновено указва типа на файла (например `.txt` за текстови файлове, `.jpg` за изображения и т.н.).

Файл е поредица от битове записана на блоково устройство (напр. HDD, SSD, т.н.).

## 3. Метадата на файл

Метадатата на файл представлява набор от данни, които описват и дават информация за самия файл. Метадатата включва:

- **Име на файла:** Уникално в дадена директория.
- **Разширение на файла:** Указва типа на файла.
- **Размер на файла:** Количеството съхранени данни, обикновено в байтове.
- **Създаване и последно модифициране:** Дати и часове на създаване и последно изменение на файла.
- **Права на достъп:** Определят кой може да чете, пише или изпълнява файла.
- **Собственик и група:** Информация за потребителя и групата, които притежават файла.
- **Идентификатори на inode:** Уникален идентификатор в контекста на файловата система.

## 4. Файлова система

Файловата система е метод и структура, чрез които операционната система организира и управлява файловете на дадено устройство за съхранение (диск, SSD, USB устройство и т.н.). Файловата система предоставя начин за създаване, четене, запис и изтриване на файлове. Основните функции на файловата система включват:

- **Управление на пространството:** Как се съхраняват и организират файловете на физическия носител.
- **Индексиране и търсене:** Бързо намиране на файлове и директории.
- **Управление на достъпа:** Контролиране на правата за достъп до файловете.

## 5. Популярни файлови системи

### Windows файлови системи:
- **FAT32:** По-стар формат, поддържа файлове до 4GB и обеми до 2TB.
- **NTFS:** Модерен формат с поддръжка на големи файлове и обеми, криптиране, права на достъп и други функции.

### Unix/Linux файлови системи:
- **EXT4:** Широко използвана в Linux дистрибуциите, предлага добра производителност и надеждност.
- **Btrfs:** Модерна файловата система с поддръжка на snapshot-и, checksums и други усъвършенствани функции.

## 6. Често ползвани директории в Unix

- **/**: Кореновата директория на файловата система.
- **/bin**: Съдържа изпълними файлове (бинарни файлове) за основните команди.
- **/etc**: Конфигурационни файлове за системата.
- **/home**: Домашни директории на потребителите.
- **/var**: Променливи данни като лог файлове, имейли и времеви файлове.
- **/tmp**: Временни файлове, които могат да бъдат изтривани автоматично.
- **/lib**: Споделени библиотеки и модули за различни програми и системни услуги.

## 7. Soft and Hard links

### Soft Links (Symbolic Links):
- **Символни връзки:** Препратки към друг файл или директория.
- **Създаване:** Чрез командата `ln -s`.
- **Характеристики:** Могат да сочат към файлове или директории, дори ако се намират на различни файлови системи. Ако оригиналният файл бъде изтрит, soft link остава, но става невалиден.

### Hard Links:
- **Твърди връзки:** Други имена за същия файл на същото място в дисковата система.
- **Създаване:** Чрез командата `ln`.
- **Характеристики:** Всички твърди връзки към файл са равностойни. Ако оригиналният файл бъде изтрит, данните остават достъпни през другите твърди връзки. Не могат да сочат към директории или да се създават между различни файлови системи.

## Бонус
Potential Rick Roll -> https://www.youtube.com/shorts/0xnuhmqRvVQ.
