// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AudioManager.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 14:17:48 by erobert           #+#    #+#             //
//   Updated: 2015/06/01 14:25:42 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AUDIO_MANAGER_HPP
# define AUDIO_MANAGER_HPP

# include "SFML/Audio.hpp"

class AudioManager
{
public:
	enum eMusic
	{
		HYMNE_A_LA_KRO = 0,
		E_MUSIC
	};
	enum eSound
	{
		CHEWBACCA = 0,
		E_SOUND
	};

	AudioManager(void);
	~AudioManager(void);

	void			playMusic(eMusic music);
	void			nextMusic(void);
	void			stopMusic(void);
	void			playSound(eSound sound);
private:
	sf::Music		_music[E_MUSIC];
	sf::SoundBuffer	_buffer[E_SOUND];
	sf::Sound		_sound[E_SOUND];

	AudioManager(AudioManager const &rhs);

	AudioManager	&operator=(AudioManager const &rhs);
};

#endif
