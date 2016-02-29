(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   jokes.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 14:23:03 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/22 16:31:27 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	if Array.length (Sys.argv) <> 2 then
		print_endline (Sys.argv.(0) ^ " file name")
	else
		try
			let ic = open_in Sys.argv.(1) in
			let n = ref 0 in
			try
				(
					while true do
						ignore (input_line ic);
						incr n
					done
				)
			with End_of_file ->
				(
					close_in ic;
					let ic = open_in Sys.argv.(1) in
					let jokes = Array.make !n "" in
					for i = 0 to (!n - 1) do
						jokes.(i) <- input_line ic
					done;
					close_in ic;
					Random.self_init ();
					print_endline jokes.(Random.int !n)
				)
		with _ ->
			print_endline (Sys.argv.(0) ^ " file name")
