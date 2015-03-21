#ifndef I_OBJECT_H
# define I_OBJECT_H

class IObject
{
public:
	virtual 		~IObject(void){}
	virtual void	draw(void){};
	virtual bool	loop(int const){return (false);};
protected:
private:
};

#endif
