(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Reaction.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 16:05:33 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/25 16:09:56 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual reaction (s: (Molecule.molecule * int) list)
											 (e: (Molecule.molecule * int) list) =
				object
					method virtual get_start: (Molecule.molecule * int) list
					method virtual get_result: (Molecule.molecule * int) list
					method virtual balance: reaction
					method virtual is_balanced: bool
				end
