(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   jokes.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 14:16:02 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/22 15:17:51 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	Random.self_init ();
	let jokes = [|"A man and a worm walking...";
							"Knock knock!";
							"Arf.";
							"No jokes here.";
							"You re nice."|]
	in
	print_endline jokes.(Random.int 5)
