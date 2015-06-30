(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 13:54:32 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/24 16:12:12 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
	Random.self_init ();
	let p = new People.people "Max" in
	let d = new Doctor.doctor "House" 69 p in
	print_endline p#to_string;
	p#talk;
	p#die;
	print_endline d#to_string;
	d#talk;
	d#use_sonic_screwdriver;
	print_endline ((d#travel_in_time 2015 3015)#to_string);
	let r0 = new Dalek.dalek in
	print_endline r0#to_string;
	let r1 = new Dalek.dalek in
	print_endline r1#to_string;
	r0#talk;
	r0#exterminate p;
	print_endline r0#to_string;
	r0#talk;
	r0#talk;
	d#use_sonic_screwdriver;
	print_endline (r0#set_hp 0)#to_string;
	r0#die;
	let a0 = new Army.army [r0; r1] in
	a0#what_is_your_work;
	print_endline "----------";
	(a0#delete#delete#add r1)#what_is_your_work;
	let a1 = new Army.army [p] in
	ignore (a1#delete#delete#add p);
	let a2 = new Army.army [d] in
	ignore (a2#delete#delete#add d);
