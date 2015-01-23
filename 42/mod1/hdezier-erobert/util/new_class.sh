if test -z "$1"
then
echo "Usage: sh util/new_class.sh Class_Name"
else
echo '#include "'$1'.h"

using namespace std;

'$1'::'$1'()
{
	;
}

'$1'::~'$1'()
{
	;
}
' > src/$1.cpp;

echo '#ifndef '$(echo "$1" | tr "[:lower:]" "[:upper:]")'_H
# define '$(echo "$1" | tr "[:lower:]" "[:upper:]")'_H

class '$1'
{
public:
	'$1'(void);
	~'$1'(void);
protected:
private:
};

#endif
' > include/$1.h;

echo ''$1' documentation

' > doc/$1
sed -i '15i\	'$1'\\' Makefile
fi

