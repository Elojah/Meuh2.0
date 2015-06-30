(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   iter.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 16:23:11 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/16 16:32:54 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec iter (f : int -> int) x n =
  if (n < 0) then
	-1
  else if (n = 0) then
	x
  else
	f (iter f x (n - 1))

let main () =
  print_int (iter (fun x -> x * x) 2 4);
  print_char '\n';
  print_int (iter (fun x -> x * 2) 2 4);
  print_char '\n';
  print_int (iter (fun x -> x * x * x) 2 2);
  print_char '\n';
  print_int (iter (fun x -> 0) 2 4);
  print_char '\n';
  print_int (iter (fun x -> x * x) (-1) 4);
  print_char '\n';
  print_int (iter (fun x -> x * x) 2 (-4));
  print_char '\n'

let () = main ()
