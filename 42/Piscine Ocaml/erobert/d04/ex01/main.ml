(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 12:01:39 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/19 14:20:40 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let rec print_all lst =
	match lst with
	| [] ->
	   ()
	| head::tail ->
	   (
		 print_int (Value.toInt head);
		 print_char ':';
		 print_string (Value.toString head);
		 print_char '_';
		 print_endline (Value.toStringVerbose head);
		 print_all tail
	   )
  in
  print_all Value.all;
  print_endline (Value.toStringVerbose (Value.next Value.King));
  print_endline (Value.toStringVerbose (Value.previous Value.King));
  print_endline (Value.toStringVerbose (Value.next Value.As));
  print_endline (Value.toStringVerbose (Value.previous Value.T2))
