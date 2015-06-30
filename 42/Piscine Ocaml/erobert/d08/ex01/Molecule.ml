(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Molecule.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 14:09:12 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/25 20:12:56 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual molecule (name: string) (formula: Atom.atom list) =
				object (this)
					val _name = name
					val _formula = formula

					method name = _name
					method formula =
						let rec add_list elem list result =
							match list with
							| [] ->
								 result @ [(1, elem)]
							| (count, data)::tail ->
								 if (data#equal elem) then
									 result @ ([(count + 1, elem)] @ tail)
								 else
									 add_list elem tail (result @ [(count, data)])
						in
						let rec store list result =
							match list with
							| [] ->
								 result
							| head::tail ->
								 store tail (add_list head result [])
						in
						let rec inner list result =
							match list with
							| [] ->
								 result
							| (count, data)::tail ->
								 if (count > 1) then
									 inner tail (result ^ (data#symbol) ^ (string_of_int count))
								 else
									 inner tail (result ^ (data#symbol))
						in
						inner (List.sort (fun (c1, d1) (c2, d2) ->
															match (d1#name, d2#name) with
															| ("C", _) -> 1
															| (_, "C") -> -1
															| ("H", _) -> 1
															| (_, "H") -> -1
															| (_, _) -> (compare d1#name d2#name)
														 )
														 (store formula []))
									""

					method to_string =
						"Molecule of " ^ _name ^ ", formula: " ^ this#formula
					method equal (that: molecule) =
						(this#name = that#name) && (this#formula = that#formula)
				end

class trinitrotoluene =
object
	inherit molecule "Trinitrotoluene" [new Atom.nitrogen;
																			new Atom.nitrogen;
																			new Atom.nitrogen;
																			new Atom.hydrogen;
																			new Atom.hydrogen;
																			new Atom.hydrogen;
																			new Atom.hydrogen;
																			new Atom.hydrogen;
																			new Atom.oxygen;
																			new Atom.oxygen;
																			new Atom.oxygen;
																			new Atom.oxygen;
																			new Atom.oxygen;
																			new Atom.oxygen;
																			new Atom.carbon;
																			new Atom.carbon;
																			new Atom.carbon;
																			new Atom.carbon;
																			new Atom.carbon;
																			new Atom.carbon;
																			new Atom.carbon]
end

class water =
object
	inherit molecule "Water" [new Atom.hydrogen;
														new Atom.hydrogen;
														new Atom.oxygen]
end

class carbon_dioxyde =
object
	inherit molecule "Carbon dioxyde" [new Atom.carbon;
																		 new Atom.oxygen;
																		 new Atom.oxygen]
end

class benzoylmethylecgonine =
object
	inherit molecule "Benzoylmethylecgonine" [new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.carbon;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.hydrogen;
																						new Atom.nitrogen;
																						new Atom.oxygen;
																						new Atom.oxygen;
																						new Atom.oxygen;
																						new Atom.oxygen]
end

class lysergic_acid_diethylamide =
object
	inherit molecule "Lysergic acid diethylamide" [new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.carbon;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.hydrogen;
																								 new Atom.nitrogen;
																								 new Atom.nitrogen;
																								 new Atom.nitrogen;
																								 new Atom.oxygen]
end
