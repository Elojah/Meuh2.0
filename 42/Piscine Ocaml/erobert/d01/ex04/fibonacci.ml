(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   fibonacci.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 15:51:04 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/16 16:14:38 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let fibonacci n =
  let rec inner_fibo n a b =
	if (n = 0) then
	  a
	else
	  inner_fibo (n - 1) (a + b) a
  in
  if (n < 0) then
	-1
  else
	inner_fibo n 0 1

let main () =
  print_int (fibonacci (-42));
  print_char '\n';
  print_int (fibonacci (1));
  print_char '\n';
  print_int (fibonacci (3));
  print_char '\n';
  print_int (fibonacci (6));
  print_char '\n';
  print_int (fibonacci (0));
  print_char '\n';
  print_int (fibonacci (46));
  print_char '\n'

let () = main ()
