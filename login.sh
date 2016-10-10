#/bin/bash

echo `clear`

read -p "Usuario:  "  usr

su $usr -c './main.sh'
