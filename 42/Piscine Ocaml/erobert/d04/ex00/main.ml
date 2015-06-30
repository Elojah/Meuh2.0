(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/19 12:01:39 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/19 12:06:21 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  let rec print_all lst =
	match lst with
	| [] ->
	   ()
	| head::tail ->
	   (
		 print_endline (Color.toString head);
		 print_endline (Color.toStringVerbose head);
		 print_all tail
	   )
  in
  print_all Color.all
