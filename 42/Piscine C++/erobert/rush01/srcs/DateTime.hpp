// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTime.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 16:37:54 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 17:06:16 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DATE_TIME_HPP
# define DATE_TIME_HPP

# include <sstream>
# include "IMonitorModule.hpp"

class DateTime: public IMonitorModule
{
private:
	std::string							_title;
	int									_type;
	std::map<std::string, std::string>	_info;

	DateTime(DateTime const &oSI);
	DateTime							&operator=(DateTime const &oSI);

public:
	DateTime(void);
	virtual ~DateTime(void);

	virtual std::string const					&getTitle(void) const;
	virtual int									getType(void) const;
	virtual std::map<std::string, std::string>	getInfo(void);
};

#endif
