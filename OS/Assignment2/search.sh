read -p "Enter name to search: " name
index="$(grep -n -w -i $name AddressBook.txt | sed -e 's/:.*//g')"
if [ $index ]
then
	echo "Record at line number $index"
else
	echo "not found"
fi
