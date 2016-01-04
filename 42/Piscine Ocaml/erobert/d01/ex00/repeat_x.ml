(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   repeat_x.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 15:22:38 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/16 15:29:36 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec repeat_x n =
  if (n < 0) then
	"Error"
  else if (n = 0) then
	""
  else
	"x" ^ repeat_x (n - 1)

let main () =
  print_endline (repeat_x 42);
  print_endline (repeat_x 0);
  print_endline (repeat_x 1);
  print_endline (repeat_x (-1))

let () = main ()
