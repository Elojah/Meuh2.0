(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_countdown.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 13:32:21 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 13:43:43 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let rec ft_countdown n =
  let print_digit n =
	print_int (n);
	print_char ('\n')
  in
  if (n > 0) then
	begin
	  print_digit (n);
	  ft_countdown (n -1)
	end
  else
	  print_digit (0)		

let main () =
  ft_countdown (1138);
  ft_countdown (0);
  ft_countdown (-55)

let () = main ()
