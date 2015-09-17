if [ $# != 2 ]
then
	echo "Specify two arguments: 'program executable name' and 'no of times it is to be executed' as Command Line Arguments to this script"
else
	j=0
	size=$2
	echo "The file '$1' will be executed $2 times...Are you sure you want to proceed? (y/n)"
	read choice
	if [ $choice == 'y' ]
	then
		for (( i=1; i<=size; i++ ))
		do
			echo '#========================================='
			echo "# execution number $i"
			echo '#========================================='
			./$1
		done
	fi
fi	