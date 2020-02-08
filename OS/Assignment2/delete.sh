read -p "Enter name for deleting: " name
sed -i "/$name/d" AddressBook.txt
