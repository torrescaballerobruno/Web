#!/bin/bash
clear
RESPUESTA=$(dpkg --get-selections | grep -w mpg123 | grep -w install)
  if [ "$RESPUESTA" = "" ]; then
      echo -e "\n\n El mpg123 no esta instalado. Deseas instalarlo ? Si o No \n\n"
      read eleccion
      case $eleccion in 
      	Si)
		`sudo apt-get install mpg123`
		echo -e "\n El mpg123 esta instalado."
		;;
		si)
		`sudo apt-get install mpg123`
		echo -e "\n El mpg123 esta instalado."
		;;
		s)
		`sudo apt-get install mpg123`
		echo -e "\n El mpg123 esta instalado."
		;;
		S)
		sudo apt-get install mpg123
		echo -e "\n El mpg123 esta instalado."
		;;
		No)
		echo -e "¡Hasta luego!"
		;;
		no)
		echo -e "¡Hasta luego!"
		;;
		N)
		echo -e "¡Hasta luego!"
		;;
		n)
		echo -e "¡Hasta luego!"
		;;
		*)
		echo -e "¡Hasta luego!"
		;;
      	esac
      
  else
      #echo "El mpg123 YA ESTA INSTALADO"
 	  cat banpreb.txt
	  echo -e "Carpeta actual: `pwd`"
	  echo -e "1)Reproducir el contenido de la carpeta actual"
	  echo -e "2)Cambiar de carpeta"
	  echo -e "3)Subir una carpeta"
	  echo -e "4)Listar archivos y subcarpetas de la carpeta actual"
	  echo -e "5)Listar opciones del reproductor"
	  echo -e "6)Salir"
	  echo -e "Seleccione la opción que desea realizar: \n "
	  read OPC
	  pwd =$toca
	  case $OPC in
		  1)
	 	  mpg123 -d $toca* 
		  ;;
		  2) 
		  echo -e "Introduce la ruta a la que deseas ir: "  
		  read ruta
		  echo $ruta
		  `cd` $ruta
		  echo $?
		  ;;
		  3) 
		  $cd ..$
		  ;;
		  4) 
		  ls [1-100]* 
		  ;;
		  5)
		  man mpg123  
		  ;;
		  6)
		  clear 
		  echo "***\n\n\nGracias por utilizar el PrebePlayer. ¡Hasta luego!\n\n\n***"
		  ;;
		  *) echo -e "Opcion inválida. Intente de nuevo"
		  ;;
	  esac
  fi