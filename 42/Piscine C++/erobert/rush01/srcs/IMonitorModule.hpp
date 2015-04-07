// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 14:21:52 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 16:57:47 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_MONITOR_MODULE_HPP
# define I_MONITOR_MODULE_HPP

# include <string>
# include <map>

class IMonitorModule
{
protected:
	typedef enum	e_type
	{
		STRING,
		PERCENT,
		VALUE
	}				t_type;

public:
	virtual ~IMonitorModule(void) {}

	virtual std::string const					&getTitle(void) const = 0;
	virtual int									getType(void) const =  0;
	virtual std::map<std::string, std::string>	getInfo(void) = 0;
};

#endif
