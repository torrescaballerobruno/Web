#!/bin/bash
clear

RESPUESTA=$(dpkg --get-selections | grep -w mpg123 | grep -w install)
    if [ "$RESPUESTA" = "" ]; then
    	echo -e "\n\n El mpg123 no esta instalado. Deseas instalarlo ? \n\n"
    	select eleccion in "Si" "No"
    	do
    	case $eleccion in 
	      	Si)
			`sudo apt-get install mpg123`
			echo -e "\n El mpg123 esta instalado."
			;;
			No)
			echo -e "¡Hasta luego!"
			;;
		esac
		done
	else

	cd /home/$1/Música/
	op1="Reproduce la carpeta actual";
	op2="Entrar a una carpeta";
	op3="Subir una carpeta";
	op4="Lista archivos y subcarpetas de la carpeta actual";
	op5="Opciones del reproductor";
	op6="Salir";
	 
	salida=1
	 
	while [ $salida -eq 1 ]; do
		echo "Esas en la carpeta: " `pwd`
	    select MENU in  "$op1" "$op2" "$op3" "$op4" "$op5" "$op6"
	    do
	        case $MENU in 
	            "$op1")
		            mpg123 -C *

	                break
	                ;;
	            "$op2")
					read -p "Carpeta: " carp
	                cd ${carp}
	                echo `clear`

	                break
	                ;;
	            "$op3")
	                cd ..
					break
					echo `clear`

	                ;;
	            "$op4")
					echo `clear`
	                $2/scripts/tree.sh
	                break
	                ;;
	            "$op5")
					echo `clear`
	                OLDIFS=$IFS
					IFS=$'\n'
					for linea in $(cat $2/opciones.txt) ; do
					  echo ${linea}
					done
					IFS=$OLDIFS
					echo "\n\n"
	                break
	                ;;
	            "$op6")
					#detener = $(ps -aux  | grep mpg123 | cut -c 10-14)
					#echo "$(detener)"
					#kill -9 $(detener)
	                salida=0;
	                #read;
	                echo `clear`
	                break
	                ;;
	        esac
	    done 
	done
fi