#!/bin/sh

ENVIRONMENT="DEV" # or PRODUCTION
# echo "AAAAA $ENVIRONMENT \n\t\n\t\t\t\t AAAAA"
test $ENVIRONMENT = "DEV"

echo $?

if [ $ENVIRONMENT = "DEV" ]
then
    # if dev
    echo "IF"
else
    # if prod
    echo "ELSE"
fi
