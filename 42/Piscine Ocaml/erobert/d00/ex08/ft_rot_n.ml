(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_rot_n.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 14:45:06 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 15:19:18 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_rot_n n str =
  let rot = n
  in
  let fct char =
	if (char >= 'a' && char <= 'z') then
	  let a =
		((int_of_char char) - (int_of_char 'a') + rot) mod 26
	  in
	  char_of_int (a + (int_of_char 'a'))
	else
	  if (char >= 'A' && char <= 'Z') then
		let a =
		  ((int_of_char char) - (int_of_char 'A') + rot) mod 26
		in
		char_of_int (a + (int_of_char 'A'))
	  else
		char
  in
  String.map fct str

let main () =
  print_endline (ft_rot_n 1 "Hello");
  print_endline (ft_rot_n 13 "abcdefghijklmnopqrstuvwxyz");
  print_endline (ft_rot_n 52 "Max");
  print_endline (ft_rot_n 2 "");
  print_endline (ft_rot_n 2 "OI2EAS67B9")

let () = main ()
