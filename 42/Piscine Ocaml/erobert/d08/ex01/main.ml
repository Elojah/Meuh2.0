(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 13:43:53 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/25 15:23:22 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	let h = new Atom.hydrogen
	and c = new Atom.carbon
	and o = new Atom.oxygen
	and k = new Atom.krypton
	and x = new Atom.xenon
	and r = new Atom.radon
	and rf = new Atom.rutherfordium
	and db = new Atom.dubnium
	in
	print_endline h#to_string;
	print_endline c#to_string;
	print_endline o#to_string;
	print_endline k#to_string;
	print_endline x#to_string;
	print_endline r#to_string;
	print_endline rf#to_string;
	print_endline db#to_string;
	print_endline (string_of_bool (r#equal h));
	let another = new Atom.radon in
	print_endline (string_of_bool (r#equal another));
	let water = new Molecule.water
	and carbon_dioxyde = new Molecule.carbon_dioxyde
	and trinitrotoluene = new Molecule.trinitrotoluene
	and cocaine = new Molecule.benzoylmethylecgonine
	and lsd = new Molecule.lysergic_acid_diethylamide
	in
	print_endline water#to_string;
	print_endline carbon_dioxyde#to_string;
	print_endline trinitrotoluene#to_string;
	print_endline cocaine#to_string;
	print_endline lsd#to_string;
	print_endline (string_of_bool (lsd#equal cocaine))
