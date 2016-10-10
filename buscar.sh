#!/bin/bash

read -p "Archivo a buscar:  " ARCH

read -p "Desde donde:  " DIR

find ${DIR} -name "${ARCH}*" 2> error

rm error