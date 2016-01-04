(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 13:54:32 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/24 15:11:02 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	let p = new People.people "Max" in
	let d = new Doctor.doctor "House" 69 p in
	print_endline p#to_string;
	p#talk;
	p#die;
	print_endline d#to_string;
	d#talk;
	d#use_sonic_screwdriver;
	print_endline ((d#travel_in_time 2015 3015)#to_string);
