(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_power.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 13:32:31 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 13:46:19 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_power n p =
  if (p = 0) then
	1
  else
	n * ft_power n (p - 1)

let main () =
  print_int (ft_power 2 2);
  print_char ('\n');
  print_int (ft_power 10 9);
  print_char ('\n');
  print_int (ft_power 0 99);
  print_char ('\n');
  print_int (ft_power 99 0);
  print_char ('\n')

let () = main ()
