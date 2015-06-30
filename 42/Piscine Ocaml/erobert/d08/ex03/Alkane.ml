(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Alkane.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 15:45:44 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/25 16:15:45 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class alkane (n: int) =
object (this)
	inherit Molecule.molecule "" []
				 
	val _n = n

	method name = (string_of_int n) ^ "-ane"
	method formula =
		if (n = 1) then
			"C1H4"
		else
			"C" ^ (string_of_int n) ^ "H" ^ (string_of_int (n * 2 + 2))
end

class methane =
object
	inherit alkane 1

	method name = "Methane"
end

class ethane =
object
	inherit alkane 2

	method name = "Ethane"
end

class octane =
object
	inherit alkane 8

	method name = "Octane"
end
