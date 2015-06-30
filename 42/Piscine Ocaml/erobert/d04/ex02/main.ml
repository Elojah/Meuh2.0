(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 12:01:39 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/19 15:03:05 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
(*  let rec print_all lst =
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
 *)
  print_endline (Card.toString (Card.best Card.all));
  print_endline (Card.toStringVerbose (Card.best Card.allClubs));
  if (Card.isOf (Card.best Card.all) Card.Color.Spade) then
	print_endline "Nice"
  else
	print_endline "...";
  if (Card.isClub (Card.best Card.all)) then
	print_endline "Nice"
  else
	print_endline "...";
  print_endline (Card.toStringVerbose
				   (Card.min (Card.newCard Card.Value.T2 Card.Color.Spade)
							 (Card.newCard Card.Value.As Card.Color.Spade)));
    print_endline (Card.toString (Card.best []))
