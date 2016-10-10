#!/bin/bash

CYAN="\E[1;36m\E[1m"
NC="\E[m"
BLUE="\E[34m\E[1m"
VIOLET="\E[35m\E[1m"
RED="\E[31m\E[1m"
YELLOW="\E[33m\E[1m"
GREEN="\E[37m\E[32m\E[1m"
TEXT="\E[1;37m\E[1m"

echo `clear`

estado=1

PRONTO="$(echo -e $YELLOW)$1:$(echo -e $BLUE)`pwd`-->$(echo -e $NC)"
echo -e "\t\t${VIOLET}---- Bienvenido ${YELLOW} $1 ---- ${NC}"
echo -e "\n\t${RED}Bienvenido a nuestra PrebeSHELL\n\tUtiliza el comando ayuda para comenzar${NC}\n"


until [ $estado -eq 0 ];
do
	read -p $PRONTO -e cmd
	case $cmd in
		arbol)
		./tree.sh
		;;
		ayuda)
		./ayuda.sh
		;;
		salir)
		estado=0
		echo `clear`
		;;
		infosis)
		./infosis.sh
		;;
		prebeplayer)
		./prebeplayer.sh $1 pwd
		;;
		*)
		echo -e "\aOpción inválida"
		;;
	esac
done

