(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   uncipher.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/18 19:53:14 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/18 22:22:18 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let unrot42 str =
  let fct char =
	if (char >= 'a' && char <= 'z') then
	  let a =
		((int_of_char char) - (int_of_char 'a') + 10) mod 26
	  in
	  char_of_int (a + (int_of_char 'a'))
	else
	  if (char >= 'A' && char <= 'Z') then
		let a =
		  ((int_of_char char) - (int_of_char 'A') + 10) mod 26
		in
		char_of_int (a + (int_of_char 'A'))
	  else
		char
  in
  String.map fct str

let uncaesar str n =
  let true_n =
	if ((-n) < 0) then
	  26 - (n mod 26)
	else
	  (-n) mod 26
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

let unxor str key =
  let xor_alpha c = char_of_int ((int_of_char c) lxor key)
  in
  String.map xor_alpha str

let ft_uncrypt str lst =
  let rec inner str lst=
	match lst with
	| [] ->
	   str
	| current::next ->
	   inner (current str) next
  in
  inner str lst
		
let () =
  print_endline (Cipher.rot42 "abcde");
  print_endline (unrot42 (Cipher.rot42 "abcde"));
  print_endline (Cipher.caesar "abcde" 42);
  print_endline (uncaesar (Cipher.caesar "abcde" 42) 42);
  print_endline (Cipher.ft_crypt "abcde" [Cipher.rot42; Cipher.rot42]);
  print_endline (ft_uncrypt (Cipher.ft_crypt "abcde"
											 [Cipher.rot42; Cipher.rot42])
							[unrot42; unrot42]);
  print_endline (Cipher.ft_crypt "abcde" []);
  print_endline (Cipher.xor "abcde" 3);
  print_endline (unxor (Cipher.xor "abcde" 3) 3);
