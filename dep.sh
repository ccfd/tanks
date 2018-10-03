#!/bin/bash

set -e

cat makefile | sed -n '/## DEP/q;p' >mk.tmp

echo "## DEP" >>mk.tmp
for i in $(find -name "*.cpp" -or -name "*.h")
do
	P=$(dirname $i)
	dep=$(cat $i | sed -n -E 's|.*"(.*.h)"|'$P'/\1|p' | paste -s -d " ")
	if ! test -z "$dep"
	then
		echo "$i : $dep" >>mk.tmp
		echo -ne "\t@test -f \$@ && touch \$@\n" >>mk.tmp
		echo -ne "\t@echo \$@ depends on \$^\n" >>mk.tmp
	else
		echo "# $i" >>mk.tmp
	fi
done

mv mk.tmp makefile
