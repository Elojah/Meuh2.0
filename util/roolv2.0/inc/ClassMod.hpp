/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMod.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 19:59:29 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 20:36:36 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_MOD_HPP
# define CLASS_MOD_HPP

# include "Menu.hpp"
# include "IModule.hpp"

class ClassMod : public Menu, public IModule
{
public:
	ClassMod(int h, int w, int x, int y);
	virtual ~ClassMod(void);
	virtual void		construct(const std::string &path, const std::string &name);
private:
	std::string		_path;
	std::string		_name;

	virtual void			sortItems(const int &length);
	virtual void			createItems(void);
};

#endif
