(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   doctor.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 14:45:42 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/24 15:13:38 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class doctor (name:string) (age:int) (sidekick:People.people) =
object (this)
	initializer
		print_endline "The good Doctor is back!"

	val _name = name
	val _age = age
	val _sidekick = sidekick
	val _hp = 100

	method to_string =
		"This is Dr " ^ _name ^ ", " ^ (string_of_int _age) ^ " year old, with "
		^ (string_of_int _hp) ^ "hp and his sidekick " ^ (_sidekick#to_string)
	method talk =
		print_endline "Hi! I’m the Doctor!"
	method travel_in_time start arrival =
		print_endline "
          _
         /-\\
    _____|#|_____
   |_____________|
  |_______________|
|||_POLICE_##_BOX_|||
 | |¯|¯|¯|||¯|¯|¯| |
 | |-|-|-|||-|-|-| |
 | |_|_|_|||_|_|_| |
 | ||~~~| | |¯¯¯|| |
 | ||~~~|!|!| O || |
 | ||~~~| |.|___|| |
 | ||¯¯¯| | |¯¯¯|| |
 | ||   | | |   || |
 | ||___| | |___|| |
 | ||¯¯¯| | |¯¯¯|| |
 | ||   | | |   || |
 | ||___| | |___|| |
|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯";
		{<_name = _name;
			_age = _age + (arrival - start);
			_sidekick = _sidekick;
			_hp = _hp;
			>};
	method use_sonic_screwdriver =
		print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"

	method private regenerate =
		{<_name = _name;
			_age = _age;
			_sidekick = _sidekick;
			_hp = 100;
			>}
end
