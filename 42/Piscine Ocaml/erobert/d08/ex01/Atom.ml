(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Atom.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 13:32:06 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/25 15:09:16 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual atom (name: string) (symbol: string) (atomic_number: int) =
				object (this)
					val _name = name
					val _symbol = symbol
					val _atomic_number = atomic_number

					method name = _name
					method symbol = _symbol
					method atomic_number = _atomic_number

					method to_string =
						_name ^ ", symbol: " ^ _symbol ^
							", atomic number: " ^ (string_of_int _atomic_number)
					method equal (that: atom) =
						(_name = that#name) && (_symbol = that#symbol) &&
							(_atomic_number = that#atomic_number)
				end

class hydrogen =
object
	inherit atom "Hydrogen" "H" 0
end

class carbon =
object
	inherit atom "Carbon" "C" 6
end

class nitrogen =
object
	inherit atom "Nitrogen" "N" 7
end

class oxygen =
object
	inherit atom "Oxygen" "O" 8
end

class krypton =
object
	inherit atom "Krypton" "Kr" 36
end

class xenon =
object
	inherit atom "Xenon" "Xe" 54
end

class radon =
object
	inherit atom "Radon" "Rn" 86
end

class rutherfordium =
object
	inherit atom "Rutherfordium" "Rf" 104
end

class dubnium =
object
	inherit atom "Dubnium" "Db" 105
end
