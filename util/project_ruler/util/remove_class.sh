if test -z "\$1"
then
echo \"Usage: sh util/remove_class.sh Class_Name\"
else
rm src/$1.cpp
rm include/$1.h
rm doc/$1
sed -i "/$1/d" Makefile

fi

