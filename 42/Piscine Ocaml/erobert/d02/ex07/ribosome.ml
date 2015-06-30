(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ribosome.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 22:07:50 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/17 22:32:37 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | U | None
type nucleotide = {
  p: phosphate;
  d: deoxyribose;
  n: nucleobase;
}
type helix = nucleotide list
type rna = nucleobase list

let generate_nucleotide c =
  {
	p = "phosphate";
	d = "deoxyribose";
	n = match c with
	| 'A' ->
	   A
	| 'T' ->
	   T
	| 'C' ->
	   C
	| 'G' ->
	   G
	| _ ->
	   None
  }

let generate_helix n =
  Random.self_init ();
  let atcg = "ATCG"
  in
  let rec inner n result:helix =
	if (n < 1) then
	  result
	else
	  inner (n - 1) (result @ [generate_nucleotide atcg.[Random.int 4]])
  in
  inner n []

let helix_to_string (h:helix) =
  let nucleobase_to_string base =
	match base with
	| A -> "A"
	| T -> "T"
	| C -> "C"
	| G -> "G"
	| U -> "U"
	| _ -> "None"
  in
  let nucleotide_to_string n =
    n.p ^ " - " ^ n.d ^ " - " ^ (nucleobase_to_string n.n)
  in
  let rec loop_h h result =
	match h with
	| [] ->
	   result
	| current::next ->
	   if (next <> []) then
		 loop_h next (result ^ (nucleotide_to_string current) ^ "\n")
	   else
		 loop_h next (result ^ (nucleotide_to_string current))
  in
  loop_h h ""

let complementary_helix (h:helix) =
  let rec inner h result:helix =
	match h with
	| [] ->
	   result
	| current::next ->
	   match current.n with
	   | A ->
		  inner next (result @ [(generate_nucleotide 'T')])
	   | T ->
		  inner next (result @ [(generate_nucleotide 'A')])
	   | C ->
		  inner next (result @ [(generate_nucleotide 'G')])
	   | G ->
		  inner next (result @ [(generate_nucleotide 'C')])
	   | _ ->
		  inner next (result @ [(generate_nucleotide 'N')])
  in
  inner h []

let generate_rna (h:helix) =
  let rec inner h result:rna =
	match h with
	| [] ->
	   result
	| current::next ->
	   match current.n with
	   | A ->
		  inner next (result @ [U])
	   | T ->
		  inner next (result @ [A])
	   | C ->
		  inner next (result @ [G])
	   | G ->
		  inner next (result @ [C])
	   | _ ->
		  inner next (result @ [None])
  in
  inner h []

let generate_bases_triplets (rna:rna) =
  let rec inner rna first second
				(result:(nucleobase * nucleobase * nucleobase) list) =
	match rna with
	| [] ->
	   result
	| current::next ->
	   if (first <> T && second <> T) then
		 inner next T T (result @ [(first, second, current)])
	   else if (first <> T) then
		 inner next first current result
	   else if (first = T) then
		 inner next current T result
	   else
		 result
  in
  inner rna T T []
		
let () =
  let h = (generate_helix 10)
  in
  let nucleobase_to_string base =
	match base with
	| A -> "A"
	| T -> "T"
	| C -> "C"
	| G -> "G"
	| U -> "U"
	| _ -> "None"
  in
  let print_nra n =
	let rec inner n =
	  match n with
	  | [] ->
		 ()
	  | current::next ->
		 (
		   print_endline (nucleobase_to_string current);
		   inner next
		 )
	in
	inner n
  in
  let print_triplets n =
	let get_1 (a,_,_) = a in
	let get_2 (_,a,_) = a in
	let get_3 (_,_,a) = a in
	let rec inner n =
	  match n with
	  | [] ->
		 ()
	  | current::next ->
		 (
		   print_string (nucleobase_to_string (get_1 current));
		   print_string (nucleobase_to_string (get_2 current));
		   print_endline (nucleobase_to_string (get_3 current));
		   inner next
		 )
	in
	inner n
  in
  print_endline (helix_to_string h);
  print_endline "->";
  print_endline (helix_to_string (complementary_helix h));
  print_endline "->";
  print_nra (generate_rna h);
  print_endline "->";
  print_triplets (generate_bases_triplets (generate_rna h));
  print_endline "->";
  print_triplets (generate_bases_triplets (generate_rna (generate_helix 3)))
