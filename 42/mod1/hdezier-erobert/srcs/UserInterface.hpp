// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInterface.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/05 16:54:49 by erobert           #+#    #+#             //
//   Updated: 2015/02/08 15:36:21 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef USER_INTERFACE_HPP
# define USER_INTERFACE_HPP

# include <X11/X.h>
# include <X11/Xlib.h>
# include <GL/gl.h>
# include <GL/glx.h>
# include <GL/glu.h>
# include <iostream>
# include <list>
# include <string>
# include "IObject.hpp"

# define ESC 61
# define MINUS 86
# define PLUS 77

class UserInterface
{
private:
	Display					*_display;
	Window					_root;
	Window					_window;
	GLXContext				_gLXC;
	std::list<IObject *>	_obj;

	UserInterface(void);
	UserInterface(UserInterface const &uI);

	UserInterface		&operator=(UserInterface const &uI);
public:
	UserInterface(std::string const &name);
	~UserInterface(void);

	void				addObject(IObject *o);
	void				drawLoop(void);
};

#endif
