(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   nucleotides.ml                                     :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 20:33:42 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/17 20:52:35 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None
type nucleotide = {
  p: phosphate;
  d: deoxyribose;
  n: nucleobase;
}

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

let () =
  let print_nucleotide n =
	(
	  print_endline n.p;
	  print_endline n.d;
	)
  in
  print_nucleotide (generate_nucleotide 'A')
