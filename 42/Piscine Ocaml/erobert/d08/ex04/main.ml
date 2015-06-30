(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 13:43:53 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/26 13:54:47 by erobert          ###   ########.fr       *)
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
	let a32 = new Alkane.alkane 32
	and methane = new Alkane.methane;
	and ethane = new Alkane.ethane;
	and octane = new Alkane.octane;
	in
	print_endline a32#to_string;
	print_endline methane#to_string;
	print_endline ethane#to_string;
	print_endline octane#to_string;
	print_endline (string_of_bool (methane#equal lsd));
	print_endline (string_of_bool (cocaine#equal (ethane:> Molecule.molecule)));
	let c0:Reaction.reaction =
		new Reaction.alkane_combustion [methane]
	and c1:Reaction.reaction =
		new Reaction.alkane_combustion [new Alkane.alkane 8]
	and c2:Reaction.reaction =
		new Reaction.alkane_combustion [new Alkane.alkane 8; methane]
	in
	print_endline (string_of_bool c0#is_balanced);
	print_endline (string_of_bool c1#is_balanced);
	print_endline (string_of_bool (c1#balance)#is_balanced);
	print_endline (string_of_bool c2#is_balanced);
	print_endline (string_of_bool (c2#balance)#is_balanced);
	let rec print_reaction lst =
		match lst with
		| [] ->
			 ()
		| (data, count)::tail ->
			 print_int count;
			 print_char '*';
			 print_string data#formula;
			 print_char '\n';
			 print_reaction tail
	in
	print_reaction c0#get_start;
	print_endline "==";
	print_reaction c0#get_result;
	print_endline "----------------";
	try
		print_reaction c2#get_start
	with Invalid_argument e ->
		print_endline e;		print_endline "----------------";
		print_reaction c2#balance#get_start;		
		print_endline "==";
		try
			print_reaction c2#get_result
		with Invalid_argument e ->
			print_endline e;
			print_reaction c2#balance#get_result;
