(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   cipher.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/18 19:52:06 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/18 22:22:33 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rot42 str =
  let fct char =
	if (char >= 'a' && char <= 'z') then
	  let a =
		((int_of_char char) - (int_of_char 'a') + 42) mod 26
	  in
	  char_of_int (a + (int_of_char 'a'))
	else
	  if (char >= 'A' && char <= 'Z') then
		let a =
		  ((int_of_char char) - (int_of_char 'A') + 42) mod 26
		in
		char_of_int (a + (int_of_char 'A'))
	  else
		char
  in
  String.map fct str
			 
let caesar str n =
  let true_n =
	if (n < 0) then
	  26 - ((-n) mod 26)
	else
	  n mod 26
  in
  let rot_alpha c =
	if (c >= 'a' && c <= 'z') then
	  char_of_int(((int_of_char c) + true_n - int_of_char 'a') mod 26 + int_of_char 'a')
	else if (c >= 'A' && c <= 'Z') then
	  char_of_int(((int_of_char c) + true_n - int_of_char 'A') mod 26 + int_of_char 'A')
	else
	  c
  in
  String.map rot_alpha str

let ft_crypt str lst =
  let rec inner str lst=
	match lst with
	| [] ->
	   str
	| current::next ->
	   inner (current str) next
  in
  inner str lst

let xor str key =
  let xor_alpha c = char_of_int ((int_of_char c) lxor key)
  in
  String.map xor_alpha str

