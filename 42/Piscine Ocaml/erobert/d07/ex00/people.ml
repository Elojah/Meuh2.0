(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   people.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 13:54:17 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/24 14:49:08 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class people (name:string) =
	object
		initializer
			print_endline "New born."
		val _name = name
		val _hp = 100

		method to_string =
			"This is " ^ _name ^ " with " ^ (string_of_int _hp) ^ "hp."
		method talk =
			print_endline ("I’m " ^ _name ^ "! Do you know the Doctor?")
		method die =
			print_endline "Aaaarghh!"
	end
