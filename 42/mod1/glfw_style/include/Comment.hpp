// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Comment.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/30 15:48:21 by hdezier           #+#    #+#             //
//   Updated: 2015/04/30 15:50:49 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COMMENT_H
# define COMMENT_H

# include "IToken.hpp"

class Comment : public IToken
{
public:
	Comment(void);
	~Comment(void);

	int				detect(const char &c);
	int				getType(void) const;
private:
	Comment(Comment const &rhs);

	Comment			operator(Comment const &rhs);
};

#endif
