(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_test_sign.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 13:32:14 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 13:34:35 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_test_sign n =
  if (n >= 0) then
	print_endline("positive")
  else
	print_endline("negative")
				 
let main () =
  ft_test_sign (1138);
  ft_test_sign (0);
  ft_test_sign (-0);
  ft_test_sign (-16)

let () = main ()
