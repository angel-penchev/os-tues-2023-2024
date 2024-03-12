# •	Да се състави командна процедура, която получава
# при стартиране в командния ред два параметъра – символен
# низ и число. Ако съществува директория с име съвпадащо с
# низа, процедурта извежда на стандартния изход имената на
# всички обикновени файлове от тази директория, чийто 
# размер е по-голям от подаденото число. В противен случай/не
# съществува такава директория/ - на стандартния изход се извежда
# подходящо съобщение.

# $1 - dir name $2 - size
if [ $# -ne 2 ]
then
    echo error parameters
    exit 1
fi

FILE_TYPE=$(stat --format "%F" $1 2> /dev/null)
if [ "$FILE_TYPE" = "directory" ]
then
    FILE_NAMES=$(ls -A $1)
    for FILE_NAME in $FILE_NAMES
    do
        FILE_SIZE=$(stat --format "%s" $1/$FILE_NAME)
        if [ "$FILE_SIZE" -gt $2 ]
        then
            echo $FILE_NAME
        fi
    done
else
    echo "error"
fi
