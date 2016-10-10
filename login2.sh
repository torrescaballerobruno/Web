#!/bin/bash

echo `clear`

read -p "USUARIO: " USERNAME

id -u $USERNAME > /dev/null
if [ $? -ne 0 ]
then
        echo "El usuario: $USERNAME no existe en el sistema"
        exit 1
else
        #echo 
        read -p "\E[34m\E[1mCONTRASEÑA:" -s PASSWD
        export PASSWD
        ORIGPASS=`sudo -S grep -w "$USERNAME" /etc/shadow | cut -d: -f2`
        export ALGO=`echo $ORIGPASS | cut -d'$' -f2`
        export SALT=`echo $ORIGPASS | cut -d'$' -f3`
        GENPASS=$(perl -le 'print crypt("$ENV{PASSWD}","\$$ENV{ALGO}\$$ENV{SALT}\$")')
        if [ "$GENPASS" == "$ORIGPASS" ]
        then    
                ./main.sh $USERNAME
                exit 0
        else
                echo "Contraseña incorrecta"
                exit 1
        fi
fi
