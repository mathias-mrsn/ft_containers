#!/bin/bash

CC="clang++"
CPPFLAGS="-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3"
INCS="-I ../containers/ -I includes -I ../containers/utils"

tmp_file=".tmp_file"

EOC="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
DBLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
DGREY="\e[1;90m"

print_result()
{
	printf $YELLOW"%-30s"$EOC "$1"
	if [ $2 -eq "1" ]
	then
		printf $GREEN"%-15s" "Success"
	else
		printf $RED"%-15s" "Error check diff output"
	fi

	printf $EOC"\t\ttime : "

	if [ $3 -eq "1" ]
	then
		printf $GREEN"OK"
	else
		printf $RED"KO"
	fi

	printf "\n"$EOF

}

compare ()
{
	name=$(basename ${1})
	mycmd="$CC $CPPFLAGS $INCS $1 -DNAMESPACE=ft -o mytest"
	${mycmd}
	start=`date +%s%N`
	./mytest > ft_output/ft_${name}.log
	end=`date +%s%N`
	runtime1=$( echo "($end - $start) / 20" | bc -l )
	
	reelcmd="$CC $CPPFLAGS $INCS $1 -DNAMESPACE=std -o reeltest "
	${reelcmd}
	start=`date +%s%N`
	./reeltest > std_output/std_${name}.log
	end=`date +%s%N`
	runtime2=$( echo "($end - $start)" | bc -l )

	diff ft_output/ft_${name}.log std_output/std_${name}.log > diff/$tmp_file.diff

	if [ $? -eq 0 ]; then
		output="1"
	else
		output="0"
	fi

	if (( $(echo "$runtime1 <= $runtime2" | bc -l) ))
	then
		time_result="1"
	else
		time_result="0"
	fi

	print_result $name $output $time_result

	rm reeltest $tmp_file mytest 2> /dev/null > /dev/null
}

launch_test ()
{
	test_files=$(find ./vector ./stack ./map ./set -type f -name '*.cpp' | sort)

	mkdir std_output ft_output diff 2> /dev/null
	rm -rf std_output/* ft_output/* diff/*

	main_test="42"

	if [ $# -eq 1 ]
	then
		if [ "$1" = "$main_test" ]
		then
			compare "./42_main/42.cpp"
		else
			compare "$1"
		fi
	else
		for file in ${test_files[@]}; do
			compare "${file}"
		done
	fi
}

launch_test $@
