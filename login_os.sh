	cdo=$PWD
	echo -e -n "\033[32m Name of the user: \033[00m" #Obtener datos para logeo
	read usser  
	echo -e -n "\033[32m Password of the user: \033[00m"
	read -s pswd

	cadena=`echo "$pswd" | sudo -S grep -r "$usser" /etc/shadow`

	if [ ${cadena} > 5 ];then #Si el usuario existe

		a=`grep mkpasswd /usr/bin/mkpasswd`
		if [ $a != "Binary file /usr/bin/mkpasswd matches" ];then
			echo "$pswd" | sudo -S  apt-get install whois #Instala el modulo o lo reinstala en dado caso
		fi
	

		IFS='$' read -r -a array <<< "$cadena"  #Detemrinamos el tipo de cifrado y el salt.
		if [ ${array[1]} == 1 ];then
 		   tencript="md5"
		elif [ ${array[1]} == 2 ];then
		    tencript="Blowfish"
		elif [ ${array[1]} == "2a" ];then
		    tencript="eksblowfish"         #Determinamos que tipo de cifrado usar.
		elif [ ${array[1]} == 5 ];then
 		   tencript="sha-256"
		elif [ ${array[1]} == 6 ];then
		    tencript="sha-512"
		fi
		con=`mkpasswd --method=$tencript --salt=${array[2]} $pswd`
		c=":"
		final=$usser$c$con #Contraseña.	

		if [[ $cadena == *$final* ]];then  #Validación de la contraseña con a firma

		promt="#"
		printf "\033c" #CLS
		echo -e "\033[36m"
		echo "--------Bienvenido a la PreBeshell--------"
		echo "Presione cualquier tecla cuando este listo." #Menú de entrada
		echo -e "\033[00m"   #Se espara 5 segundos o hasta que se de un click para continuar
		read -n1 -t5 

		fi
		#printf "\033c"