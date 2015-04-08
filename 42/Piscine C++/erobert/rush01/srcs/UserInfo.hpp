// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInfo.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 14:39:58 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 16:57:04 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef USER_INFO_HPP
# define USER_INFO_HPP

# include "IMonitorModule.hpp"

class UserInfo: public IMonitorModule
{
private:
	std::string							_title;
	int									_type;
	std::map<std::string, std::string>	_info;

	UserInfo(UserInfo const &uI);

	UserInfo							&operator=(UserInfo const &uI);

public:
	UserInfo(void);
	virtual ~UserInfo(void);

	virtual std::string const					&getTitle(void) const;
	virtual int									getType(void) const;
	virtual std::map<std::string, std::string>	getInfo(void);
};

#endif
