// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 10:57:30 by erobert           #+#    #+#             //
//   Updated: 2015/01/05 15:06:06 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class	Contact
{
private:
	std::string	_fname;
	std::string	_lname;
	std::string	_nname;
	std::string	_login;
	std::string	_paddr;
	std::string	_eaddr;
	std::string	_pnumb;
	std::string	_bdate;
	std::string	_favoriteMeal;
	std::string	_underwearsColors;
	std::string	_darkestSecret;

public:
	Contact(void);
	~Contact(void);

	void		setFname(std::string& str);
	std::string	getFname(void);

	void		setLname(std::string&str);
	std::string	getLname(void);

	void		setNname(std::string& str);
	std::string	getNname(void);

	void		setLogin(std::string& str);
	std::string	getLogin(void);

	void		setPaddr(std::string& str);
	std::string	getPaddr(void);

	void		setEaddr(std::string& str);
	std::string	getEaddr(void);

	void		setPnumb(std::string& str);
	std::string	getPnumb(void);

	void		setBdate(std::string& str);
	std::string	getBdate(void);

	void		setFavoriteMeal(std::string& str);
	std::string	getFavoriteMeal(void);

	void		setUnderwearsColors(std::string& str);
	std::string	getUnderwearsColors(void);

	void		setDarkestSecret(std::string& str);
	std::string	getDarkestSecret(void);
};

#endif
