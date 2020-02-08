#!/bin/bash
chmod +x add.sh
chmod +x display.sh
chmod +x search.sh
chmod +x delete.sh

echo "#####menu#####"
echo "1. Add Record"
echo "2. Delete Record"
echo "3. Search Record"
echo "4. Display Address Book"
echo "5. Exit"
read -p "1/2/3/4/5 :" value
while [ $value -ne 5 ]
do
	if [ $value -eq 1 ]
	then
		./add.sh
	elif [ $value -eq 2 ]
	then
		./delete.sh
	elif [ $value -eq 3 ]
	then
		./search.sh
	elif [ $value -eq 4 ]
	then
		./display.sh
	else
		echo "Invalid Choice"
	fi
	read -p "1/2/3/4/5 :" value
done
