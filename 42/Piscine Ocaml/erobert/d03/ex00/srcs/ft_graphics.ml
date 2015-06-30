(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_graphics.ml                                     :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/18 13:56:00 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/18 19:32:12 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let draw_square x y size =
  let x0 = x - size / 2
  and y0 = y - size / 2
  and x1 = x + size / 2
  and y1 = y + size / 2
  in
  Graphics.moveto x0 y0;
  Graphics.lineto x0 y1;
  Graphics.lineto x1 y1;
  Graphics.lineto x1 y0;
  Graphics.lineto x0 y0

let draw_tree_node node =
  let rec inner node x y n size stop =
	match node with
	| Nil ->
	   (
		 draw_square x y size;
		 Graphics.moveto (x - size / 3) (y - size / 3);
		 Graphics.draw_string "Nil"
	   )
	| Node(a, b, c) ->
	   (
		 draw_square x y size;
		 Graphics.moveto (x - size / 3) (y - size / 3);
		 Graphics.draw_string "value";
		 if (stop = false) then
		   (
			 Graphics.moveto (x + size / 2) y;
			 Graphics.lineto (x + 128 - size / 2) (y + n);
			 inner b (x + 128) (y + n) (n / 2) size true;
			 Graphics.moveto (x + size / 2) y;
			 Graphics.lineto (x + 128 - size / 2) (y - n);
			 inner c (x + 128) (y - n) (n / 2) size true
		   )
	   )
  in
  inner node 64 384 128 42 false
	   
let () =
  Graphics.open_graph " 1024x768";
  Graphics.set_color Graphics.black;
  draw_tree_node (Node("ALPHA",
					   Node("BETA",
							Nil,
							Node("DELTA", Nil, Nil)),
					   Nil));
  draw_tree_node Nil;
  Graphics.read_key ();
  print_endline "Ciao"
