(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   repeat_string.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 15:22:03 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/16 15:56:16 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec repeat_string ?str:(str = "x") n =
  if (n < 0) then
	"Error"
  else if (n = 0) then
	""
  else
	str ^ repeat_string ~str:str (n - 1)

let main () =
  print_endline (repeat_string 1);
  print_endline (repeat_string ~str:"X" 0);
  print_endline (repeat_string ~str:"Y" (-100));
  print_endline (repeat_string ~str:"Max" 3)

let () = main ()
