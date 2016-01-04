(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 12:22:42 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/26 13:15:59 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module App =
	struct
		type project = string * string * int
		let (zero:project) = ("", "", 0)
		let combine (p1:project) (p2:project): project =
			match (p1, p2) with
			| ((a, b, c), (d, e, f)) ->
				 if ((f + c) / 2 >= 80) then
					 (a ^ d, "succeed", (f + c) / 2)
				 else
					 (a ^ d, "failed", (f + c) / 2)
		let fail (p:project): project =
			match p with
			| (a, _, _) -> (a, "failed", 0)
		let success (p:project): project =
			match p with
			| (a, _, _) -> (a, "succeed", 80)
	end

let () =
	let print_proj (p:App.project) =
		match p with
		| (a, b, c) ->
			 print_endline ("Project: " ^ a ^ ", status: "
											^ b ^ ", grade: " ^ (string_of_int c) ^ ".")
	in
	print_proj (App.fail App.zero);
	print_proj (App.success App.zero);
	let p1:App.project = ("Manhatan", "failed", 79)
	and p2:App.project = ("MKUltra", "failed", 50)
	and p3:App.project = ("1138", "succeed", 100)
	in
	print_proj p1;
	print_proj p2;
	print_proj p3;
	print_proj (App.combine p1 p2);
	print_proj (App.combine (App.combine p1 p2) p3);
	print_endline "Ciao"
